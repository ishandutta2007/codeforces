// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, l[200005], r[200005];
long long s;
bool check(int c)
{
    long long left = s;
    int g = (n + 1) >> 1;
    std::priority_queue<int, std::vector<int>, std::greater<int>> que;
    for (int i = 1; i <= n; ++i)
        if (r[i] < c)
            left -= l[i];
        else if (l[i] >= c)
            left -= l[i], --g;
        else
            left -= l[i], que.push(c - l[i]);
    while (!que.empty() && que.top() <= left)
    {
        left -= que.top();
        que.pop();
        --g;
    }
    return g <= 0;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> s;
        for (int i = 1; i <= n; ++i)
            std::cin >> l[i] >> r[i];
        int L = 0, R = 1000000000;
        while (L < R)
        {
            int mid = (L + R + 1) >> 1;
            if (check(mid))
                L = mid;
            else
                R = mid - 1;
        }
        std::cout << L << std::endl;
    }
    return 0;
}