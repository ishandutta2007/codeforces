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
int n, a[100005], b[100005], ans, cnt;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; i += 2)
    {
        b[i] = a[++cnt];
    }
    for (int i = 1; i <= n; i += 2)
    {
        b[i] = a[++cnt];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (b[i - 1] > b[i] && b[i] < b[i + 1])
        {
            ++ans;
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; ++i)
    {
        cout << b[i] << ' ';
    }
    cout << endl;
    return 0;
}