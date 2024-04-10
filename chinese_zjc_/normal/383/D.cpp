//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 1000000007;
int n, a[1005], ans;
struct array
{
    std::vector<int> pos, neg;
    int zer = 0;
    int &operator[](int x)
    {
        if (x == 0)
            return zer;
        if (x < 0)
        {
            x = -x - 1;
            if ((int)neg.size() <= x)
                neg.resize(x + 1);
            return neg[x];
        }
        else
        {
            x = +x - 1;
            if ((int)pos.size() <= x)
                pos.resize(x + 1);
            return pos[x];
        }
    }
    const int operator[](int x) const
    {
        if (x == 0)
            return zer;
        if (x < 0)
        {
            x = -x - 1;
            if ((int)neg.size() <= x)
                return 0;
            return neg[x];
        }
        else
        {
            x = +x - 1;
            if ((int)pos.size() <= x)
                return 0;
            return pos[x];
        }
    }
    const int low() const { return -(int)neg.size(); }
    const int high() const { return (int)pos.size(); }
};
void add(int &A, const int &B) { A = (A + B) % MOD; }
void solve(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    solve(l, mid);
    solve(mid + 1, r);
    array L[mid - l + 2], R[r - mid + 1], lsum, rsum;
    L[0][0] = 1;
    for (int i = 1; i <= mid - l + 1; ++i)
    {
        int x = a[mid - i + 1];
        for (int j = L[i - 1].low(); j <= L[i - 1].high(); ++j)
            add(L[i][j - x], L[i - 1][j]), add(L[i][j + x], L[i - 1][j]);
        for (int j = L[i].low(); j <= L[i].high(); ++j)
            add(lsum[j], L[i][j]);
    }
    R[0][0] = 1;
    for (int i = 1; i <= r - mid; ++i)
    {
        int x = a[mid + i];
        for (int j = R[i - 1].low(); j <= R[i - 1].high(); ++j)
            add(R[i][j - x], R[i - 1][j]), add(R[i][j + x], R[i - 1][j]);
        for (int j = R[i].low(); j <= R[i].high(); ++j)
            add(rsum[j], R[i][j]);
    }
    // std::cout << l << ' ' << r << std::endl;
    // std::cout << ans << std::endl;
    // for (int i = lsum.low(); i <= lsum.high(); ++i)
    //     std::cout << lsum[i] << " \n"[i == lsum.high()];
    // for (int i = rsum.low(); i <= rsum.high(); ++i)
    //     std::cout << rsum[i] << " \n"[i == rsum.high()];
    for (int i = std::min(lsum.neg.size(), rsum.pos.size()); i--;)
        add(ans, lsum.neg[i] * rsum.pos[i]);
    for (int i = std::min(lsum.pos.size(), rsum.neg.size()); i--;)
        add(ans, lsum.pos[i] * rsum.neg[i]);
    add(ans, lsum.zer * rsum.zer);
    // std::cout << ans << std::endl;
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