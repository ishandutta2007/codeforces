#include <bits/stdc++.h>
#define int long long
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

    int t;
    cin >> t;

    while(t--)
    {
        int n, x;
        cin >> n >> x;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int Min = 1e9, Max = -1e9, ans = 0;

        for(int i = 0; i < n; i++)
        {
            Min = min(Min, a[i]);
            Max = max(Max, a[i]);

            if(Max - Min > 2 * x)
            {
                ans++;
                Min = a[i];
                Max = a[i];
            }
        }

        cout << ans << "\n";
    }
}