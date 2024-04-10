// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, k, a[505][505], L[250005], R[250005], sum[505], tot;
bool app[250005];
std::vector<int> l[505];
void cmin(int &A, int B) { A = std::min(A, B); }
void cmax(int &A, int B) { A = std::max(A, B); }
bool work()
{
    for (int i = n; i--;)
    {
        for (int i = 0; i <= n; ++i)
            l[i].clear();
        std::fill(L, L + n * n, n);
        for (int j = 0; j != n; ++j)
        {
            for (int k = 0; k != n; ++k)
            {
                int l = j - i, r = k;
                if (l > r)
                    std::swap(l, r);
                if (L[a[j][k]] != n)
                {
                    cmin(L[a[j][k]], l);
                    cmax(R[a[j][k]], r);
                }
                else
                {
                    L[a[j][k]] = l;
                    R[a[j][k]] = r;
                }
            }
        }
        // std::cout << i << std::endl;
        // for (int i = 0; i != n * n; ++i)
        //     std::cout << L[i] << ' ' << R[i] << std::endl;
        for (int j = 0; j != n * n; ++j)
            if (L[j] <= R[j] && L[j] >= 0 && R[j] < n - i)
                l[R[j] + 1].push_back(L[j]);
        std::fill(sum, sum + n + 1, 0);
        for (int j = 0; j <= n; ++j)
        {
            for (auto k : l[j])
                ++sum[k];
            for (int l = j, cnt = 0; l >= 0; --l)
            {
                cnt += sum[l];
                if (k - 1 <= tot - cnt && tot - cnt <= k)
                    return true;
            }
        }
    }
    return false;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
            std::cin >> a[i][j], app[--a[i][j]] = true;
    tot = std::count(app, app + n * n, true);
    if (tot <= k)
        return std::cout << k - tot << std::endl, 0;
    if (work())
        return std::cout << 1 << std::endl, 0;
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != i; ++j)
            std::swap(a[i][j], a[j][i]);
    if (work())
        return std::cout << 1 << std::endl, 0;
    std::cout << 2 << std::endl;
    return 0;
}