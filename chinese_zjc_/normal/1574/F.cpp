// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
const int MOD = 998244353;
// #define debug
int n, m, k, in[300005], out[300005], siz[300005], fa[300005];
std::vector<std::pair<int, int>> e;
std::vector<int> F;
int find(int now) { return fa[now] == now ? now : fa[now] = find(fa[now]); }
void print(const std::vector<int> &x)
{
    for (auto i : x)
        std::cout << i << ' ';
    std::cout << std::endl;
}
int up(int x)
{
    int res = 1;
    while (res < x)
        res <<= 1;
    return res;
}
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = 1ll * res * A % MOD;
        B >>= 1;
        A = 1ll * A * A % MOD;
    }
    return res;
}
void NTT(std::vector<int> &X, int INTT = 1)
{
    static std::vector<std::size_t> rev;
    if (rev.size() != X.size())
    {
        rev.resize(X.size());
        for (std::size_t i = 0; i != rev.size(); ++i)
            rev[i] = rev[i >> 1] >> 1 | (i & 1) * rev.size() / 2;
    }
    for (std::size_t i = 0; i != X.size(); ++i)
        if (rev[i] < i)
            std::swap(X[rev[i]], X[i]);
    for (std::size_t i = 1; i != X.size(); i <<= 1)
    {
        long long W = power(3, (MOD - 1) + (MOD - 1) / i / 2 * INTT);
        for (std::size_t j = 0; j != X.size(); j += i * 2)
        {
            long long w = 1;
            for (std::size_t k = 0; k != i; ++k, w = w * W % MOD)
            {
                int A = X[j | k], B = w * X[i | j | k] % MOD;
                X[j | k] = (A + B) % MOD;
                X[i | j | k] = (A - B + MOD) % MOD;
            }
        }
    }
}
void INTT(std::vector<int> &X)
{
    NTT(X, -1);
    long long inv = power(X.size(), MOD - 2);
    for (auto &i : X)
        i = i * inv % MOD;
}
std::vector<int> operator*(std::vector<int> A, std::vector<int> B)
{
    std::vector<int> res(up(A.size() + B.size()));
    A.resize(res.size());
    B.resize(res.size());
    NTT(A);
    NTT(B);
    for (std::size_t i = 0; i != res.size(); ++i)
        res[i] = 1ll * A[i] * B[i] % MOD;
    INTT(res);
    return res;
}
std::vector<int> operator-(const int &A, const std::vector<int> &B)
{
    std::vector<int> res;
    for (auto i : B)
        res.push_back((MOD - i) % MOD);
    res[0] = (res[0] + A) % MOD;
    return res;
}
std::vector<int> operator*(const int &A, const std::vector<int> &B)
{
    std::vector<int> res;
    for (auto i : B)
        res.push_back(1ll * A * i % MOD);
    return res;
}
std::vector<int> operator-(const std::vector<int> &A, const std::vector<int> &B)
{
    std::vector<int> res(std::max(A.size(), B.size()));
    for (std::size_t i = 0; i != A.size(); ++i)
        res[i] = (res[i] + A[i]) % MOD;
    for (std::size_t i = 0; i != B.size(); ++i)
        res[i] = (res[i] - B[i] + MOD) % MOD;
    return res;
}
std::vector<int> INV(std::vector<int> X)
{
    std::vector<int> res(1, power(X.front(), MOD - 2));
    for (std::size_t i = 1; i != X.size(); res.resize(i <<= 1))
        res = (2 - std::vector<int>(X.begin(), X.begin() + (i << 1)) * res) * res;
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i)
        fa[i] = i;
    for (int i = 1, c, lst, x; i <= n; ++i)
    {
        std::cin >> c >> lst;
        for (int i = 1; i != c; ++i)
            std::cin >> x, e.push_back({lst, x}), lst = x;
    }
    std::sort(e.begin(), e.end());
    e.erase(std::unique(e.begin(), e.end()), e.end());
    for (auto i : e)
    {
        if (find(i.first) == find(i.second))
        {
            in[i.first] = INT_MIN;
            out[i.second] = INT_MIN;
        }
        ++out[i.first];
        ++in[i.second];
        fa[find(i.first)] = find(i.second);
    }
    for (int i = 1; i <= k; ++i)
        if (0 <= in[i] && in[i] <= 1 && 0 <= out[i] && out[i] <= 1)
            ++siz[find(i)];
        else
            siz[find(i)] = INT_MIN;
    F.assign(up(std::max(k + 1, m + 1)), 0);
    for (int i = 1; i <= k; ++i)
        if (siz[i] > 0)
            ++F[siz[i]];
    std::cout << INV(1 - F)[m] << std::endl;
    return 0;
}