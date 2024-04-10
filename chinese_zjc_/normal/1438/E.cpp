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
int n, a[200005], sum[200005], ans;
struct L
{
    int v, p;
    bool operator<(const L &__Val) const
    {
        return v < __Val.v;
    }
};
bool check(int l, int r)
{
    return (a[l] ^ a[r]) == (sum[r - 1] - sum[l]);
}
void add(int l, int r)
{
    if (check(l, r))
    {
        ++ans;
    }
}
vector<L> tmp;
list<L> l;
list<L>::iterator to[200005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        tmp.push_back({a[i] * 2 - sum[i], i});
    }
    sort(tmp.begin(), tmp.end());
    for (auto i : tmp)
    {
        l.push_back(i);
    }
    for (auto i = l.begin(); i != l.end(); ++i)
    {
        to[i->p] = i;
    }
    l.erase(to[1]);
    for (int i = 1; i < n; ++i)
    {
        l.erase(to[i + 1]);
        for (auto j = l.rbegin(); j != l.rend(); ++j)
        {
            if (-sum[i] - a[i] <= j->v)
            {
                add(i, j->p);
            }
            else
            {
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}