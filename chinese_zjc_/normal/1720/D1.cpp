// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int son[9000005][2], bes[9000005][2], root, cnt;
int T, n, a[300005];
void cmax(int &A, int B) { A = std::max(A, B); }
void insert(int pos, int val, int dp, int dep = 30, int &now = root)
{
    if (!now)
        now = ++cnt;
    cmax(bes[now][pos >> dep & 1], dp);
    if (!dep)
        return;
    --dep;
    insert(pos, val, dp, dep, son[now][(pos ^ val) >> dep & 1]);
}
void work(int pos, int val, int &dp, int dep = 30, int now = root)
{
    if (!now)
        return;
    if (!dep)
        return;
    --dep;
    work(pos, val, dp, dep, son[now][(pos ^ val) >> dep & 1]);
    if (int p = son[now][~(pos ^ val) >> dep & 1])
        cmax(dp, bes[p][~val >> dep & 1]);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 0; i != n; ++i)
            std::cin >> a[i];
        for (int i = 0; i != n; ++i)
        {
            int v = 0;
            work(i, a[i], v);
            insert(i, a[i], ++v);
        }
        std::cout << bes[root][0] << std::endl;
        for (int i = 1; i <= cnt; ++i)
            son[i][0] = son[i][1] = bes[i][0] = bes[i][1] = 0;
        cnt = root = 0;
    }
    return 0;
}