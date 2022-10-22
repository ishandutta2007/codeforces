// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, q, k, p[300005], a[300005], L[300005], R[300005], l[300005], r[300005], s[300005], c[300005], ansl, ansr;
int pos[300005];
std::vector<int> al[300005], app;
void cmax(int &A, int B) { A = std::max(A, B); }
void cmin(int &A, int B) { A = std::min(A, B); }
int min[1 << 21], tag[1 << 21];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void pushdown(int now)
{
    if (int &v = tag[now])
    {
        min[lson] += v;
        min[rson] += v;
        tag[lson] += v;
        tag[rson] += v;
        v = 0;
    }
}
void pushup(int now) { min[now] = std::min(min[lson], min[rson]); }
void build(int now = 1, int l = 0, int r = app.size() - 1)
{
    tag[now] = 0;
    if (l == r)
    {
        min[now] = 0;
        return;
    }
    build(lson, l, lmid);
    build(rson, rmid, r);
    pushup(now);
}
void add(int L, int R, int v, int now = 1, int l = 0, int r = app.size() - 1)
{
    if (r < L || R < l)
        return;
    if (L <= l && r <= R)
    {
        min[now] += v;
        tag[now] += v;
        return;
    }
    pushdown(now);
    add(L, R, v, lson, l, lmid);
    add(L, R, v, rson, rmid, r);
    pushup(now);
}
int find(int now = 1, int l = 0, int r = app.size() - 1)
{
    if (l == r)
        return l;
    pushdown(now);
    if (min[rson] < 0)
        return find(rson, rmid, r);
    return find(lson, l, lmid);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> q;
        std::fill(l, l + 2 + n, 0);
        std::fill(r, r + 2 + n, 1000000);
        for (int i = 1; i <= n; ++i)
            std::cin >> p[i], pos[p[i]] = i;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        for (int i = 1; i <= n; ++i)
            for (int &j = L[i] = i - 1; p[j] < p[i] && j >= 1; j = L[j])
                ;
        for (int i = n; i; --i)
            for (int &j = R[i] = i + 1; p[j] < p[i] && j <= n; j = R[j])
                ;
        for (int i = 1, j = pos[i]; i <= n; j = pos[++i])
        {
            if (a[j])
                cmax(l[j], a[j]);
            cmax(l[L[j]], l[j]);
            cmax(l[R[j]], l[j]);
        }
        for (int i = n, j = pos[i]; i; j = pos[--i])
        {
            if (a[j])
                cmin(r[j], a[j]);
            cmin(r[j], r[L[j]]);
            cmin(r[j], r[R[j]]);
        }
        // for (int i = 1; i <= n; ++i)
        //     std::cout << l[i] << ' ' << r[i] << std::endl;
        app.clear();
        k = 0;
        for (int i = 1; i <= n; ++i)
            if (!a[i])
            {
                // assert(l[i] <= r[i]);
                app.push_back(l[i]);
                app.push_back(r[i]);
                ++k;
                // std::cout << l[i] << ' ' << r[i] << std::endl;
            }
        for (int i = 1; i < k; ++i)
            std::cin >> s[i], app.push_back(s[i]);
        app.push_back(0);
        app.push_back(1000000);
        std::sort(app.begin(), app.end());
        app.erase(std::unique(app.begin(), app.end()), app.end());
        ansl = 0;
        ansr = app.size() - 1;
        for (int i = 1; i <= n; ++i)
            if (l[i] > r[i])
            {
                ansl = app.size() - 1;
                ansr = 0;
            }
        for (int i = 1; i <= n; ++i)
            if (!a[i])
            {
                al[std::lower_bound(app.begin(), app.end(), r[i]) - app.begin()]
                    .push_back(std::lower_bound(app.begin(), app.end(), l[i]) - app.begin());
            }
        for (int i = 1; i < k; ++i)
            ++c[std::lower_bound(app.begin(), app.end(), s[i]) - app.begin()];
        build();
        for (std::size_t i = 0; i != app.size(); ++i)
        {
            add(0, i, c[i]);
            for (auto j : al[i])
                add(0, j, -1);
            c[i] = 0;
            al[i].clear();
            if (min[1] < 0)
            {
                if (min[1] < -1)
                    ansl = app.size() - 1, ansr = 0;
                cmax(ansl, find());
                cmin(ansr, i);
                // std::cout << app[find()] << ' ' << app[i] << std::endl;
            }
        }
        ansl = app[ansl];
        ansr = app[ansr];
        for (int i = 1, d; i <= q; ++i)
        {
            std::cin >> d;
            // std::cout << ansl << ' ' << d << ' ' << ansr << ' ';
            std::cout << (ansl <= d && d <= ansr ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}