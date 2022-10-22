// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
bool is(long long sum)
{
    long long v = std::sqrt(sum * 2) + 1;
    return v * (v - 1) / 2 == sum;
}
long long query(int l, int r)
{
    long long res;
    std::cout << '?' << ' ' << l << ' ' << r << std::endl;
    std::cin >> res;
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        int i, j, k;
        int l = 1, r = n - 2;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (query(1, mid + 1))
                r = mid;
            else
                l = mid + 1;
        }
        i = l;
        j = i + (query(i, n) - query(i + 1, n) + 1);
        k = j + (query(j, n) - query(j + 1, n));
        std::cout << "! " << i << ' ' << j << ' ' << k << std::endl;
    }
    return 0;
}