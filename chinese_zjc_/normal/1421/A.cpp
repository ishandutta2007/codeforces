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
int T, a, b, ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> a >> b;
        ans = 0;
        for (int i = 31; i >= 0; --i)
        {
            int L = ans, R = ans ^ (1ll << i);
            if ((a ^ L) + (b ^ L) > (a ^ R) + (b ^ R))
            {
                ans = R;
            }
        }
        cout << ((a ^ ans) + (b ^ ans)) << endl;
    }
    return 0;
}