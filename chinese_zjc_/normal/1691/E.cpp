// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, fa[100005], c[100005], l[100005], r[100005];
std::map<int, std::vector<int>> map;
struct cmp
{
    bool operator()(const int &A, const int &B) { return r[A] > r[B]; }
};
std::priority_queue<int, std::vector<int>, cmp> que[2];
int find(int now) { return fa[now] == now ? now : fa[now] = find(fa[now]); }
void connect(int A, int B) { fa[find(A)] = find(B); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        map.clear();
        std::iota(fa + 1, fa + 1 + n, 1);
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> c[i] >> l[i] >> r[i];
            map[l[i]].push_back(i);
            map[r[i]];
        }
        for (auto i : map)
        {
            for (auto j : i.second)
                que[c[j]].push(j);
            for (int j = 0; j != 2; ++j)
            {
                int k = !j;
                while (!que[j].empty() && r[que[j].top()] == i.first)
                {
                    int max = 0;
                    while (!que[k].empty())
                    {
                        int now = que[k].top();
                        que[k].pop();
                        connect(que[j].top(), now);
                        if (r[now] > r[max])
                            max = now;
                    }
                    que[j].pop();
                    if (max)
                        que[k].push(max);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            ans += find(i) == i;
        std::cout << ans << std::endl;
    }
    return 0;
}