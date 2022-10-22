#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, x, a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> x;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        map <int, int> m;

        for(int i = 0; i < n; i++)
            m[a[i]]++;

        for(auto p:m)
        {
            while(m[p.x] && p.x % x == 0 && m[p.x / x])
            {
                m[p.x]--;
                m[p.x / x]--;
            }
        }

        int ans = 0;

        for(auto p:m)
            ans += p.y;

        cout << ans << "\n";
    }
}