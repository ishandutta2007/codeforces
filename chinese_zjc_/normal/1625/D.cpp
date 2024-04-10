// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, k, a[300005], son[9000005][2], tim, root;
std::set<int> ans, b;
void insert(int &now, int v, int pos)
{
    if (!now)
        now = ++tim;
    if (!pos)
        return;
    --pos;
    insert(son[now][v >> pos & 1], v, pos);
}
bool solve(int A, int Av, int B, int Bv, int pos)
{
    if (!A || !B)
        return false;
    // std::cout << Av << ' ' << Bv << ' ' << pos << std::endl;
    if ((Av ^ Bv) >= k)
        return ans.insert(*b.lower_bound(Av)), ans.insert(*b.lower_bound(Bv)), true;
    if (!pos)
        return false;
    --pos;
    return solve(son[A][0], Av, son[B][1], Bv | 1 << pos, pos) ||
           solve(son[A][1], Av | 1 << pos, son[B][0], Bv, pos) ||
           (~k >> pos & 1 && (solve(son[A][0], Av, son[B][0], Bv, pos) ||
                              solve(son[A][1], Av | 1 << pos, son[B][1], Bv | 1 << pos, pos)));
}
void solve(int now, int v, int pos)
{
    if (!now)
        return;
    --pos;
    if (k >> pos & 1)
        solve(son[now][0], v, son[now][1], v | 1 << pos, pos) ? true : ans.insert(*b.lower_bound(v)).second;
    else
        solve(son[now][0], v, pos), solve(son[now][1], v | 1 << pos, pos);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], b.insert(a[i]), insert(root, a[i], 30);
    if (!k)
    {
        std::cout << n << std::endl;
        for (int i = 1; i <= n; ++i)
            std::cout << i << " \n"[i == n];
        return 0;
    }
    solve(root, 0, 30);
    if (ans.size() <= 1)
        return std::cout << -1 << std::endl, 0;
    std::cout << ans.size() << std::endl;
    // for (auto i : ans)
    //     std::cout << i << ' ';
    // std::cout << std::endl;
    for (int i = 1; i <= n; ++i)
        if (ans.count(a[i]))
            ans.erase(a[i]), std::cout << i << " \n"[ans.empty()];
    return 0;
}