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
int query(std::string str)
{
    static int x;
    std::cout << str << std::endl;
    std::cin >> x;
    if (x < 1)
        exit(0);
    return x;
}
std::string ans;
int n;
signed main()
{
    std::ios::sync_with_stdio(false);
    int A = 300 - query(std::string(300, 'a')), B = 300 - query(std::string(300, 'b'));
    n = A + B;
    ans.assign(n, 'a');
    int lst = B;
    if (!lst)
        query(ans);
    for (int i = 0; i != n; ++i)
    {
        ans[i] ^= 'a' ^ 'b';
        if (query(ans) < lst)
            --lst;
        else
            ans[i] ^= 'a' ^ 'b';
    }
    if (lst)
        ans.back() ^= 'a' ^ 'b';
    query(ans);
    return -1;
}