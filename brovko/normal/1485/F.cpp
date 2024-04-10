#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;
const int MOD = 1e9 + 7;

int t, n, b[200005], ss[200005], nxt[200005], ss2[200005], dp[200005];

int add(int x, int y)
{
    return (x + y) % MOD;
}

int sub(int x, int y)
{
    return add(x, MOD - y);
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
            cin >> b[i];

        for(int i = 0; i < n; i++)
            nxt[i] = n + 1;

        ss[n] = 0;
        map <int, int> q;
        q[0] = n;

        for(int i = n - 1; i >= 0; i--)
        {
            ss[i] = ss[i + 1] + b[i];

            if(q[ss[i]] > 0)
                nxt[i] = q[ss[i]];

            q[ss[i]] = i;
        }

        dp[n] = 1;

        for(int i = 0; i <= n + 2; i++)
            ss2[i] = 0;

        ss2[n] = 1;

        for(int i = n - 1; i >= 0; i--)
        {
            dp[i] = sub(ss2[i + 1], ss2[nxt[i] + 1]);
            ss2[i] = add(ss2[i + 1], dp[i]);
        }

        cout << dp[0] << "\n";
    }
}