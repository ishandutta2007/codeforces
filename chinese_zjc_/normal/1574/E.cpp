// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 998244353;
int n, m, k, l[1000005][2], cntl[3], c[1000005][2], cntc[3], t[2], pow2[1000005];
std::map<std::pair<int, int>, int> map;
void addl(int pos, int val)
{
    val &= 1;
    --cntl[bool(l[pos][0]) + bool(l[pos][1])];
    ++l[pos][val];
    ++cntl[bool(l[pos][0]) + bool(l[pos][1])];
}
void dell(int pos, int val)
{
    val &= 1;
    --cntl[bool(l[pos][0]) + bool(l[pos][1])];
    --l[pos][val];
    ++cntl[bool(l[pos][0]) + bool(l[pos][1])];
}
void addc(int pos, int val)
{
    val &= 1;
    --cntc[bool(c[pos][0]) + bool(c[pos][1])];
    ++c[pos][val];
    ++cntc[bool(c[pos][0]) + bool(c[pos][1])];
}
void delc(int pos, int val)
{
    val &= 1;
    --cntc[bool(c[pos][0]) + bool(c[pos][1])];
    --c[pos][val];
    ++cntc[bool(c[pos][0]) + bool(c[pos][1])];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    pow2[0] = 1;
    for (int i = 1; i <= 1000000; ++i)
        pow2[i] = pow2[i - 1] * 2 % MOD;
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        ++cntl[0];
    for (int i = 1; i <= m; ++i)
        ++cntc[0];
    for (int i = 0, x, y, v; i != k; ++i)
    {
        std::cin >> x >> y >> v;
        std::map<std::pair<int, int>, int>::iterator iter = map.find({x, y});
        if (iter != map.end())
        {
            dell(x, iter->second ^ y);
            delc(y, iter->second ^ x);
            --t[(x ^ y ^ iter->second) & 1];
            map.erase(iter);
        }
        if (v != -1)
        {
            map[{x, y}] = v;
            addl(x, v ^ y);
            addc(y, v ^ x);
            ++t[(x ^ y ^ v) & 1];
        }
        int ans = 0;
        if (!cntl[2])
            ans += pow2[cntl[0]];
        if (!cntc[2])
            ans += pow2[cntc[0]];
        ans -= !t[0] + !t[1];
        std::cout << (ans % MOD + MOD) % MOD << std::endl;
    }
    return 0;
}