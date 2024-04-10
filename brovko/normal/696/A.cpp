#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

int t;
map <int, int> m;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        int T;
        cin >> T;

        if(T == 1)
        {
            int u, v, w;

            cin >> u >> v >> w;

            while(u != v)
            {
                if(u > v)
                {
                    m[u] += w;
                    u /= 2;
                }

                else
                {
                    m[v] += w;
                    v /= 2;
                }
            }
        }

        else
        {
            int u, v;
            cin >> u >> v;

            int ans = 0;

            while(u != v)
            {
                if(u > v)
                {
                    ans += m[u];
                    u /= 2;
                }

                else
                {
                    ans += m[v];
                    v /= 2;
                }
            }

            cout << ans << "\n";
        }
    }
}