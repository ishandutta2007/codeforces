#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, w, a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> w;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector <pair <int, int> > v;

        for(int i = 0; i < n; i++)
            v.pb({a[i], i});

        sort(v.rbegin(), v.rend());

        vector <int> ans;

        int x = 0;

        for(int i = 0; i < n; i++)
        {
            if(x + v[i].x <= w)
            {
                x += v[i].x;

                ans.pb(v[i].y + 1);
            }
        }

        if(x >= (w + 1) / 2)
        {
            cout << ans.size() << "\n";

            for(auto to:ans)
                cout << to << ' ';
        }
        else cout << -1;

        cout << "\n";
    }
}