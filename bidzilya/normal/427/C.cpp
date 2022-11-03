#include <cstdio>
#include <cstdlib>
#include <cmath>
  
#include <vector>
#include <set>
#include <queue>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>
#include <algorithm>
using namespace std;
  
typedef long long ll;

const int modulo = 1e9 + 7;

vector<int> top, used, cmp;
vector<vector<int> > g, tg;
int n, m, cmps;

vector<int> cost;

vector<pair<int, int> > sol;

void top_sort(int v)
{
    used[v] = 1;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (!used[u])
            top_sort(u);
    }
    top.push_back(v);
}

void dfs(int v)
{
    cmp[v] = cmps;
    for (int i = 0; i < (int) tg[v].size(); ++i) {
        int u = tg[v][i];
        if (!cmp[u])
            dfs(u);
    }
}

int main()
{
 //   freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    cost.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &cost[i]);
    
    scanf("%d", &m);
    g.resize(n);
    tg.resize(n);
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        --v1; --v2;
        g[v1].push_back(v2);
        tg[v2].push_back(v1);
    }
    used.assign(n, 0);
    for (int i = 0; i < n; ++i)
        if (!used[i])
            top_sort(i);
    reverse(top.begin(), top.end());
    cmps = 0;
    cmp.assign(n, 0);
    for (int i = 0; i < n; ++i)
        if (!cmp[top[i]]) {
            ++cmps;
            dfs(top[i]);
        }
    sol.resize(cmps);
    for (int i = 0; i < cmps; ++i)
        sol[i].first = -1;
    for (int i = 0; i < n; ++i) {
        int c = cmp[i] - 1;
        if (sol[c].first == -1) {
            sol[c].first = cost[i];
            sol[c].second = 1;
        } else {
            if (cost[i] < sol[c].first) {
                sol[c].first = cost[i];
                sol[c].second = 1;
            } else if (cost[i] == sol[c].first) {
                ++sol[c].second;
            }
        }
    }
    
    ll min_sum = 0;
    for (int i = 0; i < cmps; ++i)
        min_sum += sol[i].first;
    int cnt = 1;
    for (int i = 0; i < cmps; ++i)
        cnt = (1LL * cnt * sol[i].second) % modulo;
    
    cout << min_sum << " " << cnt << endl;
    
    return 0;
}