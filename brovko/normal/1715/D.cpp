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
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector <int> l(q), r(q), x(q);

    for(int i = 0; i < q; i++)
    {
        cin >> l[i] >> r[i] >> x[i];
        l[i]--;
        r[i]--;
    }

    vector <int> ans(n);

    for(int j = 0; j < 30; j++)
    {
        vector <int> a(n, 1);

        for(int i = 0; i < q; i++)
            if((x[i] & (1 << j)) == 0)
                a[l[i]] = a[r[i]] = 0;

        vector <int> cnt(q);
        bool f = 1;

        vector <int> mn(n, 1e9);

        vector <int> Q[n];

        for(int i = 0; i < q; i++)
            if(x[i] & (1 << j))
            {
                cnt[i] += a[l[i]] + a[r[i]];

                if(cnt[i] == 0)
                    f = 0;

                mn[l[i]] = min(mn[l[i]], cnt[i]);
                mn[r[i]] = min(mn[r[i]], cnt[i]);

                Q[l[i]].push_back(r[i]);
                Q[r[i]].push_back(l[i]);

                if(l[i] == r[i])
                    a[l[i]] = 2;
            }

        for(int i = 0; i < n; i++)
            if(a[i] == 1 && mn[i] > 1)
            {
                a[i] = 0;

                mn[i]--;

                for(auto x:Q[i])
                    mn[x]--;
            }

        for(int i = 0; i < n; i++)
            if(a[i] == 2)
                a[i] = 1;

        for(int i = 0; i < n; i++)
            ans[i] += (a[i] << j);
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}