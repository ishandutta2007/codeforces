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
const int MOD = 19260817;
std::string operator+(std::string A, std::string B)
{
    std::string res(std::max(A.size(), B.size()) + 1, '0');
    std::reverse(A.begin(), A.end());
    std::reverse(B.begin(), B.end());
    for (int i = 0; i != (int)A.size(); ++i)
        res[i] += A[i] - '0';
    for (int i = 0; i != (int)B.size(); ++i)
        res[i] += B[i] - '0';
    for (int i = 0; i != (int)res.size(); ++i)
    {
        if (res[i] > '9')
        {
            res[i] -= 10;
            res[i + 1] += 1;
        }
    }
    while (res.size() > 1 && res.back() == '0')
        res.pop_back();
    std::reverse(res.begin(), res.end());
    return res;
}
std::string s;
int hash[1000005], p[1000005];
int get(int L, int R) { return (hash[R] - hash[L] * p[R - L] + MOD * MOD) % MOD; }
void check(int A, int B, int C)
{
    if (A <= 0 || B <= 0 || C <= 0)
        return;
    if ((get(0, A) + get(A, A + B)) % MOD != get(A + B, A + B + C))
        return;
    if (!((s[0] != '0' || A == 1) && (s[A] != '0' || B == 1) && (s[A + B] != '0' || C == 1)))
        return;
    if (s.substr(0, A) + s.substr(A, B) != s.substr(A + B, C))
        return;
    std::cout << s.substr(0, A) << '+' << s.substr(A, B) << '=' << s.substr(A + B, C) << std::endl;
    exit(0);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> s;
    // std::cout << s.substr(0, s.size() / 2) + s.substr(s.size() / 2) << std::endl;
    p[0] = 1;
    for (int i = 1; i <= (int)s.size(); ++i)
        hash[i] = (hash[i - 1] * 10 + s[i - 1] - '0') % MOD, p[i] = p[i - 1] * 10 % MOD;
    for (int i = s.size() / 3; i <= (int)s.size() / 2 + 1; ++i)
    {
        for (int j = i - 1; j <= i; ++j)
        {
            check(j, s.size() - i - j, i);
            check(s.size() - i - j, j, i);
        }
    }
    std::cout << "NOANSWER" << std::endl;
    return 0;
}