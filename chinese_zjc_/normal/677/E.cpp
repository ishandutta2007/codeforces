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
const double log23 = log2(3);
int n;
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        A = A * A % MOD;
        B >>= 1;
    }
    return res;
}
struct node
{
    int num[4];
    node() { num[0] = num[1] = num[2] = num[3] = 0; }
    node(char c) { num[0] = num[1] = num[2] = num[3] = 0, num[c - '0'] = 1; }
    int &operator[](const int &X) { return num[X]; }
    const int &operator[](const int &X) const { return num[X]; }
    friend node operator+(const node &A, const node &B)
    {
        node res;
        for (int i = 0; i != 4; ++i)
            res[i] = A[i] + B[i];
        return res;
    }
    friend node operator-(const node &A, const node &B)
    {
        node res;
        for (int i = 0; i != 4; ++i)
            res[i] = A[i] - B[i];
        return res;
    }
    node &operator+=(const node &X)
    {
        for (int i = 0; i != 4; ++i)
            num[i] += X[i];
        return *this;
    }
    friend bool operator<(const node &A, const node &B)
    {
        if (A.num[0])
            return true;
        if (B.num[0])
            return false;
        return A.num[2] + A.num[3] * log23 < B.num[2] + B.num[3] * log23;
    }
    int asint() const
    {
        return num[0] ? 0 : power(2, num[2]) * power(3, num[3]) % MOD;
    }
};
std::vector<node> suml[2005], sumc[2005];
node ans = '0';
char c[2005][2005], d[2005][2005], e[2005][2005];
int len[2005][2005];
template <class T>
void min(T X, int x, int y, int vx, int vy)
{
    x += vx;
    y += vy;
    for (int i = 1; x >= 0 && x < n && y >= 0 && y < n && X[x][y] != '0'; ++i, x += vx, y += vy)
        len[x][y] = std::min(len[x][y], i);
}
template <class T>
void solve(T x)
{
    for (int i = 0; i != n; ++i)
        suml[i] = std::vector<node>(1);
    for (int i = 0; i != n; ++i)
        sumc[i] = std::vector<node>(1);
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
        {
            suml[i].push_back(suml[i].back() + x[i][j]);
            sumc[j].push_back(sumc[j].back() + x[i][j]);
        }
    memset(len, 0x3f, sizeof(len));
    for (int i = -1; i <= n; ++i)
        for (int j = -1; j <= n; ++j)
            if (i == -1 || j == -1 || i == n || j == n || x[i][j] == '0')
            {
                min(x, i, j, +1, 0);
                min(x, i, j, -1, 0);
                min(x, i, j, 0, -1);
                min(x, i, j, 0, +1);
            }
    // for (int i = 0; i != n; ++i, std::cout << std::endl)
    //     for (int j = 0; j != n; ++j)
    //         std::cout << x[i][j];
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
            if (x[i][j] != '0')
                ans = std::max(ans, suml[i][j + len[i][j]] - suml[i][j - len[i][j] + 1] +
                                        sumc[j][i + len[i][j]] - sumc[j][i - len[i][j] + 1] - x[i][j]);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    memset(d, '0', sizeof(d));
    memset(e, '0', sizeof(e));
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
        {
            std::cin >> c[i][j];
            if ((i + j) & 1)
                d[(i + j) / 2][(i - j + n) / 2] = c[i][j];
            else
                e[(i + j) / 2][(i - j + n) / 2] = c[i][j];
        }
    // for (int i = 0; i != n; ++i, std::cout << std::endl)
    //     for (int j = 0; j != n; ++j)
    //         std::cout << d[i][j];
    // for (int i = 0; i != n; ++i, std::cout << std::endl)
    //     for (int j = 0; j != n; ++j)
    //         std::cout << e[i][j];
    solve(c);
    solve(d);
    solve(e);
    std::cout << ans.asint() << std::endl;
    return 0;
}