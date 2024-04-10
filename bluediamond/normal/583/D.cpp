#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 300 + 7;
int n, dp[N], f[N];

vector <int> dup(vector <int> a, int cnt)
{
        vector <int> b;
        for (int i = 1; i <= cnt; i++)
        {
                for (auto &x : a)
                {
                        b.push_back(x);
                }
        }
        return b;
}

void build_dp(vector <int> a)
{
        for (auto &x : a)
        {
                /// y = x
                dp[x]++;
                for (int y = 1; y < x; y++)
                {
                        dp[x] = max(dp[x], 1 + dp[y]);
                }
        }
}

int solve(vector <int> a, int rep)
{
        build_dp(dup(a, rep));
        int res = 0;
        for (int x = 1; x <= 300; x++)
        {
                res = max(res, dp[x]);
        }
        return res;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n, t;
        cin >> n >> t;
        vector <int> a(n);
        for (int i = 0; i < n; i++)
        {
                cin >> a[i];
                f[a[i]]++;
        }
        if (t <= 2 * n)
        {
                cout << solve(a, t) << "\n";
        }
        else
        {
                build_dp(dup(a, n));
                for (int x = 1; x <= 300; x++)
                {
                        dp[x] += f[x] * (t - 2 * n);
                }
                cout << solve(a, n) << "\n";
        }
        return 0;
}