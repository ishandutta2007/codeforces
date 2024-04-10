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
int n, a[100005], sum;
vector<tuple<int, int, int>> ans;
void work(int x, int y, int z)
{
    int v = a[x] ^ a[y] ^ a[z];
    a[x] = v;
    a[y] = v;
    a[z] = v;
    ans.push_back({x, y, z});
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum ^= a[i];
    }
    if (!(n & 1) && sum)
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    work(1, 2, 3);
    for (int i = (n & 1 ? 3 : 4); i <= n - 2; i += 2)
    {
        work(i, i + 1, i + 2);
    }
    for (int i = n - 4; i > 0; i -= 2)
    {
        work(i, i + 1, i + 2);
    }
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << get<0>(i) << ' ' << get<1>(i) << ' ' << get<2>(i) << endl;
    }
    // for (int i = 1; i <= n; ++i)
    // {
    //     cout << a[i] << " \n"[i == n];
    // }
    return 0;
}