// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
const int tim = 4;
const int cnt = 4;
const int querys[tim] = {
    0b0011,
    0b0101,
    0b0101,
    0b0011};
bool query(std::vector<int> x)
{
    if (x.empty())
        return false;
    std::cout << '?' << ' ' << x.size();
    for (auto i : x)
        std::cout << ' ' << i;
    std::cout << std::endl;
    static std::string res;
    std::cin >> res;
    return res == "YES";
}
void submit(int x)
{
    std::cout << "! " << x << std::endl;
    static std::string res;
    std::cin >> res;
    if (res == ":)")
        exit(0);
}
void solve(std::vector<int> x)
{
    if (x.size() <= 2)
    {
        submit(x[0]);
        submit(x[1]);
    }
    std::vector<int> p[cnt];
    for (std::size_t i = 0; i != x.size(); ++i)
        p[i % cnt].push_back(x[i]);
    auto get = [&](int val)
    {
        std::vector<int> res;
        for (int i = 0; i != cnt; ++i)
            if (val >> i & 1)
                res.insert(res.end(), p[i].begin(), p[i].end());
        return res;
    };
    int res = 0;
    for (int i = 0; i != tim; ++i)
        res |= query(get(querys[i])) << i;
    int good = 0;
    for (int i = 0; i != cnt; ++i)
    {
        int lie = res;
        for (int j = 0; j != tim; ++j)
            lie ^= (querys[j] >> i & 1) << j;
        if (lie & lie >> 1)
            continue;
        good |= 1 << i;
    }
    assert(__builtin_popcount(good) <= 2);
    std::vector<int> nxt;
    for (int i = 0; i != cnt; ++i)
        if (good >> i & 1)
            nxt.insert(nxt.end(), p[i].begin(), p[i].end());
    solve(nxt);
}
int n;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    std::vector<int> a(n);
    std::iota(a.begin(), a.end(), 1);
    solve(a);
    return 0;
}