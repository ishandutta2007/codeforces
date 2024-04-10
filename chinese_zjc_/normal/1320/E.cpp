// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::vector<int> to[200005], T[200005];
int n, q, fa[20][200005], depth[200005], dfn[200005], tim, sp[200005];
std::pair<int, int> dis[200005];
std::vector<int> A, B, C, D;
void init(int now)
{
    dfn[now] = ++tim;
    for (int i = 1; 1 << i <= depth[now]; ++i)
        fa[i][now] = fa[i - 1][fa[i - 1][now]];
    for (auto i : to[now])
    {
        if (i == fa[0][now])
            continue;
        fa[0][i] = now;
        depth[i] = depth[now] + 1;
        init(i);
    }
}
int LCA(int A, int B)
{
    if (depth[A] < depth[B])
        std::swap(A, B);
    for (int i = 20; i--;)
        if (depth[A] - depth[B] >= 1 << i)
            A = fa[i][A];
    if (A == B)
        return A;
    for (int i = 20; i--;)
        if (fa[i][A] != fa[i][B])
            A = fa[i][A], B = fa[i][B];
    return fa[0][A];
}
int up(int A, int B) { return (A - 1) / B + 1; }
int DIS(int A, int B) { return depth[A] + depth[B] - depth[LCA(A, B)] * 2; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1, x, y; i < n; ++i)
        std::cin >> x >> y, to[x].push_back(y), to[y].push_back(x);
    init(1);
    std::cin >> q;
    for (int i = 1, x, y; i <= q; ++i)
    {
        std::cin >> x >> y;
        for (int j = 0, t; j != x; ++j)
            std::cin >> t >> sp[j], A.push_back(t), C.push_back(t);
        for (int j = 0, t; j != y; ++j)
            std::cin >> t, B.push_back(t), C.push_back(t);
        std::sort(C.begin(), C.end(), [&](const int &A, const int &B)
                  { return dfn[A] < dfn[B]; });
        std::stack<int> sta;
        std::for_each(C.begin(), C.end(), [&](const int &now)
                      {
                        if (sta.empty())
                        {
                            sta.push(now);
                            return;
                        }
                        int lca = LCA(sta.top(), now);
                        while (!sta.empty() && dfn[lca] < dfn[sta.top()])
                        {
                            int tmp = sta.top();
                            sta.pop();
                            D.push_back(tmp);
                            T[sta.empty() || dfn[sta.top()] < dfn[lca] ? lca : sta.top()].push_back(tmp);
                            T[tmp].push_back(sta.empty() || dfn[sta.top()] < dfn[lca] ? lca : sta.top());
                        }
                        if (sta.empty() || sta.top() != lca)
                            sta.push(lca);
                        sta.push(now); });
        while (!sta.empty())
        {
            int tmp = sta.top();
            sta.pop();
            D.push_back(tmp);
            if (!sta.empty())
                T[sta.top()].push_back(tmp), T[tmp].push_back(sta.top());
        }
        std::priority_queue<std::pair<std::pair<int, int>, int>,
                            std::vector<std::pair<std::pair<int, int>, int>>,
                            std::greater<std::pair<std::pair<int, int>, int>>>
            que;
        std::for_each(D.begin(), D.end(), [&](const int &now)
                      { dis[now].first = 1919810; });
        for (std::size_t j = 0; j != A.size(); ++j)
            que.push({dis[A[j]] = {0, j}, A[j]});
        // for (auto i : D)
        //     std::cout << i << ' ';
        // std::cout << std::endl;
        while (!que.empty())
        {
            if (que.top().first != dis[que.top().second])
            {
                que.pop();
                continue;
            }
            int now = que.top().second, p = dis[now].second;
            que.pop();
            for (auto i : T[now])
            {
                std::pair<int, int> tmp = {up(DIS(A[p], i), sp[p]), p};
                if (dis[i] > tmp)
                    que.push({dis[i] = tmp, i});
            }
        }
        std::for_each(B.begin(), B.end(), [&](const int &now)
                      { std::cout << dis[now].second + 1 << ' '; });
        std::cout << std::endl;
        std::for_each(D.begin(), D.end(), [&](const int &now)
                      { T[now].clear(); });
        A.clear();
        B.clear();
        C.clear();
        D.clear();
    }
    return 0;
}