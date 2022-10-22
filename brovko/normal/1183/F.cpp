#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int q, n, a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    while(q--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        if(n == 1)
        {
            cout << a[0] << "\n";
            continue;
        }

        sort(a, a + n);

        vector <int> v;

        for(int i = 0; i < n; i++)
            if(i == 0 || a[i] != a[i - 1])
                v.pb(a[i]);

        int m = v.size();

        int ans = v[m - 1];

        for(int i = 0; i < m; i++)
            if(v[m - 1] % v[i])
                ans = max(ans, v[m - 1] + v[i]);

        int x = v[m - 1];
        int j = m - 2;

        while(j >= 0 && x % v[j] == 0)
            j--;

        if(j >= 0)
        {
            int y = v[j];

            while(j >= 0 && (y % v[j] == 0 || x % v[j] == 0))
                j--;

            if(j >= 0)
                ans = max(ans, x + y + v[j]);
        }


        x = v[m - 2];
        j = m - 2;

        while(j >= 0 && x % v[j] == 0)
            j--;

        if(j >= 0)
        {
            int y = v[j];

            while(j >= 0 && (y % v[j] == 0 || x % v[j] == 0))
                j--;

            if(j >= 0)
                ans = max(ans, x + y + v[j]);
        }

        cout << ans << "\n";
    }
}