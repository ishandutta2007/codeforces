#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[3005];

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
            cin >> a[i];

        int ans = 0;

        vector <int> v;

        for(int i = 0; i < n; i++)
            v.pb(a[i]);

        sort(v.begin(), v.end());

        for(int i = 0; i < n; i++)
        {
            int x = i;

            for(int j = 0; j < n; j++)
                if(x < n && a[j] == v[x])
                    x++;

            ans = max(ans, x - i);
        }

        cout << n - ans << "\n";
    }
}