#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

int t, n, m, a[100005];

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

        for(int i = 0; i < n * m; i++)
        {
            cin >> a[i];
            v.pb({a[i], -i});
        }

        sort(v.begin(), v.end());

        int ans = 0;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                for(int k = 0; k < j; k++)
                    if(v[i * m + j].y < v[i * m + k].y)
                        ans++;
            }

        cout << ans << "\n";
    }
}