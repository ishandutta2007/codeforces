// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::string ans;
long long n;
bool cmp(const std::string &A, const std::string &B) { return A.length() < B.length(); }
void cmin(std::string &A, const std::string &B) { A = std::min(A, B, cmp); }
std::map<long long, std::string> map;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    ans = std::to_string(n);
    for (long long i = 2; i * i <= n; ++i)
        for (long long j = i, k = 1; j <= n; j *= i, ++k)
            if (map.count(j))
                cmin(map[j], std::to_string(i) + "^" + std::to_string(k));
            else
                map[j] = std::min(std::to_string(i) + "^" + std::to_string(k), std::to_string(j), cmp);
    for (auto i : map)
    {
        long long A = n / i.first, B = n % i.first;
        cmin(ans, (A == 1 ? "" : (map.count(A) ? map[A] : std::to_string(A)) + "*") +
                      i.second +
                      (B ? "+" + (map.count(B) ? map[B] : std::to_string(B)) : ""));
    }
    std::cout << ans << std::endl;
    return 0;
}