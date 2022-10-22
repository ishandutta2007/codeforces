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
int n, a[100005], b[100005], ans, l, r;
multiset<int> s;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i)
    {
        s.insert(a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        multiset<int>::iterator it = s.upper_bound(a[i]);
        if (it == s.end())
        {
            s.erase(s.begin());
            continue;
        }
        else
        {
            s.erase(it);
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}