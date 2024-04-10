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
int n, k, T, lst[22], nxt[200005][22], a[22], b[22][22], sum[1 << 22], v[200005], hasnum, ans;
string s;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k >> T >> s;
    fill(lst, lst + k, n);
    for (int i = n - 1; i >= 0; --i)
    {
        v[i] = s[i] - 'A';
        memcpy(nxt[i], lst, sizeof(lst));
        lst[v[i]] = i;
        hasnum |= 1 << v[i];
    }
    for (int i = 0; i < k; ++i)
    {
        cin >> a[i];
        sum[1 << i] = a[i];
    }
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        vector<int> tmp;
        for (int j = 0; j < k; ++j)
        {
            if (nxt[i][j] != n)
            {
                tmp.push_back(nxt[i][j]);
            }
        }
        sort(tmp.begin(), tmp.end());
        int g = 0;
        for (int j = 0; j < tmp.size(); ++j)
        {
            sum[g] += b[v[i]][v[tmp[j]]];
            sum[g | (1 << v[i])] -= b[v[i]][v[tmp[j]]];
            sum[g | (1 << v[tmp[j]])] -= b[v[i]][v[tmp[j]]];
            sum[g | (1 << v[i]) | (1 << v[tmp[j]])] += b[v[i]][v[tmp[j]]];
            g |= 1 << v[tmp[j]];
        }
    }
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < 1 << k; ++j)
        {
            if (j & (1 << i))
            {
                sum[j] += sum[j ^ (1 << i)];
            }
        }
    }
    for (int i = 0; i < 1 << k; ++i)
    {
        // cout << sum[i] << endl;
        if ((hasnum & i) != i || hasnum == i || sum[i] > T)
        {
            continue;
        }
        ++ans;
    }
    cout << ans << endl;
    return 0;
}