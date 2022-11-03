#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

const int max_n = 1e5 + 10;

vector<vector<int> > g;
int m, k, p;
int ch[max_n];
int hmax;

ll cs[2][max_n];

void dfs(int v, int h, int pr)
{
    hmax = max(hmax, h);
    ++ch[h];
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (u != pr)
            dfs(u, h + 1, v);
    }
}

ll sum2(int l, int r) 
{
    ll result = cs[1][r];
    if (l > 0) {
        result -= cs[1][l - 1];
        result -= cs[0][l - 1] * (r - l + 1);
    }
    return result;
}

ll sum1(int l, int r)
{
    ll result = cs[0][r];
    if (l > 0) {
        result -= cs[0][l - 1];
    }
    return result;
}

bool check(int k)
{
    if (k >= m) return false;
    for (int y1 = hmax, y2 = hmax; y2 > 0; --y2) {
        if (y1 > y2) y1 = y2;
        ll c = sum1(y1, y2);
        while (y1 > 1 && c < k) {
            --y1;
            c = sum1(y1, y2);
        }
        if (c >= k) {
            if (y1 == y2) {
                return true;
            }
            c = k - sum1(y1 + 1, y2);
            ll cost = sum2(y1, y2 - 1) - 1LL * (ch[y1] - c) * (y2 - y1);
            if (cost <= p) return true;
        }
    }
    return false;
}

int main()
{
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
 
    scanf("%d%d%d", &m, &k, &p);
    k = min(k, m - 1);
    g.resize(m);
    for (int i = 0; i < m - 1; ++i) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        --v1; --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    
    hmax = 0;
    dfs(0, 0, -1);
    
    cs[0][0] = 1;
    for (int i = 1; i <= hmax; ++i)
        cs[0][i] = ch[i] + cs[0][i - 1];
        
    cs[1][0] = 1;
    for (int i = 1; i <= hmax; ++i)
        cs[1][i] = cs[0][i] + cs[1][i - 1];
    
    int bl = 1, br = k, ba = 0;
    while (bl <= br) {
        int bm = (bl + br) >> 1;
        if (check(bm)) {
            ba = bm;
            bl = bm + 1;
        } else {
            br = bm - 1;
        }
    }
    printf("%d\n", ba);

    return 0;
}