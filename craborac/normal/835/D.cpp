#include <bits/stdc++.h>
#define android ios

using namespace std;

int dp[5001][5001], ans[5001];
long long h1[5001], h2[5001], st[5001];

long long p = 239;
long long m = (long long)1e9 + 7;

long long mod(long long a)
{
    a %= m;
    if (a < 0)
        a += m;
    return a;
}

long long has1(int l, int r)
{
    return mod(h1[r] - h1[l] * st[r - l]);
}

long long has2(int l, int r)
{
    return mod(h2[l] - h2[r] * st[r - l]);
}

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    h1[0] = 0;
    st[0] = 1;
    for (int i = 0; i < n; i++)
    {
        fill(dp[i], dp[i] + n + 1, 0);
        h1[i + 1] = (h1[i] * p + s[i]) % m;
        st[i + 1] = (st[i] * p) % m;
    }
    fill(ans, ans + n + 1, 0);
    h2[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        h2[i] = (h2[i + 1] * p + s[i]) % m;
    }
    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i + len <= n; i++)
        {
            int j = i + len;
            if (has1(i, i + len / 2) == has2(j - len / 2, j))
                dp[i][j] = dp[i][i + len / 2] + 1;
            else
                dp[i][j] = 0;
            ans[dp[i][j]]++;
        }
    }
    for (int i = n - 1; i > 0; i--)
        ans[i] += ans[i + 1];
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}