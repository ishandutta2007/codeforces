// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const unsigned MOD = 1000000007;
int n, k, fa[1000005], max[1000005], sec[1000005], dep[1000005], heavy[1000005];
bool heavyv[1000005];
std::vector<int> to[1000005][2];
struct mint
{
    unsigned v;
    mint(unsigned v_ = 0) : v(v_) {}
    mint operator+=(const mint &x) { return (v += x.v) >= MOD ? v -= MOD : v, *this; }
    mint operator-=(const mint &x) { return (v += MOD - x.v) >= MOD ? v -= MOD : v, *this; }
    mint operator-() const { return v ? mint(MOD - v) : *this; }
    mint operator*=(const mint &x) { return v = 1llu * v * x.v % MOD, *this; }
    friend mint operator+(const mint &A, const mint &B) { return mint(A) += B; }
    friend mint operator-(const mint &A, const mint &B) { return mint(A) -= B; }
    friend mint operator*(const mint &A, const mint &B) { return mint(A) *= B; }
    friend std::istream &operator>>(std::istream &A, mint &B) { return A >> B.v; }
    friend std::ostream &operator<<(std::ostream &A, const mint &B) { return A << B.v; }
} a[1000005], ans;
struct twin
{
    mint way, sum;
    twin(mint way_ = 0, mint sum_ = 0) : way(way_), sum(sum_) {}
    twin &operator+=(const twin &x) { return way += x.way, sum += x.sum, *this; }
    twin &operator-=(const twin &x) { return way -= x.way, sum -= x.sum, *this; }
    twin &operator*=(const twin &x) { return sum = sum * x.way + way * x.sum, way *= x.way, *this; }
    friend twin operator+(const twin &A, const twin &B) { return twin(A) += B; }
    friend twin operator*(const twin &A, const twin &B) { return twin(A) *= B; }
    friend std::ostream &operator<<(std::ostream &A, const twin &B) { return A << '(' << B.way << ',' << B.sum << ')'; }
    mint operator()(const mint &x) const { return sum - x * way; }
};
void init(int now)
{
    max[now] = sec[now] = dep[now] = dep[fa[now]] + 1;
    for (int i = 0; i != 2; ++i)
    {
        for (const auto &j : to[now][i])
        {
            if (j == fa[now])
                continue;
            fa[j] = now;
            a[j] += a[now];
            init(j);
            if (max[j] > max[now])
            {
                sec[now] = max[now];
                max[now] = max[j];
                heavy[now] = j;
                heavyv[now] = i;
            }
            else if (max[j] > sec[now])
                sec[now] = max[j];
        }
    }
}
void dfs(int now, std::array<twin *, 2> &f, std::array<twin, 2> &g)
{
    bool &v = heavyv[now];
    static twin tmp;
    if (heavy[now])
    {
        ++f[0];
        ++f[1];
        dfs(heavy[now], f, g);
        f[0] -= v ^ 0;
        f[1] -= v ^ 1;
        if (k <= max[now] - dep[now])
            g[!v] -= f[!v][k];
        if (v != heavyv[heavy[now]])
            std::swap(f[0], f[1]), std::swap(g[0], g[1]);
        for (int i = 0; i <= sec[heavy[now]] - dep[now]; ++i)
        {
            f[v][i] += f[!v][i];
            f[!v][i] = twin();
        }
        g[v] += g[!v];
        g[!v] = twin();
        f[v][0] += twin(1, a[heavy[now]]);
        g[v] += twin(1, a[heavy[now]]);
    }
    for (const auto &i : to[now][v])
    {
        if (i == fa[now] || i == heavy[now])
            continue;
        std::array<twin *, 2> ff({new twin[(max[i] - dep[now]) * 2], new twin[(max[i] - dep[now]) * 2]});
        std::array<twin, 2> gg;
        dfs(i, ff, gg);
        for (int j = 1; j != std::min(k, max[i] - dep[now]); ++j)
            ff[v][j] += ff[!v][j - 1];
        ff[v][0] += twin(1, a[i]);
        tmp = g[v];
        for (int j = 0; j != std::min(k, max[i] - dep[now]); ++j)
        {
            ans += (tmp * ff[v][j])(a[now] + a[fa[now]]);
            if (k - j - 1 <= max[now] - dep[now])
                tmp -= f[v][k - j - 1];
        }
        for (int j = 0; j != std::min(k, max[i] - dep[now]); ++j)
            f[v][j] += ff[v][j], g[v] += ff[v][j];
    }
    for (const auto &i : to[now][!v])
    {
        if (i == fa[now])
            continue;
        std::array<twin *, 2> ff({new twin[(max[i] - dep[now]) * 2], new twin[(max[i] - dep[now]) * 2]});
        std::array<twin, 2> gg;
        dfs(i, ff, gg);
        for (int j = 1; j != std::min(k, max[i] - dep[now]); ++j)
            ff[!v][j] += ff[v][j - 1];
        ff[!v][0] += twin(1, a[i]);
        tmp = g[v];
        for (int j = 0; j != std::min(k, max[i] - dep[now]); ++j)
        {
            if (k - j - 1 <= max[now] - dep[now])
                tmp -= f[v][k - j - 1];
            ans += (tmp * ff[!v][j])(a[now] + a[fa[now]]);
        }
        tmp = g[!v];
        for (int j = 0; j != std::min(k, max[i] - dep[now]); ++j)
        {
            ans += (tmp * ff[!v][j])(a[now] + a[fa[now]]);
            if (k - j - 1 <= max[now] - dep[now])
                tmp -= f[!v][k - j - 1];
        }
        for (int j = 0; j != std::min(k, max[i] - dep[now]); ++j)
            f[!v][j] += ff[!v][j], g[!v] += ff[!v][j];
    }
    ans += (g[0] + g[1])(a[fa[now]]);
    // std::cerr << now << std::endl;
    // std::cerr << f[0] << ' ' << f[1] << std::endl;
    // for (int i = 0; i != max[now] - dep[now]; ++i)
    //     std::cerr << f[0][i] << ' ' << f[1][i] << std::endl;
    // std::cerr << g[0] << ' ' << g[1] << ' ' << ans << std::endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    ++k;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], ans += a[i];
    for (int i = 1, u, v, w; i != n; ++i)
    {
        std::cin >> u >> v >> w;
        to[u][w].push_back(v);
        to[v][w].push_back(u);
    }
    init(1);
    std::array<twin *, 2> f({new twin[max[1] * 2], new twin[max[1] * 2]});
    std::array<twin, 2> g;
    dfs(1, f, g);
    std::cout << ans << std::endl;
    return 0;
}