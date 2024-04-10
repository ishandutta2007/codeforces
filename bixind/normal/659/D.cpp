#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, i, m = 0;
    int x, y, x0, y0, x1, y1;
    cin >> n;
    cin >> x0 >> y0;
    cin >> x1 >> y1;
    for (i = 2; i < n + 1; i++)
    {
        cin >> x >> y;
        if ((x - x1) * (y1 - y0) - (y - y1) * (x1 - x0) < 0)
            m++;
        x0 = x1;
        y0 = y1;
        x1 = x;
        y1 = y;
    }
    cout << m;
    return 0;
}