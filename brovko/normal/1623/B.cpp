#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, l[1005], r[1005], used[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> l[i] >> r[i];

        vector <pair <int, int> > v;

        for(int i = 0; i < n; i++)
            v.pb({r[i] - l[i], i});

        sort(v.begin(), v.end());

        for(int i = 1; i <= n; i++)
            used[i] = 0;

        for(int i = 0; i < n; i++)
        {
            int j = v[i].y;

            for(int z = l[j]; z <= r[j]; z++)
                if(used[z] == 0)
                {
                    used[z] = 1;
                    cout << l[j] << ' ' << r[j] << ' ' << z << "\n";
                }
        }
    }
}