// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int BLOCK = 5;
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count() / 1000000;
std::mt19937 Rand(seed);
bool Prime(int x)
{
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
#ifdef debug
    std::cout << x << std::endl;
#endif
    return true;
}
int GET()
{
    static int x;
    do
        x = Rand() % (INT_MAX / 2);
    while (!Prime(x));
    return x;
}
const int MOD[BLOCK] = {GET(), GET(), GET(), GET(), GET()};
int lenx, lens;
std::string str;
struct node
{
    int v[BLOCK];
    int &operator[](const int &x) { return v[x]; }
    const int &operator[](const int &x) const { return v[x]; }
    node() : v() {}
    node(const int &x)
    {
        for (int i = 0; i != BLOCK; ++i)
            v[i] = x % MOD[i];
    }
    node operator+=(const node &val)
    {
        for (int i = 0; i != BLOCK; ++i)
            (v[i] += val[i]) >= MOD[i] ? v[i] -= MOD[i], void() : void();
        return *this;
    }
    node operator-=(const node &val)
    {
        for (int i = 0; i != BLOCK; ++i)
            (v[i] += MOD[i] - val[i]) >= MOD[i] ? v[i] -= MOD[i], void() : void();
        return *this;
    }
    node operator*=(const node &val)
    {
        for (int i = 0; i != BLOCK; ++i)
            v[i] = 1ll * v[i] * val[i] % MOD[i];
        return *this;
    }
    friend node operator+(const node &A, const node &B) { return node(A) += B; }
    friend node operator-(const node &A, const node &B) { return node(A) -= B; }
    friend node operator*(const node &A, const node &B) { return node(A) *= B; }
    friend bool operator==(const node &A, const node &B)
    {
        for (int i = 0; i != BLOCK; ++i)
            if (A[i] != B[i])
                return false;
        return true;
    }
} pow10[500005], x[500005], s[500005];
template <node *S>
node calc(int l, int r) { return S[r] - S[l] * pow10[r - l]; }
void check(int l, int m, int r)
{
    if (!(0 <= l && l < m && m < r && r <= lens))
        return;
    if (calc<s>(l, m) + calc<s>(m, r) == calc<x>(0, lenx))
    {
        std::cout << l + 1 << ' ' << m << std::endl
                  << m + 1 << ' ' << r << std::endl;
        exit(0);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    pow10[0] = 1;
    for (int i = 1; i <= 500000; ++i)
        pow10[i] = pow10[i - 1] * 10;
    std::cin >> str;
    lens = str.size();
    for (std::size_t i = 0; i != str.size(); ++i)
        s[i + 1] = s[i] * 10 + (str[i] - '0');
    std::cin >> str;
    lenx = str.size();
    for (std::size_t i = 0; i != str.size(); ++i)
        x[i + 1] = x[i] * 10 + (str[i] - '0');
    for (int i = 0; i != lens; ++i)
    {
        int l = 0, r = lenx;
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            if (calc<s>(i, i + mid) == calc<x>(0, mid))
                l = mid;
            else
                r = mid - 1;
        }
        check(i, i + lenx, i + lenx + lenx - l - 1);
        check(i, i + lenx, i + lenx + lenx - l);
        check(i - lenx + l + 1, i, i + lenx);
        check(i - lenx + l, i, i + lenx);
        check(i - lenx + 1, i, i + lenx - 1);
    }
    return 0;
}