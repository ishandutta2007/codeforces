// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[200005], lson[200005], rson[200005];
long long sum[200005][2][2];
bool ans;
void work(int now)
{
    if (now == 0)
        return;
    work(lson[now]);
    work(rson[now]);
    sum[now][0][0] = sum[lson[now]][0][1] + a[now] + sum[rson[now]][1][0];
    sum[now][0][1] = std::max(sum[lson[now]][0][1] + a[now] + sum[rson[now]][1][1], sum[rson[now]][0][1]);
    sum[now][1][0] = std::max(sum[lson[now]][1][1] + a[now] + sum[rson[now]][1][0], sum[lson[now]][1][0]);
    sum[now][1][1] = sum[lson[now]][1][1] + a[now] + sum[rson[now]][1][1];
    ans &= a[now] >= sum[now][0][0];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    a[0] = INT_MAX;
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        rson[0] = 0;
        std::stack<int> sta({0});
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
            while (a[i] > a[sta.top()])
                sta.pop();
            lson[i] = rson[sta.top()];
            rson[sta.top()] = i;
            sta.push(i);
            rson[i] = 0;
        }
        ans = true;
        work(rson[0]);
        std::cout << (ans ? "YES" : "NO") << std::endl;
    }
    return 0;
}