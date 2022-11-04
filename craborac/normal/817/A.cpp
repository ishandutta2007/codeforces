#include <bits/stdc++.h>

using namespace std;

int main()
{
    //android::sync_with_stdio(false);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long a, b, c, d, x, y;
    cin >> a >> b >> c >> d >> x >> y;
    a = abs(a - c);
    b = abs(b - d);
    if (a % x == 0 && b % y == 0 && (a % (2 * x)) / x == (b % (2 * y)) / y)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}