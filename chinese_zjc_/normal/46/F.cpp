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
bool flag;
int n, m, k, x[1005], y[1005], keyA[1005], personA[1005], faA[1005], keyB[1005], personB[1005], faB[1005];
std::vector<int> to[1005];
std::map<std::string, int> map;
int findA(int now) { return faA[now] == now ? now : faA[now] = findA(faA[now]); }
int findB(int now) { return faB[now] == now ? now : faB[now] = findB(faB[now]); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        faA[i] = faB[i] = i;
    for (int i = 1; i <= m; ++i)
        std::cin >> x[i] >> y[i];
    for (int i = 1; i <= k; ++i)
    {
        static std::string nam;
        static int x, s, t;
        std::cin >> nam >> x >> s;
        personA[map.insert({nam, map.size()}).first->second] = x;
        for (int i = 0; i != s; ++i)
            std::cin >> t, keyA[t] = x;
    }
    for (int i = 1; i <= k; ++i)
    {
        static std::string nam;
        static int x, s, t;
        std::cin >> nam >> x >> s;
        personB[map.insert({nam, map.size()}).first->second] = x;
        for (int i = 0; i != s; ++i)
            std::cin >> t, keyB[t] = x;
    }
    do
    {
        flag = false;
        for (int i = 1; i <= m; ++i)
            if ((findA(keyA[i]) == findA(x[i]) || findA(keyA[i]) == findA(y[i])) && findA(x[i]) != findA(y[i]))
                faA[findA(x[i])] = findA(y[i]), flag = true;
    } while (flag);
    do
    {
        flag = false;
        for (int i = 1; i <= m; ++i)
            if ((findB(keyB[i]) == findB(x[i]) || findB(keyB[i]) == findB(y[i])) && findB(x[i]) != findB(y[i]))
                faB[findB(x[i])] = findB(y[i]), flag = true;
    } while (flag);
    for (int i = 1; i <= m; ++i)
        if (findA(keyA[i]) != findA(keyB[i]) || findB(keyA[i]) != findB(keyB[i]))
            return std::cout << "NO" << std::endl, 0;
    for (int i = 0; i != (int)map.size(); ++i)
        if (findA(personA[i]) != findA(personB[i]) || findB(personA[i]) != findB(personB[i]))
            return std::cout << "NO" << std::endl, 0;
    std::cout << "YES" << std::endl;
    return 0;
}