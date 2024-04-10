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
int n, a[300005], T, l, r;
bool ans[300005], has[300005];
vector<int> pos[300005];
int dl[300005], L, R;
bool check(int now)
{
    L = 1;
    R = 0;
    fill(has + 1, has + 1 + n, false);
    for (int i = 1; i < now; ++i)
    {
        while (L <= R && a[dl[R]] > a[i])
        {
            --R;
        }
        dl[++R] = i;
    }
    for (int i = now; i <= n; ++i)
    {
        if (dl[L] == i - now)
        {
            ++L;
        }
        while (L <= R && a[dl[R]] > a[i])
        {
            --R;
        }
        dl[++R] = i;
        if (has[a[dl[L]]] || a[dl[L]] > n - now + 1)
        {
            return false;
        }
        has[a[dl[L]]] = true;
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            ans[i] = false;
            pos[i].clear();
        }
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            pos[a[i]].push_back(i);
        }
        ans[1] = true;
        for (int i = 1; i <= n; ++i)
        {
            if (pos[i].size() != 1)
            {
                ans[1] = false;
                break;
            }
        }
        if (!pos[1].empty())
        {
            l = 2;
            r = n;
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (check(mid))
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            fill(ans + l, ans + 1 + n, true);
        }
        for (int i = 1; i <= n; ++i)
        {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}