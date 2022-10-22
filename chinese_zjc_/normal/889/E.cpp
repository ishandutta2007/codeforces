// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const double ULLMAX = 1.0 / ULLONG_MAX;
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 Rand(seed);
int n;
long long ans, a[200005];
std::map<long long, long long> map;
void cmax(long long &A, long long B) { A = std::max(A, B); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    map[a[1] - 1] = 0;
    for (int i = 2; i <= n; ++i)
        for (std::map<long long, long long>::iterator j = map.lower_bound(a[i]); j != map.end(); map.erase(j++))
        {
            cmax(map[j->first % a[i]], j->second + (i - 1) * (j->first / a[i] * a[i]));
            cmax(map[a[i] - 1], j->second + (i - 1) * ((j->first + 1) / a[i] * a[i] - a[i]));
        }
    for (auto i : map)
        cmax(ans, i.second + i.first * n);
    std::cout << ans << std::endl;
    return 0;
}