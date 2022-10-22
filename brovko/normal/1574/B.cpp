#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, a, b, c, m;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> a >> b >> c >> m;

        if(m <= a + b + c - 3 && m >= 2 * max({a, b, c}) - a - b - c - 1)
            cout << "YES\n";
        else cout << "NO\n";
    }
}