#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1000100;
int n, tt;
int p[maxn], q[maxn], vis[maxn];
vector<int> g[maxn], cir[maxn];

void dfs(int t, int i){
	g[t].push_back(i);
	vis[i] = 1;
	if (!vis[p[i]]) dfs(t, p[i]);
}

void work(vector<int> V){
	for(int i = 0; i < V.size(); i++)
		q[V[i]] = V[(i + 1)% V.size()];
}

void odd(int t, int l){
	vector<int> V; V.clear();
	for(int i = 0; i < l / 2; i++){
		V.pb(g[t][i]);
		V.pb(g[t][i + 1 + l / 2]);
	}
	V.pb(g[t][l / 2]);
	work(V);
}

void eve(int t, int k, int l){
	vector<int> V; V.clear();
	for(int i = 0; i < l; i++){
		V.pb(g[t][i]);
		V.pb(g[k][i]);
	}
	work(V);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", p + i);
	}
	for(int i = 1; i <= n; i++)
		if (!vis[i]){
			++tt;
			dfs(tt, i);
			cir[g[tt].size()].push_back(tt);
		}
	for(int i = 1; i <= n; i++)
		if (i & 1){
			for(int j = 0; j < cir[i].size(); j++){
				odd(cir[i][j], i);
			}
		}else{
			if (cir[i].size() & 1) { printf("-1\n"); return 0; }
			for(int j = 0; j < cir[i].size(); j += 2)
				eve(cir[i][j], cir[i][j + 1], i);
		}
	for(int i = 1; i <= n; i++) printf("%d ", q[i]);
  return 0;
}