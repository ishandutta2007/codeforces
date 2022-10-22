// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[500005], Lmax[500005], Rmax[500005], L[500005], R[500005];
long long ans;
std::vector<int> app[1000005];
int findL(int now) { return now == L[now] ? now : L[now] = findL(L[now]); }
int findR(int now) { return now == R[now] ? now : R[now] = findR(R[now]); }
long long calc(int v)
{
    long long res = 0;
    for (auto i : app[v])
        res += 1ll * (std::min(findR(i), Rmax[i]) - i) * (i - std::max(findL(i), Lmax[i]));
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], app[a[i]].push_back(i);
        ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int &j = Lmax[i] = i - 1; j >= 1 && a[j] <= a[i]; j = Lmax[j])
                ;
        for (int i = n; i; --i)
            for (int &j = Rmax[i] = i + 1; j <= n && a[j] < a[i]; j = Rmax[j])
                ;
        std::iota(L, L + 2 + n, 0);
        std::iota(R, R + 2 + n, 0);
        for (int i = 1000000; i; --i)
        {
            for (int j = i; j <= 1000000; j += i)
                ans -= calc(j);
            for (auto j : app[i])
            {
                L[j] = j - 1;
                R[j] = j + 1;
            }
            for (int j = i; j <= 1000000; j += i)
                ans += calc(j);
        }
        std::cout << ans << std::endl;
        for (int i = 1; i <= 1000000; ++i)
            app[i].clear();
    }
    return 0;
}