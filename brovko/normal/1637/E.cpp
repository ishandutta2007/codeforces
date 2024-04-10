#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, m, a[300005], r[300005], y;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        y = 0;

        cin >> n >> m;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector <int> V;

        for(int i = 0; i < n; i++)
            V.pb(a[i]);

        sort(V.begin(), V.end());

        map <int, int> M;

        for(auto x:V)
            if(M[x] == 0)
            {
                M[x] = ++y;
                r[y] = x;
            }

        for(int i = 0; i < n; i++)
            a[i] = M[a[i]];

//        for(int i = 0; i < n; i++)
//            cout << a[i] << ' ';
//
//        cout << endl;
//
//        for(int i = 0; i < n; i++)
//            cout << r[a[i]] << ' ';
//
//        cout << endl;

        int cnt[y + 1] = {0}, pos[y + 1] = {0};

        vector <int> v[n + 1];

        for(int i = 0; i < n; i++)
            cnt[a[i]]++;

        for(int i = 0; i <= y; i++)
            if(cnt[i] > 0)
            {
                v[cnt[i]].pb(i);
                pos[i] = (int)v[cnt[i]].size() - 1;
            }

        map <pair <int, int>, bool> bad;

        int ans = 0;

        for(int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;

            x = M[x];
            y = M[y];

            bad[{x, y}] = 1;
            bad[{y, x}] = 1;
        }

        for(int i = 0; i < n; i++)
        {
            bad[{a[i], a[i]}] = 1;
        }

        vector <int> c;

        for(int i = 0; i <= n; i++)
            if(v[i].size())
                c.pb(i);

        for(int i = 0; i < c.size(); i++)
            for(int j = 0; j < i; j++)
            {
                if(!bad[{v[c[i]].back(), v[c[j]].back()}])
                    ans = max(ans, (c[i] + c[j]) * (r[v[c[i]].back()] + r[v[c[j]].back()]));
            }

        for(int i = 0; i < c.size(); i++)
            if(v[c[i]].size() >= 2)
            {
                int x = v[c[i]].back(), y = v[c[i]][(int)v[c[i]].size() - 2];

                if(!bad[{x, y}])
                    ans = max(ans, (cnt[x] + cnt[y]) * (r[x] + r[y]));
            }

        for(auto p:bad)
            if(p.x.x <= p.x.y && ans < (cnt[p.x.x] + cnt[p.x.y]) * (r[p.x.x] + r[p.x.y]))
            {
                int x = p.x.x;
                int y = p.x.y;

                if(pos[x] > 0)
                {
                    int x2 = v[cnt[x]][pos[x] - 1];

                    if(!bad[{x2, y}])
                        ans = max(ans, (cnt[x2] + cnt[y]) * (r[x2] + r[y]));
                }

                if(pos[y] > 0)
                {
                    int y2 = v[cnt[y]][pos[y] - 1];

                    if(!bad[{x, y2}])
                        ans = max(ans, (cnt[x] + cnt[y2]) * (r[x] + r[y2]));
                }
            }

        cout << ans << "\n";
//        cout << endl;
    }
}