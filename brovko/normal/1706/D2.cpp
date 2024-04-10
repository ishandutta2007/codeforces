#include <bits/stdc++.h>
//#define int long long
#define pb push_back

using li = long long;

using namespace std;
const int N = 1e5 + 5;

vector <int> v(N);

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        for(int i = 0; i < N; i++)
            v[i] = -1;

        int n, k;
        cin >> n >> k;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector <int> nxt(n, -1);

        int Max = 0;

        for(int i = 0; i < n; i++)
        {
//            v[a[i] / k].push_back(a[i]);
            nxt[i] = v[a[i] / k];
            v[a[i] / k] = i;

            Max = max(Max, a[i] / k);
        }

        sort(a.begin(), a.end());

        int ans = 1e9;

        for(int Min = 0; Min <= a[0]; Min++)
        {
            if(Min > 0)
            {
//                for(auto x:v[Min - 1])
//                {
//                    int New = x / (x / Min);
//
//                    v[New].pb(x);
//                    Max = max(Max, New);
//                }

                int x = v[Min - 1];

                while(x != -1)
                {
                    int New = a[x] / (a[x] / Min);

                    int Nxt = nxt[x];
                    nxt[x] = v[New];
                    v[New] = x;

                    Max = max(Max, New);

                    x = Nxt;
                }

//                v[Min - 1].erase(v[Min - 1].begin(), v[Min - 1].end());
            }

            ans = min(ans, Max - Min);
        }

        cout << ans << "\n";
    }
}