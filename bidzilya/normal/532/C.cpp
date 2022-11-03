#include <bits/stdc++.h>
using namespace std;

const string kSecond = "Vasiliy";
const string kFirst = "Polycarp";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int xp, yp, xv, yv;
    cin >> xp >> yp >> xv >> yv;
    
    if (xv + yv < xp + yp) {
        cout << kSecond << endl;
        return 0;
    } else if (xv + yv == xp + yp) {
        if (xp + yp == 1 || xv == 0 || yv == 0) {
            cout << kFirst << endl;
            return 0;
        } else {
            cout << kSecond << endl;
            return 0;
        }
    } else if (xv + yv > xp + yp) {
        int step = 0;
        while (xv > 0 && yv > 0) {
            ++step;
            --xv;
            --yv;
            if (xv <= xp && yv <= yp && abs(xp - xv) + abs(yp - yv) <= step) {
                cout << kFirst << endl;
                return 0;
            }
        }
        int dist1 = xp + yp - step;
        int dist2 = xv + yv;
        if (dist1 <= dist2) {
            cout << kFirst << endl;
            return 0;
        } else {
            cout << kSecond << endl;
            return 0;
        }
    }
    
    return 0;
}