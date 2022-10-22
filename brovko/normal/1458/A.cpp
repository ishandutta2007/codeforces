#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, a[200005], b[200005];

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

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++)
        cin >> b[i];

    int g = 0;

    for(int i = 1; i < n; i++)
        g = gcd(g, abs(a[i] - a[i - 1]));

    for(int i = 0; i < m; i++)
        cout << gcd(g, a[0] + b[i]) << ' ';
}