#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[1005], g, Min;

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

    Min = 1e9;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        g = gcd(g, a[i]);
        Min = min(Min, a[i]);
    }

    if(Min != g)
    {
        cout << -1;
        return 0;
    }

    cout << n * 2 << "\n";
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << ' '  << g << ' ';
    }
}