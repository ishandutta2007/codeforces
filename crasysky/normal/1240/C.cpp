#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#include <set>
#define Pr pair <int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int maxn = 1000006;
const int P = 1e9 + 7;
vector < Pr > G[maxn];
long long f[maxn][2];
int k;
void dfs(int u, int fa){
    vector <long long> V;
    f[u][0] = f[u][1] = 0;
    for (int i = 0; i < G[u].size(); ++ i){
        int v = G[u][i].fi;
        if (v != fa){
            dfs(v, u);
            f[u][0] += f[v][0], f[u][1] += f[v][0];
            if (f[v][1] + G[u][i].se > f[v][0])
                V.push_back(-(f[v][1] + G[u][i].se - f[v][0]));
        }
    }
    sort(V.begin(), V.end());
    int s = V.size();
    for (int i = 0; i < min(s, k); ++ i)
        f[u][0] -= V[i];
    for (int i = 0; i < min(s, k - 1); ++ i)
        f[u][1] -= V[i];
}
int read(){
	int c = 0, f = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c * f;
}
int main(){
    int T = read();
    while (T --){
        int n = read();
        k = read();
        for (int i = 1; i <= n; ++ i)
            G[i].clear();
        for (int i = 1; i < n; ++ i){
            int u = read(), v = read(), c = read();
            G[u].push_back(mp(v, c));
            G[v].push_back(mp(u, c));
        }
        dfs(1, 0);
        cout << f[1][0] << endl;
    }
}