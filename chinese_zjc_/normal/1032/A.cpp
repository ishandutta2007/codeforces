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
#include <list>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int t[105], n, k, Max, has, tmp;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> tmp;
        ++t[tmp];
    }
    for (int i = 1; i <= 100; ++i)
    {
        if (t[i])
        {
            ++has;
        }
        Max = max(Max, (int)ceil(t[i] * 1.0 / k) * k);
    }
    cout << has * Max - n << endl;
    return 0;
}