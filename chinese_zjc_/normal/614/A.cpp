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
// #define debug
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
unsigned int l, r, k, a[64];
vector<int> ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> l >> r >> k;
    a[0] = 1;
    for (int i = 1; i < 64; ++i)
        a[i] = a[i - 1] * k;
    if (l <= 1)
    {
        ans.push_back(a[0]);
    }
    for (int i = 1; i < 64 && a[i] <= r && a[i] / k == a[i - 1]; ++i)
        if (l <= a[i])
            ans.push_back(a[i]);
    if (ans.empty())
        cout << -1;
    else
        for (auto i : ans)
            cout << i << ' ';
    cout << endl;
    return 0;
}