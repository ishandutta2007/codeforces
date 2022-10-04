/**********
*         *
*  HELLO  *
*         *
**********/

#include <bits/stdc++.h>
#define ll long long
#define mp make_pair

using namespace std;

int s, x1, x2, t1, t2, p, d, w1, w2;

int main()
{
    cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
    w1 = abs(x1 - x2) * t2;
    if (t1 >= t2) {
        cout << w1;
        return 0;
    }
    if (x1 > x2) {
        p = s - p;
        x1 = s - x1;
        x2 = s - x2;
        d = -d;
    }
    if (x1 < x2) {
        if (d == -1) {
            w2 = (p + x2) * t1;
        }
        if ((p <= x2) && (p > x1) && (d == 1)) {
            w2 = (s - p + s + x2) * t1;
        }
        if ((p <= x2) && (p <= x1) && (d == 1)) {
            w2 = (x2 - p) * t1;
        }
        if ((p > x2) && (d == 1)) {
            w2 = (s - p + s + x2) * t1;
        }
    }
    cout << min(w1, w2);
    return 0;
}