// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, d, cnt, ans;
bool a[1000005];
bool now = false, nxt = true;
std::queue<int> que[2];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> d;
        cnt = 0;
        for (int i = 0; i != n; ++i)
        {
            std::cin >> a[i];
            if (!a[i])
                que[now].push(i);
        }
        ans = -1;
        for (int i = 0; i <= n; ++i, std::swap(now, nxt))
        {
            while (!que[now].empty())
            {
                int v = que[now].front();
                que[now].pop();
                ++cnt;
                if (a[(v - d + n) % n])
                    a[(v - d + n) % n] = false, que[nxt].push((v - d + n) % n);
            }
            if (cnt == n)
            {
                ans = i;
                break;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}