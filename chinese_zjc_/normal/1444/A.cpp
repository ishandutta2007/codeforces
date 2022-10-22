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
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int T, a, b, tim[20], v[20], cnt, ans;
int gcd(int A, int B)
{
    return B ? gcd(B, A % B) : A;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> a >> b;
        int tmp = b;
        cnt = 0;
        for (int i = 2; i * i <= tmp; ++i)
        {
            if (tmp % i == 0)
            {
                v[++cnt] = i;
                tim[cnt] = 0;
                while (tmp % i == 0)
                {
                    ++tim[cnt];
                    tmp /= i;
                }
            }
        }
        if (tmp > 1)
        {
            v[++cnt] = tmp;
            tim[cnt] = 1;
        }
        ans = 0;
        for (int i = 1; i <= cnt; ++i)
        {
            int G = a;
            while (G % b == 0)
            {
                G /= v[i];
            }
            ans = max(ans, G);
        }
        cout << ans << endl;
    }
    return 0;
}