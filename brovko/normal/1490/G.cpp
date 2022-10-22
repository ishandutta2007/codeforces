#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], x[m], k[m], p[m], d[m];

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < m; i++)
            cin >> x[i];

        int s = 0, Max = -1e9;

        for(int i = 0; i < n; i++)
        {
            s += a[i];
            Max = max(Max, s);
        }

        vector <pair <int, int> > v;

        for(int i = 0; i < m; i++)
        {
            if(s <= 0)
                k[i] = 0;
            else k[i] = max(0ll, (x[i] - Max + s - 1) / s);
            p[i] = x[i] - k[i] * s;

            v.pb({p[i], i});
        }

        sort(v.begin(), v.end());

        int z = 0, q = 0;

        for(int i = 0; i < n; i++)
        {
            q += a[i];

            while(z < m && q >= v[z].x)
            {
                d[v[z].y] = i;
                z++;
            }
        }

        for(int i = 0; i < m; i++)
            if(s > 0 || Max >= x[i])
                cout << n * k[i] + d[i] << ' ';
            else cout << "-1 ";

        cout << "\n";
    }
}