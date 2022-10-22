#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int MOD = 1e9 + 7;

int p[200005], dp[200005], ps[200005], pps[200005];

int add(int x, int y)
{
    return (x + y) % MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();
    s = t + "#" + s;
    int k = 0;

    for(int i = 1; i < s.size(); i++)
    {
        while(k > 0 && s[k] != s[i])
            k = p[k - 1];

        if(s[k] == s[i])
            k++;

        p[i] = k;
    }

    int ans = 0;

    pps[m] = 1;

    for(int i = m + 1; i < s.size(); i++)
    {
        if(p[i] >= m)
            dp[i] = pps[i - m];
        else dp[i] = dp[i - 1];

        ps[i] = add(ps[i - 1], dp[i]);
        pps[i] = add(pps[i - 1], ps[i] + 1);
        ans = add(ans, dp[i]);
    }

    cout << ans << endl;
}