// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug1
const long long MOD = 998244353;
int n, m;
long long ans;
void print(const std::vector<long long> &x)
{
    for (const auto &i : x)
        std::cout << i << ' ';
    std::cout << std::endl;
}
int up_2(int x)
{
    return x & (x - 1) ? 1 << (32 - __builtin_clz(x)) : x;
}
long long power(long long A, long long B)
{
    long long res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
void NTT(std::vector<long long> &X, int INTT = 1)
{
    assert((X.size() & (X.size() - 1)) == 0);
    static std::vector<std::size_t> rev;
    if (rev.size() != X.size())
    {
        rev.resize(X.size());
        for (std::size_t i = 1; i != X.size(); ++i)
            rev[i] = rev[i >> 1] >> 1 | (i & 1) * X.size() >> 1;
    }
    for (std::size_t i = 0; i != X.size(); ++i)
        if (i < rev[i])
            std::swap(X[i], X[rev[i]]);
    for (int i = 1; i != int(X.size()); i <<= 1)
    {
        long long W = power(3, (MOD - 1) + INTT * (MOD - 1) / i / 2);
        for (int j = 0; j != int(X.size()); j += i << 1)
        {
            long long w = 1;
            for (int k = 0; k != i; ++k, w = w * W % MOD)
            {
                long long A = X[j | k], B = w * X[i | j | k] % MOD;
                X[j | k] = (A + B) % MOD;
                X[i | j | k] = (A - B + MOD) % MOD;
            }
        }
    }
}
void INTT(std::vector<long long> &X)
{
    long long inv = power(X.size(), MOD - 2);
    NTT(X, -1);
    for (auto &i : X)
        i = i * inv % MOD;
}
std::vector<long long> operator*(std::vector<long long> A, std::vector<long long> B)
{
    const int s = std::min(int(A.size() + B.size() - 1), n + n + 1);
    std::vector<long long> res(up_2(s));
    A.resize(res.size());
    B.resize(res.size());
    NTT(A);
    NTT(B);
    for (std::size_t i = 0; i != res.size(); ++i)
        res[i] = A[i] * B[i] % MOD;
    INTT(res);
    res.resize(std::min(s, n + 1));
    return res;
}
std::vector<long long> operator-(long long A, std::vector<long long> B)
{
    for (auto &i : B)
        i = MOD - i;
    B.front() = (B.front() + A) % MOD;
    return B;
}
std::vector<long long> operator+(std::vector<long long> A, std::vector<long long> B)
{
    std::vector<long long> res(n + 1);
    for (int i = 0; i <= n; ++i)
        res[i] = (A[i] + B[i]) % MOD;
    return res;
}
std::vector<long long> INV(std::vector<long long> X)
{
    X.resize(up_2(X.size()));
    std::vector<long long> res(1, power(X.front(), MOD - 2));
    for (std::size_t i = 1; i != X.size(); i <<= 1)
    {
        res.resize(i);
        res = (2 - std::vector<long long>(X.begin(), X.begin() + i + i) * res) * res;
    }
    res.resize(X.size());
    return res;
}
std::vector<long long> F(int m)
{
    if (m == 0)
    {
        std::vector<long long> res(n + 1);
        res[0] = 1;
        return res;
    }
    std::vector<long long> tmp = F(m / 2), A(n + 1), B(n + 1);
    for (int i = 0; i <= n; ++i)
        (i & 1 ? A : B)[i] = tmp[i];
    A[1] = (m + 1) / 2;
    tmp = INV(1 - A);
    ans = n & 1 ? tmp[n] : (2 * ans + tmp[n]) % MOD;
    for (int i = 1; i <= n; i += 2)
        ans = (ans + A[i] * tmp[n - i] % MOD * (i - 1)) % MOD;
    tmp = tmp * B * B;
    return tmp + A;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    F(m);
    std::cout << ans << std::endl;
    return 0;
}