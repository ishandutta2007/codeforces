// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
int n, root, son[50005][10], fa[50005], cnt;
std::string s, l, r;
bool good[50005];
void insert(int &now, std::string::iterator cur, std::string::iterator end)
{
    if (!now)
        now = ++cnt;
    if (cur == end)
    {
        good[now] = true;
        return;
    }
    insert(son[now][int(*cur)], cur + 1, end);
}
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
};
mint work(std::string lim)
{
    bool now = false, lst = true;
    mint dp[2][50005][2][2];
    std::memset(dp[now], 0, sizeof(dp[now]));
    dp[now][root][1][0] = 1;
    for (int i = 0; i != n; ++i)
    {
        std::swap(now, lst);
        std::memset(dp[now], 0, sizeof(dp[now]));
        for (int j = 1; j <= cnt; ++j)
            for (int k = 0; k != 2; ++k)
                for (int l = 0; l != 2; ++l)
                    for (int o = 0; o <= std::min(k ? lim[i] : 9, 9); ++o)
                        dp[now][son[j][o]][k && o == lim[i]][l || good[son[j][o]]] += dp[lst][j][k][l];
    }
    mint res = 0;
    for (int i = 1; i <= cnt; ++i)
        res += dp[now][i][0][1];
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> s >> l >> r;
    n = l.size();
    for (auto &i : s)
        i -= '0';
    for (auto &i : l)
        i -= '0';
    for (auto &i : r)
        i -= '0';
    ++r.back();
    for (int i = n; --i && r[i] == 10;)
        if (r[i] == 10)
        {
            r[i] = 0;
            ++r[i - 1];
        }
    for (std::string::iterator i = s.begin(); i + n / 2 <= s.end(); ++i)
        insert(root, i, i + n / 2);
    std::queue<int> que;
    for (int i = 0; i != 10; ++i)
        if (int v = son[root][i])
        {
            fa[v] = root;
            que.push(v);
        }
        else
            son[root][i] = root;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = 0; i != 10; ++i)
            if (int v = son[now][i])
            {
                fa[v] = son[fa[now]][i];
                que.push(v);
            }
            else
                son[now][i] = son[fa[now]][i];
    }
    std::cout << work(r) - work(l) << std::endl;
    return 0;
}