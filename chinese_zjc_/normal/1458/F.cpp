// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int long long
const long long INF = LLONG_MAX >> 1;
int n, m, siz[200005], fa[200005], ans;
bool vis[200005];
std::vector<int> to[200005];
struct ST
{
    int rmq[20][400005], lg[400005], depth[200005], app[200005], fa[20][200005], cnt;
    int cmin(int A, int B) { return depth[A] < depth[B] ? A : B; }
    void init_tree(int now)
    {
        for (int i = 1; 1 << i <= depth[now]; ++i)
            fa[i][now] = fa[i - 1][fa[i - 1][now]];
        rmq[0][app[now] = ++cnt] = now;
        for (auto i : to[now])
        {
            if (i == fa[0][now])
                continue;
            depth[i] = depth[now] + 1;
            fa[0][i] = now;
            init_tree(i);
            rmq[0][++cnt] = now;
        }
    }
    void init()
    {
        init_tree(1);
        // for (int i = 1; i <= cnt; ++i)
        //     std::cout << rmq[0][i] << " \n"[i == cnt];
        for (int i = 2; i <= cnt; ++i)
            lg[i] = lg[i - 1] + !(i & (i - 1));
        for (int i = 1; 1 << i <= cnt; ++i)
            for (int j = 1; j + (1 << i) - 1 <= cnt; ++j)
                rmq[i][j] = cmin(rmq[i - 1][j], rmq[i - 1][j + (1 << i >> 1)]);
    }
    int query(int A, int B)
    {
        if (A > B)
            std::swap(A, B);
        int len = B - A + 1;
        return cmin(rmq[lg[len]][A], rmq[lg[len]][B - (1 << lg[len]) + 1]);
    }
    int LCA(int A, int B) { return query(app[A], app[B]); }
    int get_dis(int A, int B) { return depth[A] + depth[B] - depth[LCA(A, B)] * 2; }
    int go(int A, int B, int k)
    {
        int lca = LCA(A, B);
        if (depth[A] - depth[lca] < k)
            k = depth[A] + depth[B] - depth[lca] * 2 - k, std::swap(A, B);
        for (int i = 19; ~i; --i)
            if (k >= 1 << i)
                A = fa[i][A], k -= 1 << i;
        return A;
    }
} s;
void init_siz(int now, int fa)
{
    siz[now] = 1;
    for (auto i : to[now])
    {
        if (i == fa || vis[i])
            continue;
        init_siz(i, now);
        siz[now] += siz[i];
    }
}
int find_root(int now, int fa, int tot)
{
    int max = tot - siz[now];
    for (auto i : to[now])
    {
        if (i == fa || vis[i])
            continue;
        int res = find_root(i, now, tot);
        if (res)
            return res;
        max = std::max(max, siz[i]);
    }
    return max <= tot / 2 ? now : 0;
}
void build(int now, int lst)
{
    init_siz(now, 0);
    int tot = siz[now];
    siz[now = find_root(now, 0, tot)] = tot;
    fa[now] = lst;
    vis[now] = true;
    for (auto i : to[now])
        if (!vis[i])
            build(i, now);
}
const std::pair<int, int> operator+(const std::pair<int, int> &A, const std::pair<int, int> &B)
{
    int dis = s.get_dis(A.first, B.first);
    if (A.second >= B.second + dis)
        return A;
    if (B.second >= A.second + dis)
        return B;
    return std::make_pair(s.go(A.first, B.first, (dis - A.second + B.second) / 2), (dis + A.second + B.second) / 2);
}
int cnt1[200005], cnt2[200005], sum1[200005], sum2[200005];
void modify(int pos, int val)
{
    for (int i = pos; i; i = fa[i])
        cnt1[i] += val, sum1[i] += val * s.get_dis(i, pos);
    for (int i = pos; fa[i]; i = fa[i])
        cnt2[i] += val, sum2[i] += val * s.get_dis(fa[i], pos);
}
int query(int pos)
{
    int res = 0;
    for (int i = pos; i; i = fa[i])
        res += cnt1[i] * s.get_dis(i, pos) + sum1[i];
    for (int i = pos; fa[i]; i = fa[i])
        res -= cnt2[i] * s.get_dis(fa[i], pos) + sum2[i];
    return res;
}
void cdq(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    cdq(l, mid);
    cdq(mid + 1, r);
    static std::pair<int, int> R[100005], L;
    int i, j = mid + 1, k = mid + 1, sum = 0, cnt = 0;
    for (i = mid + 1, R[i] = std::make_pair(i, 0); ++i <= r;)
        R[i] = R[i - 1] + std::make_pair(i, 0);
    for (i = mid + 1; i <= r; ++i)
        sum += R[i].second * 2;
    for (L = std::make_pair(i = mid, 0); i >= l; L = L + std::make_pair(--i, 0))
    {
        while (k <= r && L + R[k] != R[k])
        {
            sum -= R[k].second;
            ++cnt;
            modify(R[k].first, +1);
            ++k;
        }
        while (j != k && L + R[j] == L)
        {
            sum -= R[j].second;
            ++cnt;
            modify(R[j].first, -1);
            ++j;
        }
        ans += sum + cnt * L.second + query(L.first);
    }
    while (j != k)
        modify(R[j++].first, -1);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i != n; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        to[x].push_back(n + i);
        to[n + i].push_back(x);
        to[y].push_back(n + i);
        to[n + i].push_back(y);
    }
    s.init();
    build(1, 0);
    cdq(1, n);
    std::cout << ans / 2 << std::endl;
    return 0;
}