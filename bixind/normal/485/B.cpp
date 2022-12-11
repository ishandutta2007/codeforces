#include <iostream>

using namespace std;

int main()
{
    long long  n, i, x, y, xmax, xmin, ymax, ymin;
    cin >> n;
    cin >> xmax >> ymax;
    xmin = xmax;
    ymin = ymax;
    for (i = 1; i < n; i++)
    {
        cin >> x >> y;
        if (x > xmax) xmax = x;
        if (y > ymax) ymax = y;
        if (x < xmin) xmin = x;
        if (y < ymin) ymin = y;
    }
    x = max ((xmax - xmin), (ymax - ymin));
    cout << x * x;
    return 0;
}