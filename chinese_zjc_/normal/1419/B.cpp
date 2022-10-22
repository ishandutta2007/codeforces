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
int T, n, ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n;
        ans = 0;
        for (int i = 1; n >= ((1ll << i) - 1) * (1ll << i) / 2; ++i)
        {
            ++ans;
            n -= ((1ll << i) - 1) * (1ll << i) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}