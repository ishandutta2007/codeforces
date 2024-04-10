// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, Llim, Rlim, fa[100005], depth[100005], maxdepth[100005], v[100005], siz[100005], heavy[100005];
std::pair<int, int> ans;
std::vector<std::pair<int, int>> son[100005];
void kill(int now)
{
    siz[now] = 1;
    for (std::size_t i = 0; i != son[now].size(); ++i)
    {
        if (fa[now] == son[now][i].first)
        {
            std::swap(son[now][i--], son[now].back());
            son[now].pop_back();
            continue;
        }
        fa[son[now][i].first] = now;
        maxdepth[son[now][i].first] = depth[son[now][i].first] = depth[now] + 1;
        kill(son[now][i].first);
        maxdepth[now] = std::max(maxdepth[now], maxdepth[son[now][i].first]);
        siz[now] += siz[son[now][i].first];
        if (siz[son[now][i].first] > siz[heavy[now]])
            heavy[now] = son[now][i].first;
    }
}
void init(int now, int lim)
{
    for (auto i : son[now])
    {
        v[i.first] = v[now] + (i.second < lim ? -1 : +1);
        init(i.first, lim);
    }
}
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
const std::pair<int, int> MIN = {INT_MIN / 2, 0};
std::pair<int, int> max[1 << 18];
void clear(int L, int R, int now = 1, int l = depth[1], int r = maxdepth[1])
{
    if (R < l || r < L)
        return;
    max[now] = MIN;
    if (l == r)
        return;
    clear(L, R, lson, l, lmid);
    clear(L, R, rson, rmid, r);
}
void update(int pos, std::pair<int, int> val, int now = 1, int l = depth[1], int r = maxdepth[1])
{
    max[now] = std::max(max[now], val);
    if (l == r)
        return;
    if (pos <= lmid)
        update(pos, val, lson, l, lmid);
    else
        update(pos, val, rson, rmid, r);
}
std::pair<int, int> query(int L, int R, int now = 1, int l = depth[1], int r = maxdepth[1])
{
    if (R < l || r < L)
        return MIN;
    if (L <= l && r <= R)
        return max[now];
    return std::max(query(L, R, lson, l, lmid), query(L, R, rson, rmid, r));
}
#undef lson
#undef rson
#undef lmid
#undef rmid
void add(int now)
{
    update(depth[now], {v[now], now});
    for (auto i : son[now])
        add(i.first);
}
void del(int now) { clear(depth[now], maxdepth[now]); }
void calc(int now, int lca)
{
    std::pair<int, int> tmp = query(Llim + 2 * depth[lca] - depth[now], Rlim + 2 * depth[lca] - depth[now]);
    if (tmp.first + v[now] - 2 * v[lca] >= 0)
        ans = {tmp.second, now};
    for (auto i : son[now])
        calc(i.first, lca);
}
void dfs(int now)
{
    for (auto i : son[now])
    {
        if (i.first == heavy[now])
            continue;
        dfs(i.first);
        del(i.first);
    }
    if (heavy[now])
        dfs(heavy[now]);
    for (auto i : son[now])
    {
        if (i.first == heavy[now])
            continue;
        calc(i.first, now);
        add(i.first);
    }
    std::pair<int, int> tmp = query(Llim + depth[now], Rlim + depth[now]);
    if (tmp.first - v[now] >= 0)
        ans = {tmp.second, now};
    update(depth[now], {v[now], now});
}
bool check(int lim)
{
    init(1, lim);
    ans = {0, 0};
    clear(depth[1], maxdepth[1]);
    dfs(1);
    return ans.first && ans.second;
}
std::vector<int> app;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> Llim >> Rlim;
    for (int i = 1, x, y, z; i != n; ++i)
    {
        std::cin >> x >> y >> z;
        app.push_back(z);
        son[x].push_back({y, z});
        son[y].push_back({x, z});
    }
    std::sort(app.begin(), app.end());
    app.erase(std::unique(app.begin(), app.end()), app.end());
    kill(1);
    int l = 0, r = app.size() - 1;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        // std::cout << l << ' ' << mid << ' ' << r << std::endl;
        if (check(app[mid]))
            l = mid;
        else
            r = mid - 1;
    }
    check(app[l]);
    std::cout << ans.first << ' ' << ans.second << std::endl;
    return 0;
}