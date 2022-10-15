#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = (int) 1e9 + 7;

int add(int a, int b)
{
    a += b;
    if (a >= MOD)
    {
        return a - MOD;
    }
    if (a < 0)
    {
        return a + MOD;
    }
    return a;
}

int mul(int a, int b)
{
    return a * (ll) b % MOD;
}

const int N = 5000 + 7;
int n;
string s;
int a[N];
int c[N][N]; /// c[l][r]
int dp[N][N]; /// dp[p][len]
int sum[N][N];

struct T
{
    int c;
    int last;
    int i;
};

bool operator < (T a, T b)
{
    if (a.c != b.c)
    {
        return a.c < b.c;
    }
    else
    {
        return a.last < b.last;
    }
}

void build(int r)
{
    int cur = 0;
    for (int i = 0; i <= n; i++)
    {
        cur = add(cur, dp[r][i]);
        sum[r][i] = cur;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        a[i] = s[i - 1] - '0';
    }
    for (int i = 1; i <= n; i++)
    {
        c[i][i] = a[i];
    }
    for (int len = 2; len <= n; len++)
    {
        vector<T> t;
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            t.push_back({c[l][r - 1], a[r], l});
        }
        sort(t.begin(), t.end());
        int cur = 0;
        T ant = {-1, -1, -1};
        for (auto &it : t)
        {
            cur += (it.c != ant.c || it.last != ant.last);
            ant = it;
            c[it.i][it.i + len - 1] = cur;
        }
    }
    dp[0][0] = 1;
    build(0);
    for (int p = 1; p <= n; p++)
    {
        for (int len = 1; len <= p; len++)
        {
            if (a[p - len + 1] != 0)
            {
                dp[p][len] = sum[p - len][len - 1];
                if (p - 2 * len + 1 >= 1 && c[p - len + 1][p] > c[p - 2 * len + 1][p - len])
                {
                    dp[p][len] = add(dp[p][len], dp[p - len][len]);
                }
            }
        }
        build(p);
    }
    int ans = 0;
    for (int len = 1; len <= n; len++)
    {
        ans = add(ans, dp[n][len]);
    }
    cout << ans << "\n";
}