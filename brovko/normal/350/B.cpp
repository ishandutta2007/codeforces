#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> t(n);

    for(int i = 0; i < n; i++)
        cin >> t[i];

    vector <int> a(n);
    vector <int> g[n];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;

        if(a[i] != -1)
        {
            g[a[i]].pb(i);
        }
    }

    int ans = 0;
    vector <int> vans;

    for(int i = 0; i < n; i++)
        if(t[i])
        {
            int x = 0, v = i;
            vector <int> u;

            while(v != -1 && g[v].size() <= 1)
            {
                u.pb(v);
                v = a[v];
                x++;
            }

            if(x > ans)
            {
                ans = x;
                vans = u;
            }
        }

    cout << ans << "\n";
    reverse(vans.begin(), vans.end());

    for(auto x:vans)
        cout << x + 1 << ' ';
}