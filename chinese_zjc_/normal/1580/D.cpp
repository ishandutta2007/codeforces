// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug1
int n, m, ls[4005], rs[4005];
long long a[4005], siz[4005], dp[4005][4005];
std::vector<int> st;
void cmax(long long &A, long long B) { A = std::max(A, B); }
void dfs(int now)
{
    siz[now] = 1;
    if (ls[now])
        dfs(ls[now]), siz[now] += siz[ls[now]];
    if (rs[now])
        dfs(rs[now]), siz[now] += siz[rs[now]];
    if (ls[now] && rs[now])
    {
        for (int i = 0; i <= siz[ls[now]]; ++i)
            for (int j = 0; j <= siz[rs[now]]; ++j)
            {
                cmax(dp[now][i + j], dp[ls[now]][i] + dp[rs[now]][j] - 2 * a[now] * i * j);
                cmax(dp[now][i + j + 1], dp[ls[now]][i] + dp[rs[now]][j] + a[now] * (m - 1 - 2 * (i + j)) - 2 * a[now] * i * j);
            }
    }
    else if (ls[now])
    {
        for (int i = 0; i <= siz[ls[now]]; ++i)
        {
            cmax(dp[now][i], dp[ls[now]][i]);
            cmax(dp[now][i + 1], dp[ls[now]][i] + a[now] * (m - 1 - 2 * i));
        }
    }
    else if (rs[now])
    {
        for (int i = 0; i <= siz[rs[now]]; ++i)
        {
            cmax(dp[now][i], dp[rs[now]][i]);
            cmax(dp[now][i + 1], dp[rs[now]][i] + a[now] * (m - 1 - 2 * i));
        }
    }
    else
    {
        dp[now][0] = 0;
        dp[now][1] = a[now] * (m - 1);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    st.push_back(0);
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        while (!st.empty() && a[st.back()] > a[i])
            ls[i] = st.back(), st.pop_back();
        rs[st.back()] = i;
        st.push_back(i);
    }
    memset(dp, 0xf0, sizeof(dp));
    dfs(rs[0]);
    std::cout << dp[rs[0]][m] << std::endl;
    return 0;
}