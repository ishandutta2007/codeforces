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
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 1000000007;
class martix
{
public:
    int n, m, num[105][105];
    martix operator*(const martix &TMP) const
    {
        martix res;
        res.n = n;
        res.m = TMP.m;
        memset(res.num, 0, sizeof res.num);
        for (int i = 1; i <= res.n; ++i)
        {
            for (int j = 1; j <= res.m; ++j)
            {
                for (int k = 1; k <= m; ++k)
                {
                    res.num[i][j] = (res.num[i][j] + num[i][k] * TMP.num[k][j]) % MOD;
                }
            }
        }
        return res;
    }
} ans, cha;
int n, x, d[100005];
martix g(int now)
{
    martix res;
    res.n = res.m = now;
    for (int i = 1; i <= now; ++i)
    {
        res.num[i][i] = 1;
    }
    return res;
}
martix power(martix A, int B)
{
    martix res = g(100 + 1);
    while (B)
    {
        if (B & 1)
        {
            res = res * A;
        }
        A = A * A;
        B >>= 1;
    }
    return res;
}
void print(martix A)
{
    for (int i = 1; i <= A.n; ++i)
    {
        for (int j = 1; j <= A.m; ++j)
        {
            cout << A.num[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
    {
        cin >> d[i];
    }
    ans.n = 1;
    ans.m = 100 + 1;
    ans.num[1][100] = 1;
    cha.n = cha.m = 100 + 1;
    for (int i = 2; i <= 100; ++i)
    {
        cha.num[i][i - 1] = 1;
    }
    cha.num[100][100 + 1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        ++cha.num[100 - d[i] + 1][100];
    }
    ++cha.num[100 + 1][100 + 1];
    ans = ans * power(cha, x);
    cout << (ans.num[1][100] + ans.num[1][100 + 1]) % MOD << endl;
    return 0;
}