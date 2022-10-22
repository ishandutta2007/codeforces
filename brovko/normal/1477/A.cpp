#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, k, a[200005];

int gcd(int x, int y)
{
    if(x == 0)
        return y;

    return gcd(y % x, x);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int g = 0;

        for(int i = 1; i < n; i++)
            g = gcd(g, abs(a[i] - a[i - 1]));

        if(k == a[0] || (g != 0 && abs(k - a[0]) % g == 0))
            cout << "YES\n";
        else cout << "NO\n";
    }
}