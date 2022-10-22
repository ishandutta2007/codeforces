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
int n, T, ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n;
        ans = 0;
        while (n)
        {
            if (n & 1)
            {
                --n;
                ++ans;
            }
            else
            {
                if (n & 2 || n == 4)
                {
                    n >>= 1;
                    ans += n;
                }
                else
                {
                    --n;
                    ++ans;
                }
            }
            if (n == 0)
            {
                break;
            }
            if (n & 1)
            {
                --n;
            }
            else
            {
                if (n & 2 || n == 4)
                {
                    n >>= 1;
                }
                else
                {
                    --n;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}