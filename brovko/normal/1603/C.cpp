#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int MOD = 998244353;

int t, n, a[100005], k[100005], k2[100005];
vector <int> v, v2;

int add(int x, int y)
{
    x += y;

    if(x >= MOD)
        x -= MOD;

    return x;
}

int mul(int x, int y)
{
    return x * 1ll * y % MOD;
}

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

        v.clear();
        v2.clear();

        int ans = 0;

        for(int i = n - 1; i >= 0; i--)
        {
            v.pb(1);
            k[1] = 1;

            for(auto x:v2)
            {
                int d = a[i + 1] / x;
                int c = (a[i] + d - 1) / d;

                if(k[c] == 0)
                    v.pb(c);

                k[c] += k2[x];
            }

            for(auto x:v2)
                k2[x] = 0;

            for(auto x:v)
            {
                ans = add(ans, mul(x - 1, mul(k[x], i + 1)));

                k2[x] = k[x];
                k[x] = 0;
            }

            v2 = v;
            v.clear();
        }

        for(auto x:v)
            k2[x] = 0;

        v.clear();

        cout << ans << "\n";
    }
}