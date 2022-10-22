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
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
int T, n, k, a[100005], sum;
bool once;
bool check0()
{
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != k)
        {
            return false;
        }
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        sum = 0;
        once = false;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            if (a[i] == k)
            {
                once = true;
            }
            sum += a[i];
        }
        if (check0())
        {
            cout << 0 << endl;
            continue;
        }
        if (once || sum == k * n)
        {
            cout << 1 << endl;
            continue;
        }
        cout << 2 << endl;
    }
    return 0;
}