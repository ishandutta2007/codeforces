#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;
const int MOD = 998244353;

int add(int x, int y)
{
    x += y;

    return (x >= MOD ? x - MOD : x);
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

    int t;
    cin >> t;

    while(t--)
    {
        int n, s;
        cin >> n >> s;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i]--;
        }

        vector <int> b(n);

        for(int i = 0; i < n; i++)
        {
            cin >> b[i];
            b[i]--;
        }

        vector <int> posa(n), posb(n);

        for(int i = 0; i < n; i++)
            posa[a[i]] = i;

        for(int i = 0; i < n; i++)
            if(b[i] >= 0)
                posb[b[i]] = i;

        int dp = 1, k = 0;

        for(int i = 0; i < s; i++)
            k += (b[posa[i]] < 0);

        for(int i = 0; i < n; i++)
        {
            if(i + s < n)
                k += (b[posa[i + s]] < 0);

            if(b[posb[i]] == i)
                dp = mul(dp, (a[posb[i]] <= i + s));
            else
            {
                dp = mul(dp, k);
                k--;
            }
        }

        cout << dp << "\n";
    }
}