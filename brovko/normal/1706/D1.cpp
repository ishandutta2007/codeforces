#include <bits/stdc++.h>
//#define int long long
#define pb push_back

using li = long long;

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
        int n, k;
        cin >> n >> k;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        int ans = 1e9;

        for(int i = 0; i <= a[0]; i++)
        {
            int mx = i;

            for(int j = 0; j < n; j++)
                mx = max(mx, max(a[j] / k, (i == 0 ? (int)-1e9 : a[j] / (a[j] / i))));

            ans = min(ans, mx - i);
        }

        cout << ans << "\n";
    }
}