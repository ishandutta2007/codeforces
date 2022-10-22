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
int n, k, l, r;
int get(int now)
{
    return now * (now + 1) / 2;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    r = n;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (get(mid) - (n - mid) < k)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    cout << n - l << endl;
    return 0;
}