#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

int t, n, m, a[105], b[105], c[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for(int i = 0; i < 105; i++)
            c[i] = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            c[a[i]]++;
        }

        int ans = 0;

        for(int i = 0; i < m; i++)
        {
            cin >> b[i];
            c[b[i]]++;

            if(c[b[i]] == 2)
                ans++;
        }

        cout << ans << "\n";
    }
}