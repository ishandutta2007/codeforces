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
#include <random>
#include <chrono>
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, k, ans, len;
char lst;
string s;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    cin >> s;
    sort(s.begin(), s.end());
    lst = 'a';
    while (len < k)
    {
        string::iterator nxt = lower_bound(s.begin(), s.end(), lst);
        if (nxt == s.end())
        {
            break;
        }
        ans += *nxt - 'a' + 1;
        ++len;
        lst = *nxt + 2;
    }
    if (len == k)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}