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
#include <cctype>
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
string Map[2], goal;
const int xx[] = {0, 1, 0, -1}, yy[] = {1, 0, -1, 0};
struct modint
{
    int v;
    modint()
    {
        v = 0;
    }
    modint(int V)
    {
        v = (V % MOD + MOD) % MOD;
    }
    modint operator+(const modint &__Val) const
    {
        modint res;
        res.v = v + __Val.v;
        if (res.v >= MOD)
        {
            res.v -= MOD;
        }
        return res;
    }
    modint operator-(const modint &__Val) const
    {
        return v - __Val.v;
    }
    modint operator*(const modint &__Val) const
    {
        modint res;
        res.v = v * __Val.v % MOD;
        return res;
    }
    modint &operator+=(const modint &__Val)
    {
        return *this = *this + __Val;
    }
    modint &operator-=(const modint &__Val)
    {
        return *this = *this - __Val;
    }
    modint &operator++()
    {
        return *this += 1;
    }
    modint &operator--()
    {
        return *this -= 1;
    }
    bool operator==(const modint &__Val) const
    {
        return v == __Val.v;
    }
    friend ostream &operator<<(ostream &ost, const modint &__Val)
    {
        return ost << __Val.v;
    }
};
modint ans, p[2005];
modint power(modint A, int B)
{
    modint res = 1;
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
struct str
{
    int len;
    modint hsh;
    str operator+(const str &__Val) const
    {
        return {len + __Val.len, hsh * p[__Val.len] + __Val.hsh};
    }
    str operator-(const str &__Val) const
    {
        return {len - __Val.len, hsh - __Val.hsh * p[len - __Val.len]};
    }
    bool operator==(const str &__Val) const
    {
        return len == __Val.len && hsh == __Val.hsh;
    }
    str(string __Val)
    {
        len = __Val.length();
        hsh = 0;
        for (int i = 0; i < (int)__Val.length(); ++i)
        {
            hsh = hsh * 128 + __Val[i];
        }
    }
    str(int A, modint B)
    {
        len = A;
        hsh = B;
    }
    str()
    {
        len = 0;
        hsh = 0;
    }
} C[4005];
str substr(str tmp[], int l, int r)
{
    if (l == 0)
    {
        return tmp[r];
    }
    return tmp[r] - tmp[l - 1];
}
void work(bool flag)
{
#define print                                        \
    for (int k = 0; k < 2; ++k)                      \
    {                                                \
        for (int i = 0; i < Map->length(); ++i)      \
        {                                            \
            for (int j = 0; j <= goal.length(); ++j) \
            {                                        \
                cout << dp[k][i][j] << ' ';          \
            }                                        \
            cout << endl;                            \
        }                                            \
        cout << endl;                                \
    }
    str A[2][4005], B[2][4005];
    modint dp[2][2005][2005];
    for (int i = 1; i <= Map->length(); ++i)
    {
        A[0][i] = Map[0].substr(0, i);
        B[0][i] = Map[1].substr(0, i);
    }
    reverse(Map[0].begin(), Map[0].end());
    reverse(Map[1].begin(), Map[1].end());
    for (int i = 1; i <= Map->length(); ++i)
    {
        A[1][i] = Map[0].substr(0, i);
        B[1][i] = Map[1].substr(0, i);
    }
    reverse(Map[0].begin(), Map[0].end());
    reverse(Map[1].begin(), Map[1].end());
    for (int i = 0; i < Map->length(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (substr(A[1], Map->length() - i, Map->length() - j) + substr(B[0], j + 1, i + 1) == C[(i - j + 1) << 1])
            {
                dp[1][i][(i - j + 1) << 1] = 1;
            }
            if (substr(B[1], Map->length() - i, Map->length() - j) + substr(A[0], j + 1, i + 1) == C[(i - j + 1) << 1])
            {
                dp[0][i][(i - j + 1) << 1] = 1;
            }
        }
        dp[0][i][0] = dp[1][i][0] = 1;
    }
    // print;
    if (goal[0] == Map[0][0])
    {
        dp[0][0][1] = 1;
    }
    if (goal[0] == Map[1][0])
    {
        dp[1][0][1] = 1;
    }
    if (goal[0] == Map[0][0] && goal[1] == Map[1][0])
    {
        dp[1][0][2] = 1;
    }
    if (goal[0] == Map[1][0] && goal[1] == Map[0][0])
    {
        dp[0][0][2] = 1;
    }
    for (int i = 1; i < Map->length(); ++i)
    {
        if (goal[0] == Map[0][i])
        {
            dp[0][i][1] += dp[0][i - 1][0];
        }
        if (goal[0] == Map[1][i])
        {
            dp[1][i][1] += dp[1][i - 1][0];
        }
        for (int j = 2; j <= goal.length(); ++j)
        {
            if (goal[j - 1] == Map[0][i])
            {
                dp[0][i][j] += dp[0][i - 1][j - 1];
            }
            if (goal[j - 1] == Map[1][i])
            {
                dp[1][i][j] += dp[1][i - 1][j - 1];
            }
            if (goal[j - 2] == Map[0][i] && goal[j - 1] == Map[1][i])
            {
                dp[1][i][j] += dp[0][i - 1][j - 2];
            }
            if (goal[j - 2] == Map[1][i] && goal[j - 1] == Map[0][i])
            {
                dp[0][i][j] += dp[1][i - 1][j - 2];
            }
        }
    }
    // print;
    for (int i = 0; i < Map->length(); ++i)
    {
        for (int j = 1; j <= goal.length(); ++j)
        {
            if (j == goal.length())
            {
                ans += dp[0][i][j] + dp[1][i][j];
                continue;
            }
            if ((j & 1) == (goal.length() & 1))
            {
                int v = (goal.length() - j) >> 1;
                // cout << i << ' ' << j << ' ' << i + v << endl;
                if (i + v >= Map->length() || v == 1)
                {
                    continue;
                }
                if (substr(A[0], i + 2, i + v + 1) + substr(B[1], Map->length() - i - v, Map->length() - i - 1) ==
                    substr(C, j + 1, goal.length()))
                {
                    // cout << 0 << ' ' << i << " " << j << endl;
                    ans += dp[0][i][j];
                }
                if (substr(B[0], i + 2, i + v + 1) + substr(A[1], Map->length() - i - v, Map->length() - i - 1) ==
                    substr(C, j + 1, goal.length()))
                {
                    // cout << 1 << ' ' << i << " " << j << endl;
                    ans += dp[1][i][j];
                }
            }
        }
    }
}
signed main()
{
    // ios::sync_with_stdio(false);
    cin >> Map[0] >> Map[1] >> goal;
    p[0] = 1;
    for (int i = 1; i <= 2000; ++i)
    {
        p[i] = p[i - 1] * 128;
    }
    if (goal.length() == 1)
    {
        for (int i = 0; i < (int)Map->length(); ++i)
        {
            if (goal[0] == Map[0][i])
            {
                ++ans;
            }
            if (goal[0] == Map[1][i])
            {
                ++ans;
            }
        }
        cout << ans << endl;
        return 0;
    }
    if (goal.length() == 2)
    {
        for (int i = 0; i < Map->length(); ++i)
        {
            if (goal[0] == Map[0][i])
            {
                for (int j = 0; j < 4; ++j)
                {
                    int x = 0 + xx[j], y = i + yy[j];
                    if (x < 0 || y < 0 || x >= 2 || y >= Map->length())
                    {
                        continue;
                    }
                    if (goal[1] == Map[x][y])
                    {
                        ++ans;
                    }
                }
            }
            if (goal[0] == Map[1][i])
            {
                for (int j = 0; j < 4; ++j)
                {
                    int x = 1 + xx[j], y = i + yy[j];
                    if (x < 0 || y < 0 || x >= 2 || y >= Map->length())
                    {
                        continue;
                    }
                    if (goal[1] == Map[x][y])
                    {
                        ++ans;
                    }
                }
            }
        }
        cout << ans << endl;
        return 0;
    }
    for (int i = 1; i <= goal.length(); ++i)
    {
        C[i] = goal.substr(0, i);
    }
    work(false);
    // cout << ans << endl;
    reverse(Map[0].begin(), Map[0].end());
    reverse(Map[1].begin(), Map[1].end());
    work(true);
    cout << ans << endl;
    return 0;
}