#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, u, v, a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> u >> v;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int d = 0;

        for(int i = 1; i < n; i++)
            d = max(d, abs(a[i] - a[i - 1]));

        if(d == 0)
            cout << v + min(u, v);
        else if(d == 1)
            cout << min(u, v);
        else cout << 0;

        cout << "\n";
    }
}