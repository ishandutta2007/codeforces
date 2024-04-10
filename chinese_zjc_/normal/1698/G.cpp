// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::string S;
unsigned long long s, a[1 << 18 | 1], b[1 << 17 | 1];
int n, pre = 1;
unsigned long long mul(unsigned long long A, unsigned long long B)
{
    unsigned long long res = 0;
    while (B)
    {
        if (B & 1)
            res ^= A;
        A <<= 1;
        B >>= 1;
        if (A >= 1llu << S.size() >> 1)
            A ^= s;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> S;
    while (!S.empty() && S.front() == '0')
        S.erase(0, 1), ++pre;
    while (!S.empty() && S.back() == '0')
        S.pop_back();
    if (S.empty())
        return std::cout << -1 << std::endl, 0;
    if (S == "1")
        return std::cout << pre << ' ' << pre + 1 << std::endl, 0;
    if (S == "11")
        return std::cout << pre << ' ' << pre + 1 << std::endl, 0;
    for (std::size_t i = 0; i != S.size(); ++i)
        s |= static_cast<unsigned long long>(S[i] == '1') << i;
    a[0] = 1;
    a[1] = 2;
    for (int i = 1; i <= 1 << 18; ++i)
        a[i] = mul(a[i - 1], a[1]);
    b[0] = 1;
    b[1] = a[1 << 18];
    for (int i = 1; i <= 1 << 17; ++i)
        b[i] = mul(b[i - 1], b[1]);
    std::map<unsigned long long, int> map;
    for (int i = 0; i != 1 << 18; ++i)
        map[a[i]] = i;
    for (unsigned long long i = 1; i <= 1 << 17; ++i)
    {
        std::map<unsigned long long, int>::iterator iter = map.find(b[i]);
        if (iter != map.end())
            return std::cout << pre << ' ' << pre + (i << 18) - iter->second << std::endl, 0;
    }
    std::cout << -1 << std::endl;
    return 0;
}