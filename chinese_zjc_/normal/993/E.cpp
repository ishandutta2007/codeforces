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
#include <complex>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, x, a[200005], ans[1 << 19], tot;
std::vector<int> pre, suf;
void work()
{
    std::vector<std::complex<double>> A, B;
    for (int i = 0; i != (int)pre.size(); ++i)
        A.push_back(pre[i]);
    for (int i = 0; i != (int)suf.size(); ++i)
        B.push_back(suf[i]);
    A.resize(1 << 19);
    B.resize(1 << 19);
    int inv[1 << 19];
    inv[0] = 0;
    for (int i = 1; i != 1 << 19; ++i)
        inv[i] = inv[i >> 1] >> 1 | (i & 1) << 18;
    std::vector<std::complex<double>> W;
    for (int i = 0; i <= 1 << 19; ++i)
        W.push_back(std::complex<double>(cos(PI / (1 << 18) * i), sin(PI / (1 << 18) * i)));
    // std::cout << std::fixed << std::setprecision(10);
    // for (int i = 0; i != 1 << 19; i += 1 << 12)
    //     std::cout << W[i] << std::endl;
    // for (int i = 0; i != 10; ++i)
    //     std::cout << A[i] << " \n"[i + 1 == 10];
    for (int i = 0; i != 1 << 19; ++i)
        if (i < inv[i])
            std::swap(A[i], A[inv[i]]), std::swap(B[i], B[inv[i]]);
    for (int i = 1; i != 1 << 19; i <<= 1)
    {
        for (int j = 0; j != 1 << 19; j += i << 1)
        {
            for (int k = 0; k != i; ++k)
            {
                std::complex<double> X = A[j | k], Y = A[i | j | k] * W[k * (1 << 18) / i];
                A[j | k] = X + Y;
                A[i | j | k] = X - Y;
                X = B[j | k], Y = B[i | j | k] * W[k * (1 << 18) / i];
                B[j | k] = X + Y;
                B[i | j | k] = X - Y;
            }
        }
    }
    for (int i = 0; i != 1 << 19; ++i)
        A[i] *= B[i];
    for (int i = 0; i != 1 << 19; ++i)
        if (i < inv[i])
            std::swap(A[i], A[inv[i]]), std::swap(B[i], B[inv[i]]);
    for (int i = 1; i != 1 << 19; i <<= 1)
    {
        for (int j = 0; j != 1 << 19; j += i << 1)
        {
            for (int k = 0; k != i; ++k)
            {
                std::complex<double> X = A[j | k], Y = A[i | j | k] * W[(1 << 19) - k * (1 << 18) / i];
                A[j | k] = X + Y;
                A[i | j | k] = X - Y;
                X = B[j | k], Y = B[i | j | k] * W[(1 << 19) - k * (1 << 18) / i];
                B[j | k] = X + Y;
                B[i | j | k] = X - Y;
            }
        }
    }
    for (int i = 0; i != 1 << 19; ++i)
    {
        A[i] *= pow(0.5, 19);
        B[i] *= pow(0.5, 19);
    }
    // for (int i = 0; i != 10; ++i)
    //     std::cout << A[i] << " \n"[i + 1 == 10];
    for (int i = 0; i != 1 << 19; ++i)
        ans[i] = round(A[i].real());
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> x;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        tot += a[i] = a[i] < x;
    }
    pre.push_back(0);
    suf.push_back(0);
    for (int i = 1, lst = 0; i <= n; ++i)
        if (a[i])
            pre.push_back(i - lst), lst = i;
    for (int i = n, lst = n + 1; i; --i)
        if (a[i])
            suf.push_back(lst - i), lst = i;
    work();
    int zero = 0;
    for (int i = 1; i <= n; ++i)
        if (!a[i])
        {
            int j = i;
            while (j <= n && !a[j])
                ++j;
            zero += (j - i) * (j - i + 1) / 2;
            i = j;
        }
    std::cout << zero << ' ';
    for (int i = 1; i <= n; ++i)
        std::cout << (tot - i + 2 >= 0 ? ans[tot - i + 2] : 0) << " \n"[i == n];
    return 0;
}