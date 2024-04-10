#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int xp, yp, xv, yv;
    cin >> xp >> yp >> xv >> yv;
    if (xp <= xv && yp <= yv) {
        cout << "Polycarp\n";
        return 0;
    }
    if (xv <= xp && yv <= yp) {
        cout << "Vasiliy\n";
        return 0;
    }
    if (xv < xp) {
        if (xv >= yv - yp) {
            cout << "Vasiliy\n";
            return 0;
        } else {
            if (xp <= yv - yp) {
                cout << "Polycarp\n";
                return 0;
            } else {
                cout << "Vasiliy\n";
                return 0;
            }
        }
    } else {
        if (yv >= xv - xp) {
            cout << "Vasiliy\n";
            return 0;
        } else {
            if (yp <= xv - xp) {
                cout << "Polycarp\n";
                return 0;
            } else {
                cout << "Vasiliy\n";
                return 0;
            }
        }
    }

    return 0;
}