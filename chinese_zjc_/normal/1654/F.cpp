// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n;
std::string s;
std::string To_string(std::vector<int> v)
{
    std::string s = "";
    for (auto c : v)
    {
        s += c + 'a';
    }
    return s;
}
std::vector<int> dfs(int k, std::vector<int> x)
{
    if (k == 0)
        return x;
    std::vector<std::pair<int, int>> A, B;
    for (int i = 0; i != 1 << k >> 1; ++i)
    {
        A.push_back({x[i << 1], x[i << 1 | 1]});
        B.push_back({x[i << 1 | 1], x[i << 1]});
    }
    std::sort(A.begin(), A.end());
    A.erase(std::unique(A.begin(), A.end()), A.end());
    std::sort(B.begin(), B.end());
    B.erase(std::unique(B.begin(), B.end()), B.end());
    std::vector<int> l, r;
    for (int i = 0; i != 1 << k >> 1; ++i)
    {
        std::pair<int, int> L = {x[i << 1], x[i << 1 | 1]},
                            R = {x[i << 1 | 1], x[i << 1]};
        l.push_back(std::lower_bound(A.begin(), A.end(), L) - A.begin());
        r.push_back(std::lower_bound(B.begin(), B.end(), R) - B.begin());
    }
    std::vector<int> Lans = dfs(k - 1, l), Rans = dfs(k - 1, r);
    std::vector<int> Aans(1 << k), Bans(1 << k);
    for (int i = 0; i != 1 << k >> 1; ++i)
    {
        Aans[i << 1] = A[Lans[i]].first, Aans[i << 1 | 1] = A[Lans[i]].second;
        Bans[i << 1] = B[Rans[i]].first, Bans[i << 1 | 1] = B[Rans[i]].second;
    }
    return std::min(Aans, Bans);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> s;
    std::vector<int> a(1 << n);
    for (int i = 0; i != 1 << n; ++i)
        a[i] = s[i] - 'a';
    std::vector<int> res = dfs(n, a);
    for (int i = 0; i != 1 << n; ++i)
        std::cout << char(res[i] + 'a');
    std::cout << std::endl;
    return 0;
}