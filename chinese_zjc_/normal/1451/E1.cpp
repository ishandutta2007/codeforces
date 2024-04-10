//This Code was made by Chinese_zjc_.
#include <iostream>
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
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
using namespace std;
int a, b, c, d, e, n, num[1 << 16 | 5], ans;
int ask(int A, int B, string t)
{
    cout << t << ' ' << A << ' ' << B << endl;
    int v;
    cin >> v;
    return v;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    a = ask(1, 2, "AND");
    b = ask(1, 3, "AND");
    c = ask(2, 3, "AND");
    d = ask(1, 2, "OR");
    e = ask(1, 3, "OR");
    for (int i = 1; i < n; i <<= 1)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                for (int l = 0; l < 2; ++l)
                {
                    if ((j & k) == (true && (a & i)) &&
                        (j & l) == (true && (b & i)) &&
                        (k & l) == (true && (c & i)) &&
                        (j | k) == (true && (d & i)) &&
                        (j | l) == (true && (e & i)))
                    {
                        num[1] |= j * i;
                        num[2] |= k * i;
                        num[3] |= l * i;
                    }
                }
            }
        }
    }
    for (int i = 4; i <= n; ++i)
    {
        num[i] = num[1] ^ ask(1, i, "XOR");
    }
    cout << '!';
    for (int i = 1; i <= n; ++i)
    {
        cout << ' ' << num[i];
    }
    cout << endl;
    return 0;
}