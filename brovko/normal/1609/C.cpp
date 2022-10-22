#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define li long long

using namespace std;

int t, n, e, a[200005], np[1000005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 2; i < 1000005; i++)
        if(np[i] == 0)
            for(int j = i * i; j < 1000005; j += i)
                np[j] = 1;

    cin >> t;

    while(t--)
    {
        int ans = 0;
        cin >> n >> e;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int rg = 0; rg < e; rg++)
        {
            vector <int> v;

            for(int i = rg; i < n; i += e)
                v.pb(a[i]);

            int m = v.size();
            int r[m + 1];
            r[m] = m;

            for(int i = m - 1; i >= 0; i--)
            {
                if(v[i] == 1)
                    r[i] = r[i + 1];
                else r[i] = i;

                int L = r[i];

                if(L < m)
                {
                    int R = m;

                    if(L + 1 < m)
                        R = r[L + 1];

                    if(np[v[L]] == 0)
                    {
                        ans += R - max(L, i + 1);
                    }

                }

//                cout << ans << endl;
            }
        }

        cout << ans << "\n";
    }
}