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
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int T, a[3], ans;
int A[3], Same[3][3], All;
ofstream out("NMSL.out");
void GET(int &res, const int &num)
{
    res = 0;
    for (int i = 1; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            ++res;
            if (i * i != num)
            {
                ++res;
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        ans = 1;
        for (int i = 0; i < 3; ++i)
        {
            cin >> a[i];
            GET(A[i], a[i]);
            ans *= A[i];
        }
        GET(All, __gcd(__gcd(a[0], a[1]), a[2]));
        for (int i = 0; i < 3; ++i)
        {
            for (int j = i + 1; j < 3; ++j)
            {
                GET(Same[i][j], __gcd(a[i], a[j]));
                ans -= Same[i][j] * (Same[i][j] - 1) / 2 * A[3 ^ i ^ j];
                ans += All * (All - 1) / 2 * (Same[i][j] - All);
            }
        }
        ans += All * (All - 1) + All * (All - 1) * (All - 2) * 4 / 6;
        ans -= (Same[0][1] - All) * (Same[1][2] - All) * (Same[0][2] - All);
        cout << ans << endl;
    }
    return 0;
}