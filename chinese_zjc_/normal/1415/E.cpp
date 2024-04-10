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
int n, k, a[500005], now, ans, cnt;
vector<int> b, c[500005];
bool cmp(const int &A, const int &B)
{
    return A > B;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, cmp);
    ++k;
    for (int i = 1; i <= n; ++i)
    {
        ans += now;
        now += a[i];
        // cout << a[i] << endl;
        if (now < 0)
        {
            // cout << now << endl;
            b.push_back(now);
            for (int j = i + 1; j <= n; ++j)
            {
                b.push_back(a[j]);
            }
            sort(b.begin(), b.end());
            break;
        }
    }
    for (int i = 0; i < b.size(); ++i)
    {
        ans += b[i] * (int)c[i % k].size();
        c[i % k].push_back(b[i]);
    }
    cout << ans << endl;
    return 0;
}