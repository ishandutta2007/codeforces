#include <bits/stdc++.h>
//#define int long long
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

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector <int> a(n), b(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            cin >> b[i];

        int ans = 0, sa = 0, sb = 0;

        for(int i = 0; i < n; i++)
        {
            ans += abs(a[i] - b[i]);
            sa += a[i];
            sb += b[i];
        }

        cout << min(ans, abs(sa - sb) + 1) << "\n";
    }
}