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
int lcm, gcd, l, r, ab, ans, abdgcd2;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> l >> r >> gcd >> lcm;
    ab = gcd * lcm;
    abdgcd2 = ab / gcd / gcd;
    for (int i = 1; i * i <= abdgcd2; ++i)
    {
        if (abdgcd2 % i == 0)
        {
            int a = i * gcd, b = ab / i / gcd;
            if (__gcd(a, b) == gcd && a * b == ab && l <= a && a <= r && l <= b && b <= r)
            {
                ++ans;
                if (a != b)
                {
                    ++ans;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}