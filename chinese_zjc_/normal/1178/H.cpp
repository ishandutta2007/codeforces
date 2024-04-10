// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int l, r = 1000000001;
int n, m, a[4405], b[4405], d[4405], cost, id[4405], S, T, ecnt, ncnt, head[100005], cur[100005], dis[100005];
bool vis[100005];
long long c[4405];
bool check(int x)
{
    for (int i = 1; i <= m; ++i)
        c[i] = 1ll * a[i] * x + b[i];
    std::fill(d + 1, d + 1 + n, 0);
    for (int i = 1; i <= m; ++i)
    {
        int cnt = 0;
        for (int j = n + 1; j <= m; ++j)
            if (c[j] <= c[i])
                ++cnt;
        for (int j = 1; j <= n; ++j)
            if (b[j] >= b[i])
                d[j] = std::max(d[j], cnt);
    }
    std::sort(d + 1, d + 1 + n);
    for (int i = 1; i <= n; ++i)
        if (d[i] < i)
            return false;
    return true;
}
struct edge
{
    int n, t, c, f;
} e[100005];
int new_node() { return head[ncnt] = -1, ncnt++; }
void add_edge(int A, int B, int C, int F)
{
    e[ecnt].n = head[A];
    e[ecnt].t = B;
    e[ecnt].c = C;
    e[ecnt].f = F;
    head[A] = ecnt++;
}
void add_flow(int A, int B, int C, int F)
{
    add_edge(A, B, +C, F);
    add_edge(B, A, -C, 0);
}
bool spfa()
{
    std::fill(dis, dis + ncnt, INT_MAX);
    dis[S] = 0;
    std::queue<int> que;
    que.push(S);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        vis[now] = false;
        for (int i = head[now]; ~i; i = e[i].n)
            if (e[i].f && dis[e[i].t] > dis[now] + e[i].c)
            {
                dis[e[i].t] = dis[now] + e[i].c;
                if (!vis[e[i].t])
                {
                    vis[e[i].t] = true;
                    que.push(e[i].t);
                }
            }
    }
    return dis[T] != INT_MAX;
}
int dinic(int now = S, int flow = INT_MAX)
{
    if (now == T || !flow)
        return flow;
    int res = 0;
    vis[now] = true;
    for (int &i = cur[now]; ~i; i = e[i].n)
        if (e[i].f && dis[e[i].t] == dis[now] + e[i].c && !vis[e[i].t])
        {
            int tmp = dinic(e[i].t, std::min(flow, e[i].f));
            e[i].f -= tmp;
            e[i ^ 1].f += tmp;
            res += tmp;
            flow -= tmp;
            cost += tmp * e[i].c;
            if (!flow)
                break;
            if (e[i].f)
                dis[e[i].t] = INT_MAX;
        }
    vis[now] = false;
    return res;
}
void work(int x)
{
    static int rk[4405];
    S = new_node();
    T = new_node();
    for (int i = 1; i <= m; ++i)
        c[i] = 1ll * a[i] * x + b[i], rk[i] = i;
    std::sort(rk + 1, rk + 1 + m, [&](const int &A, const int &B)
              { return b[A] > b[B]; });
    b[0] = c[0] = -1;
    for (int i = 1, lst = -1; i <= m; ++i)
    {
        int l = new_node(), mid = b[rk[i - 1]] != b[rk[i]] ? new_node() : lst, r = new_node();
        if (rk[i] <= n)
            add_flow(S, l, 0, 1);
        add_flow(l, mid, 1, n);
        add_flow(mid, r, 0, n);
        add_flow(l, r, 0, n);
        if (~lst && b[rk[i - 1]] != b[rk[i]])
            add_flow(lst, mid, 0, n);
        lst = mid;
        id[rk[i]] = r;
    }
    std::sort(rk + 1, rk + 1 + m, [&](const int &A, const int &B)
              { return c[A] > c[B]; });
    for (int i = 1, lst = -1; i <= m; ++i)
    {
        int l = new_node(), mid = c[rk[i - 1]] != c[rk[i]] ? new_node() : lst, r = new_node();
        if (rk[i] > n)
            add_flow(r, T, 0, 1);
        add_flow(l, mid, 1, n);
        add_flow(mid, r, 0, n);
        add_flow(l, r, 0, n);
        add_flow(id[rk[i]], l, 0, n);
        if (~lst && c[rk[i - 1]] != c[rk[i]])
            add_flow(lst, mid, 0, n);
        lst = mid;
    }
    while (spfa())
    {
        std::copy(head, head + ncnt, cur);
        dinic();
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    m = n << 1;
    for (int i = 1; i <= m; ++i)
        std::cin >> a[i] >> b[i];
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if (l == 1000000001)
        return std::cout << -1 << std::endl, 0;
    work(l);
    std::cout << l << ' ' << cost << std::endl;
    return 0;
}