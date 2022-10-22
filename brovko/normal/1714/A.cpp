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
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, H, M;
        cin >> n >> H >> M;

        vector <int> h(n), m(n);

        for(int i = 0; i < n; i++)
        {
            cin >> h[i] >> m[i];
        }

        vector <int> used(24 * 60);

        for(int i = 0; i < n; i++)
            used[h[i] * 60 + m[i]] = 1;

        int ans = 0;

        int t = H * 60 + M;

        while(used[t] == 0)
        {
            ans++;
            t = (t + 1) % (24 * 60);
        }

        cout << ans / 60 << ' ' << ans % 60 << "\n";
    }
}