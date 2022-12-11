#include <iostream>
#include <vector>
#include <cmath>

const double pi = 3.1415926535897932384626433832795;

bool test(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3)
{
    long long vx1 = x2 - x1;
    long long vy1 = y2 - y1;
    long long vx2 = x3 - x1;
    long long vy2 = y3 - y1;
    return ((vx1 * vx2 + vy1 * vy2) > 0);
}

long long vc(long long x1, long long y1, long long x2, long long y2)
{
    return (x1 * y2 - x2 * y1);
}

using namespace std;

int main()
{
    int n, i;
    long long x0, y0, x, y, xp, yp, xf, yf;
    double rmx = 0, rmn = 1000000000;
    cin >> n >> x0 >> y0;
    cin >> xf >> yf;
    xp = xf;
    yp = yf;
    for (i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        rmx = max(rmx, hypot(x - x0, y - y0));
        rmn = min(rmn, hypot(x - x0, y - y0));
        if (test(xp, yp, x, y, x0, y0) && test(x, y, xp, yp, x0, y0))
            rmn = min(rmn, abs(vc(x - x0, y - y0, xp - x0, yp - y0)) / (hypot(x - xp, y - yp)));
        xp = x;
        yp = y;
    }
    x = xf;
    y = yf;
    rmx = max(rmx, hypot(x - x0, y - y0));
    rmn = min(rmn, hypot(x - x0, y - y0));
    if (test(xp, yp, x, y, x0, y0) && test(x, y, xp, yp, x0, y0))
        rmn = min(rmn, abs(vc(x - x0, y - y0, xp - x0, yp - y0)) / (hypot(x - xp, y - yp)));
    cout.precision(30);
//    cout << rmx << ' ' << rmn << endl;
    cout << pi * (rmx*rmx - rmn*rmn);
    return 0;
}