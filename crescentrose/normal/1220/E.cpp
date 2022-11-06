#include <ctime>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <set>
#include <cmath>
using namespace std;
const int N = 200001;
vector<int> g[N];
vector<int>g1[N];
bool type[N];
int n, m;
long long f[N][2];
int v[N], s;
int low[N], dfn[N], instack[N], stack[N], belong[N], tot;
long long w[N];
void dfs(int x , int fa) {
    static int calc = 0;
    dfn[x] = low[x] = ++calc, stack[++ stack[0]] = x, instack[x] = 1;
    for (auto u:g[x])
        if (u!=fa){
            if (!dfn[u]){
                dfs(u, x);
                low[x] = min(low[x], low[u]);
            } else
                if (instack[u]){
                    low[x] = min(low[x], dfn[u]);
                }
        }
    if (low[x] == dfn[x]) {
        ++tot;
        int sum = 0;
        do{
            belong[stack[stack[0]]] = tot;
            instack[stack[stack[0]]] = 0;
            sum ++;
            w[tot] += v[stack[stack[0]]];
            stack[0] --;
        }while (stack[stack[0] + 1]!=x);
        type[tot] = (sum > 1);
    }
}
void dfs1(int x, int fa) {
    long long tmp = 0;
    for (auto u:g1[x])
        if (u != fa) {
            dfs1(u, x);
            type[x] |= type[u];
            if (type[u])
                tmp += f[u][1];
        }
    for (auto u:g1[x])
        if (u != fa) {
            if (type[u]) {
                f[x][0] = max(f[x][0], tmp - f[u][1] + f[u][0]);
            } else
                f[x][0] = max(f[x][0], tmp + f[u][0]);
        }
    f[x][0] += w[x];
    f[x][1] = tmp + w[x];
}
int main() {
    scanf("%d %d",&n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    for (int i = 1; i <= m ; i ++){
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    scanf("%d", &s);
    dfs(s, 0);
    for (int i = 1; i <= n; i ++)
        for (auto u:g[i])
            if (belong[i] != belong[u])
                g1[belong[i]].push_back(belong[u]);
    dfs1(belong[s], 0);
    cout << f[belong[s]][0] << endl;
    return 0;
}