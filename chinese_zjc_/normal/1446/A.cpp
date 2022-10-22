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
int T, n, W, sum;
struct L
{
    int v, p;
    bool operator<(const L &__Val) const
    {
        return v > __Val.v;
    }
} a[200005];
vector<int> ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n >> W;
        ans.clear();
        sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i].v;
            a[i].p = i;
        }
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; ++i)
        {
            if (W >= a[i].v + sum)
            {
                sum += a[i].v;
                ans.push_back(a[i].p);
            }
        }
        if (sum < W / 2 + W % 2)
        {
            cout << -1 << endl;
            continue;
        }
        cout << ans.size() << endl;
        for (auto i : ans)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}