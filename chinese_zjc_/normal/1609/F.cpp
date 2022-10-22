// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#define popcount __builtin_popcountll
// #define debug
int n;
long long a[1000005], ans;
void solve(int l, int r)
{
    if (l == r)
    {
        ++ans;
        return;
    }
    int mid = (l + r) / 2;
    solve(l, mid);
    solve(mid + 1, r);
    // std::cout << l << ' ' << r << ' ' << ans << std::endl;
    int minl, maxl, minr, maxr;
    minl = maxl = mid;
    for (int i = mid, j = mid + 1; i >= l; --i)
    {
        minl = a[minl] < a[i] ? minl : i;
        maxl = a[maxl] > a[i] ? maxl : i;
        while (j <= r && a[minl] <= a[j] && a[j] <= a[maxl])
            ++j;
        if (popcount(a[minl]) == popcount(a[maxl]))
            ans += j - mid - 1;
    }
    minr = maxr = mid + 1;
    for (int i = mid + 1, j = mid; i <= r; ++i)
    {
        minr = a[minr] < a[i] ? minr : i;
        maxr = a[maxr] > a[i] ? maxr : i;
        while (j >= l && a[minr] < a[j] && a[j] < a[maxr])
            --j;
        if (popcount(a[minr]) == popcount(a[maxr]))
            ans += mid - j;
    }
    int t[64];
    memset(t, 0, sizeof(t));
    minl = maxl = mid;
    for (int i = mid, j = mid + 1, k = mid + 1, maxj = j, maxk = k; i >= l; --i)
    {
        minl = a[minl] < a[i] ? minl : i;
        maxl = a[maxl] > a[i] ? maxl : i;
        while (k <= r && a[minl] <= a[k])
        {
            maxk = a[maxk] > a[k] ? maxk : k;
            ++t[popcount(a[maxk])];
            ++k;
        }
        while (j < k && a[j] <= a[maxl])
        {
            maxj = a[maxj] > a[j] ? maxj : j;
            --t[popcount(a[maxj])];
            ++j;
        }
        ans += t[popcount(a[minl])];
    }
    // std::cout << ans << std::endl;
    memset(t, 0, sizeof(t));
    minl = maxl = mid;
    for (int i = mid, j = mid + 1, k = mid + 1, minj = j, mink = k; i >= l; --i)
    {
        minl = a[minl] < a[i] ? minl : i;
        maxl = a[maxl] > a[i] ? maxl : i;
        while (k <= r && a[k] <= a[maxl])
        {
            mink = a[mink] < a[k] ? mink : k;
            ++t[popcount(a[mink])];
            ++k;
        }
        while (j < k && a[minl] <= a[j])
        {
            minj = a[minj] < a[j] ? minj : j;
            --t[popcount(a[minj])];
            ++j;
        }
        // std::cout << j << ' ' << k << std::endl;
        ans += t[popcount(a[maxl])];
    }
    // std::cout << l << ' ' << r << ' ' << ans << std::endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    solve(1, n);
    std::cout << ans << std::endl;
    return 0;
}