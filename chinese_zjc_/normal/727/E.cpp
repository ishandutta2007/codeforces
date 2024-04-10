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
const int base1 = 114514;
const int base2 = 1919810;
const int MOD1 = 998244353;
const int MOD2 = 1000000007;
int n, k, g, pow1[1000005], pow2[1000005], to[1000005];
std::string s, t[100005];
struct StringHash
{
    std::vector<int> hash1, hash2;
    int size;
    void init(const std::string &x)
    {
        hash1.assign(1, 0);
        hash2.assign(1, 0);
        size = x.size();
        pow1[0] = pow2[0] = 1;
        for (int i = 1; i <= (int)x.size(); ++i)
        {
            pow1[i] = pow1[i - 1] * base1 % MOD1;
            pow2[i] = pow2[i - 1] * base2 % MOD2;
        }
        for (int i = 0; i != (int)x.size(); ++i)
        {
            hash1.push_back((hash1.back() * base1 + x[i]) % MOD1);
            hash2.push_back((hash2.back() * base2 + x[i]) % MOD2);
        }
    }
    std::pair<int, int> RangeHash(int L, int R)
    {
        if (R <= L)
        {
            std::pair<int, int> tmp = RangeHash(L, size);
            return std::make_pair((hash1[R] + tmp.first * pow1[R]) % MOD1,
                                  (hash2[R] + tmp.second * pow2[R]) % MOD2);
        }
        return std::make_pair((hash1[R] + (MOD1 - hash1[L]) * pow1[R - L]) % MOD1,
                              (hash2[R] + (MOD2 - hash2[L]) * pow2[R - L]) % MOD2);
    }
} S;
std::pair<int, int> SingleHash(const std::string &x)
{
    std::pair<int, int> res;
    for (int i = 0; i != (int)x.size(); ++i)
    {
        res.first = (res.first * base1 + x[i]) % MOD1;
        res.second = (res.second * base2 + x[i]) % MOD2;
    }
    return res;
}
std::map<std::pair<int, int>, int> map;
std::set<int> app;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k >> s >> g;
    S.init(s);
    for (int i = 0; i != g; ++i)
        std::cin >> t[i], map[SingleHash(t[i])] = i;
    for (int i = 0; i != (int)s.size(); ++i)
    {
        std::map<std::pair<int, int>, int>::iterator j = map.find(S.RangeHash(i, (i + k) % s.size()));
        if (j == map.end())
            to[i] = -1;
        else
            to[i] = j->second;
    }
    for (int i = 0; i != k; ++i)
    {
        app.clear();
        for (int j = 0; j != n; ++j)
        {
            if (~to[j * k + i])
                app.insert(to[j * k + i]);
            else
                break;
        }
        if ((int)app.size() == n)
        {
            std::cout << "YES" << std::endl;
            for (int j = 0; j != n; ++j)
                std::cout << (" " + (j == 0)) << to[j * k + i] + 1;
            std::cout << std::endl;
            return 0;
        }
    }
    std::cout << "NO" << std::endl;
    return 0;
}