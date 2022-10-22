#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, m, x, y, d;
        cin >> n >> m >> x >> y >> d;

        if(x - d <= 1 && y - d <= 1 || x + d >= n && y + d >= m || x + d >= n && x - d <= 1 || y + d >= m && y - d <= 1)
            cout << "-1\n";
        else cout << n + m - 2 << "\n";
    }
}