#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, x, y;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> x >> y;

        if(x > y)
            cout << x + y << "\n";
        else if(x == y)
            cout << x << "\n";
        else cout << y - (y % x / 2) << "\n";
    }
}