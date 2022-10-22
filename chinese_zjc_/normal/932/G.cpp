// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
struct mint
{
    unsigned v;
    mint(unsigned v_ = 0) : v(v_) {}
    mint operator-() const { return v ? MOD - v : *this; }
    mint &operator+=(const mint &X) { return (v += X.v) >= MOD ? v -= MOD : v, *this; }
    mint &operator-=(const mint &X) { return (v += MOD - X.v) >= MOD ? v -= MOD : v, *this; }
    mint &operator*=(const mint &X) { return v = 1llu * v * X.v % MOD, *this; }
    mint &operator/=(const mint &X) { return *this *= X.inv(); }
    mint pow(long long B) const
    {
        B %= MOD - 1;
        if (B < 0)
            B += MOD - 1;
        mint res = 1, A = *this;
        while (B)
        {
            if (B & 1)
                res *= A;
            B >>= 1;
            A *= A;
        }
        return res;
    }
    mint inv() const { return pow(MOD - 2); }
    friend mint operator+(const mint &A, const mint &B) { return mint(A) += B; }
    friend mint operator-(const mint &A, const mint &B) { return mint(A) -= B; }
    friend mint operator*(const mint &A, const mint &B) { return mint(A) *= B; }
    friend mint operator/(const mint &A, const mint &B) { return mint(A) /= B; }
    friend std::istream &operator>>(std::istream &A, mint &B) { return A >> B.v; }
    friend std::ostream &operator<<(std::ostream &A, const mint &B) { return A << B.v; }
    explicit operator bool() const { return v; }
} dp[1000005], sum[1000005];
int n, s[1000005], son[1000005][26], link[1000005], len[1000005], diff[1000005], slink[1000005], cnt, lst;
std::string t;
void push(int c)
{
    s[n++] = c;
    while (n - len[lst] - 2 < 0 || s[n - len[lst] - 2] != s[n - 1])
        lst = link[lst];
    if (son[lst][c])
        lst = son[lst][c];
    else
    {
        int now = ++cnt;
        son[lst][c] = now;
        len[now] = len[lst] + 2;
        do
            lst = link[lst];
        while (lst && !(son[lst][c] && s[n - len[lst] - 2] == s[n - 1]));
        link[now] = lst ? son[lst][c] : 2;
        diff[now] = len[now] - len[link[now]];
        slink[now] = link[now];
        if (diff[now] == diff[link[now]])
            slink[now] = slink[link[now]];
        lst = now;
    }
    for (int i = lst; i > 2; i = slink[i])
    {
        sum[i] = dp[n - len[slink[i]] - diff[i]];
        if (slink[i] != link[i])
            sum[i] += sum[link[i]];
        if (n % 2 == 0)
            dp[n] += sum[i];
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    link[++cnt] = 0;
    len[cnt] = -1;
    link[++cnt] = 1;
    slink[cnt] = 1;
    len[cnt] = 0;
    lst = 2;
    std::cin >> t;
    dp[0] = 1;
    // for (std::size_t i = 0; i << 1 != t.size(); ++i)
    //     std::cout << t[i] << t.rbegin()[i];
    // std::cout << std::endl;
    for (std::size_t i = 0; i << 1 != t.size(); ++i)
    {
        push(t[i] - 'a');
        // std::cout << lst << ' ' << len[lst] << ' ' << link[lst] << ' ' << slink[lst] << std::endl;
        push(t.rbegin()[i] - 'a');
        // std::cout << lst << ' ' << len[lst] << ' ' << link[lst] << ' ' << slink[lst] << std::endl;
        // std::cout << dp[n] << std::endl;
    }
    std::cout << dp[n] << std::endl;
    return 0;
}