#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int R, x1, x2, y1, y2;
    cin >> R >> x1 >> y1 >> x2 >> y2;
    if ((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1) >= R*R){
        cout << x1 << " " << y1 << " " << R << endl;
        return 0;
    }
    if (x1==x2 && y1==y2){
        cout << x1+(double)R/2 << " " << y1 << " " << (double)R/2 << endl;
        return 0;
    }
    x2 -= x1, y2 -= y1;
    double a = -y2;
    double b = x2;
    double c = 0;
    double x0 = -a*c/(a*a+b*b),  y0 = -b*c/(a*a+b*b);
    double d = (double) R*R - c*c/(a*a+b*b);
    double mult = sqrt (d / (a*a+b*b));
    double ax,ay,bx,by;
    ax = x0 + b * mult;
    bx = x0 - b * mult;
    ay = y0 - a * mult;
    by = y0 + a * mult;
    double d1 = (ax-x2) * (ax-x2) + (ay-y2) * (ay-y2);
    double d2 = (bx-x2) * (bx-x2) + (by-y2) * (by-y2);
    ax += x1;
    x2 += x1;
    bx += x1;
    ay += y1;
    y2 += y1;
    by += y1;
    cout.precision(20);
    if (d1 > d2){
        cout << (ax+x2) / 2 << " " << (ay+y2) / 2 << " " << sqrt(d1) / 2 << endl;
        return 0;
    }
    cout << (bx+x2) / 2 << " " << (by+y2) / 2 << " " << sqrt(d2) / 2 << endl;
    return 0;
}