// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
int n;
namespace A
{
    int min[1 << 19], depth[200005], fa[20][200005], dfn[200005], end[200005], idfn[200005], tim;
    std::vector<int> son[200005];
    std::vector<std::pair<int, int>> killed;
    std::set<std::pair<int, int>> h[200005];
    void pushup(int now)
    {
        min[now] = std::min(min[lson], min[rson]);
    }
    void build(int now = 1, int l = 1, int r = n)
    {
        if (l == r)
            return void(min[now] = h[dfn[l]].empty() ? INT_MAX : h[dfn[l]].begin()->first);
        build(lson, l, lmid);
        build(rson, rmid, r);
        pushup(now);
    }
    void work(int L, int R, int v, int now = 1, int l = 1, int r = n)
    {
        if (R < l || r < L || min[now] > v)
            return;
#ifdef debug
        std::cout << L << ' ' << R << ' ' << v << ' ' << now << ' ' << l << ' ' << r << std::endl;
#endif
        if (l == r)
        {
#ifdef debug
            for (auto i : h[dfn[l]])
                std::cout << i.first << ' ' << i.second << std::endl;
#endif
            while (!h[dfn[l]].empty() && h[dfn[l]].begin()->first <= v)
            {
                killed.emplace_back(dfn[l], h[dfn[l]].begin()->second);
                h[h[dfn[l]].begin()->second].erase({h[dfn[l]].begin()->first, dfn[l]});
                h[dfn[l]].erase(h[dfn[l]].begin());
            }
            min[now] = h[dfn[l]].empty() ? INT_MAX : h[dfn[l]].begin()->first;
            return;
        }
        work(L, R, v, lson, l, lmid);
        work(L, R, v, rson, rmid, r);
        pushup(now);
    }
    void init(int now)
    {
        dfn[idfn[now] = ++tim] = now;
        for (int i = 1; 1 << i <= depth[now]; ++i)
            fa[i][now] = fa[i - 1][fa[i - 1][now]];
        for (auto i : son[now])
        {
            depth[i] = depth[now] + 1;
            init(i);
        }
        end[now] = tim;
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
}
namespace B
{
    int min[1 << 19], depth[200005], fa[20][200005], dfn[200005], end[200005], idfn[200005], tim;
    std::vector<int> son[200005];
    std::vector<std::pair<int, int>> killed;
    std::set<std::pair<int, int>> h[200005];
    void pushup(int now)
    {
        min[now] = std::min(min[lson], min[rson]);
    }
    void build(int now = 1, int l = 1, int r = n)
    {
        if (l == r)
            return void(min[now] = h[dfn[l]].empty() ? INT_MAX : h[dfn[l]].begin()->first);
        build(lson, l, lmid);
        build(rson, rmid, r);
        pushup(now);
    }
    void work(int L, int R, int v, int now = 1, int l = 1, int r = n)
    {
        if (R < l || r < L || min[now] > v)
            return;
        if (l == r)
        {
            while (!h[dfn[l]].empty() && h[dfn[l]].begin()->first <= v)
            {
                killed.emplace_back(dfn[l], h[dfn[l]].begin()->second);
                h[h[dfn[l]].begin()->second].erase({h[dfn[l]].begin()->first, dfn[l]});
                h[dfn[l]].erase(h[dfn[l]].begin());
            }
            min[now] = h[dfn[l]].empty() ? INT_MAX : h[dfn[l]].begin()->first;
            return;
        }
        work(L, R, v, lson, l, lmid);
        work(L, R, v, rson, rmid, r);
        pushup(now);
    }
    void init(int now)
    {
        dfn[idfn[now] = ++tim] = now;
        for (int i = 1; 1 << i <= depth[now]; ++i)
            fa[i][now] = fa[i - 1][fa[i - 1][now]];
        for (auto i : son[now])
        {
            depth[i] = depth[now] + 1;
            init(i);
        }
        end[now] = tim;
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
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 2; i <= n; ++i)
        std::cin >> A::fa[0][i], A::son[A::fa[0][i]].push_back(i);
    for (int i = 2; i <= n; ++i)
        std::cin >> B::fa[0][i], B::son[B::fa[0][i]].push_back(i);
    A::init(1);
    B::init(1);
    int t;
    std::vector<int> killed;
    std::cin >> t;
    std::cout << "Blue" << '\n'
              << t << '\n';
    killed.push_back(t + 1);
    for (int i = 2; i <= n; ++i)
    {
        int LCA = A::LCA(i, B::fa[0][i]);
        A::h[i].insert({A::depth[LCA], B::fa[0][i]});
        A::h[B::fa[0][i]].insert({A::depth[LCA], i});
    }
    for (int i = 2; i <= n; ++i)
    {
        if (i - 1 == t)
            continue;
        int LCA = B::LCA(i, A::fa[0][i]);
        B::h[i].insert({B::depth[LCA], A::fa[0][i]});
        B::h[A::fa[0][i]].insert({B::depth[LCA], i});
    }
    A::build();
    B::build();
    for (int i = 2; true; ++i)
    {
        if (i & 1)
        {
            for (auto j : killed)
                B::work(B::idfn[j], B::end[j], B::depth[j] - 1);
            killed.clear();
            for (auto j : B::killed)
                killed.push_back(A::depth[j.first] > A::depth[j.second] ? j.first : j.second);
            B::killed.clear();
            std::sort(killed.begin(), killed.end());
            if (killed.empty())
                break;
            std::cout << "Blue" << '\n';
            for (auto i : killed)
                std::cout << i - 1 << ' ';
            std::cout << '\n';
        }
        else
        {
            for (auto j : killed)
                A::work(A::idfn[j], A::end[j], A::depth[j] - 1);
            killed.clear();
            for (auto j : A::killed)
                killed.push_back(B::depth[j.first] > B::depth[j.second] ? j.first : j.second);
            A::killed.clear();
            std::sort(killed.begin(), killed.end());
            if (killed.empty())
                break;
            std::cout << "Red" << '\n';
            for (auto i : killed)
                std::cout << i - 1 << ' ';
            std::cout << '\n';
        }
    }
    return 0;
}