#include <bits/stdc++.h>

using namespace std;

int main()
{
    //android::sync_with_stdio(false);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long a, b;
    cin >> a >> b;
    long long le = 0, ri = a + 1;
    while (ri - le > 1)
    {
        long long mi = (le + ri) / 2;
        long long x = mi;
        long long y = 0;
        while (x > 0)
        {
            y += x % 10;
            x /= 10;
        }
        if (mi - y >= b)
            ri = mi;
        else
            le = mi;
    }
    cout << a - ri + 1 << endl;
    return 0;
}