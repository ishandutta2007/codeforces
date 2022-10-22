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
int T, n;
int work(int now)
{
    return (1 + now / 2) * (1 + (now - now / 2));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n;
        int l = 0, r = 100000;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (work(mid) >= n)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << l << endl;
    }
    return 0;
}