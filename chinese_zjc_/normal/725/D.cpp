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
int n, you, LIMIT, r = 1, ans, killed;
struct team
{
    int v, w, need;
    bool operator<(const team &__Val) const
    {
        return need > __Val.need;
    }
} t[300005];
bool cmp(const team &A, const team &B)
{
    return A.v > B.v;
}
priority_queue<team> que;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> you >> LIMIT;
    for (int i = 1; i < n; ++i)
    {
        cin >> t[i].v >> t[i].w;
        t[i].need = t[i].w - t[i].v + 1;
    }
    sort(t + 1, t + n, cmp);
    while (t[r].v > you && r < n)
    {
        que.push(t[r++]);
    }
    ans = r;
    while (!que.empty() && que.top().need <= you)
    {
        ++killed;
        you -= que.top().need;
        que.pop();
        while (t[r].v > you && r < n)
        {
            que.push(t[r++]);
        }
        ans = min(ans, r - killed);
    }
    cout << ans << endl;
    return 0;
}