#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

int t, n, m, a[100005], b[100005], ps[100005];

bool comp(pair <int, int> i, pair <int, int> j)
{
    return i > j;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        vector <pair <int, int> > v;

        for(int i = 0; i < m; i++)
        {
            cin >> a[i] >> b[i];

            v.push_back({a[i], b[i]});
        }

        sort(v.begin(), v.end(), comp);

        for(int i = 0; i < m; i++)
            ps[i + 1] = ps[i] + v[i].first;

        int ans = 0;

        for(int i = 0; i < m; i++)
        {
            int k = 1;
            int s = v[i].first;

            int L = -1;
            int R = m;

            while(R - L > 1)
            {
                int M = (L + R) / 2;

                if(v[M].first > v[i].second)
                    L = M;
                else R = M;
            }

            if(v[i].first > v[i].second)
            {
                k = 0;
                s = 0;
            }

            if(n - k < R)
            {
                s += ps[n - k];
                k = n;
            }
            else
            {
                k += R;
                s += ps[R];
            }

            s += v[i].second * (n - k);
            ans = max(ans, s);
        }

        cout << ans << "\n";
    }
}