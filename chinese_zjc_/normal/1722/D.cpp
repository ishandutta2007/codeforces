// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, n;
long long ans;
std::string s;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> s;
        ans = 0;
        std::priority_queue<int> que;
        for (int i = 0; i != n; ++i)
        {
            int a = s[i] == 'L' ? i : n - i - 1, b = n - 1 - a;
            ans += a;
            que.push(b - a);
        }
        for (int i = 1; i <= n; ++i)
        {
            if (que.top() > 0)
                ans += que.top(), que.pop();
            std::cout << ans << " \n"[i == n];
        }
    }
    return 0;
}