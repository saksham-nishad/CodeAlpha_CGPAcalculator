#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Course {
    float grade;       
    int creditHours;
    float gradePoints; 
};

int main() {
    int numCourses;
    int totalGradePoints = 0.0;
    int totalCredits = 0;

    cout << "Enter the number of courses taken this semester: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);
    for (int i = 0; i < numCourses; ++i) {
        cout << "\nCourse " << (i + 1) << ":\n";
        cout << "Enter grade point (ex:- 4 for A, 3 for B ";
        cin >> courses[i].grade;
        cout << "Enter credit hours: ";
        cin >> courses[i].creditHours;

        courses[i].gradePoints = courses[i].grade * courses[i].creditHours;
        totalGradePoints += courses[i].gradePoints;
        totalCredits += courses[i].creditHours;
    }

    // for calulation of GPA
    float semesterGPA = totalGradePoints / totalCredits;

    // for result
    cout << fixed << setprecision(2);
    cout << "\n-------------------- GPA REPORT --------------------\n";
    for (int i = 0; i < numCourses; ++i) {
        cout << "Course " << (i + 1)
             << " | Grade Point: " << courses[i].grade
             << " | Credit Hours: " << courses[i].creditHours
             << " | Grade Points: " << courses[i].gradePoints << endl;
    }

    cout << "----------------------------------------------------\n";
    cout << "Total Credit Hours: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Semester GPA: " << semesterGPA << endl;

    // for calculation of CGPA
    char hasPrev;
    cout << "\nDo you want to calculate CGPA with previous semesters? (y/n): ";
    cin >> hasPrev;

    if (tolower(hasPrev) == 'y') {
        float prevCGPA;
        int prevTotalCredits;

        cout << "Enter previous CGPA: ";
        cin >> prevCGPA;
        cout << "Enter total credit hours earned before this semester: ";
        cin >> prevTotalCredits;

        float overallCGPA = ((prevCGPA * prevTotalCredits) + totalGradePoints) / (prevTotalCredits + totalCredits);
        cout << "Cumulative CGPA (Overall): " << overallCGPA << endl;
    } else {
        cout << "Cumulative CGPA: " << semesterGPA << " (Only current semester considered)" << endl;
    }

    return 0;
}