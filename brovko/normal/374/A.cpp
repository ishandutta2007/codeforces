#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, i, j, a, b;
    cin >> n >> m >> i >> j >> a >> b;

    int ans = 1e9;

    if((i - 1) % a == 0 && (j - 1) % b == 0)
    {
        int x = (i - 1) / a;
        int y = (j - 1) / b;

        if(x % 2 == y % 2)
            ans = min(ans, max(x, y));
    }

    if((i - 1) % a == 0 && (m - j) % b == 0)
    {
        int x = (i - 1) / a;
        int y = (m - j) / b;

        if(x % 2 == y % 2)
            ans = min(ans, max(x, y));
    }

    if((n - i) % a == 0 && (m - j) % b == 0)
    {
        int x = (n - i) / a;
        int y = (m - j) / b;

        if(x % 2 == y % 2)
            ans = min(ans, max(x, y));
    }

    if((n - i) % a == 0 && (j - 1) % b == 0)
    {
        int x = (n - i) / a;
        int y = (j - 1) / b;

        if(x % 2 == y % 2)
            ans = min(ans, max(x, y));
    }

    if(ans > 1e8 || ans != 0 && (i + a > n && i - a < 1 || j + b > m && j - b < 1))
        cout << "Poor Inna and pony!";
    else cout << ans;
}