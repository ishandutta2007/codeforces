#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;


const int N = 3005;
int d[N][N];

vvi G;
queue<int> Q;
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	G = vvi(n);
	for(int i = 0; i < m; ++i) {
		int u,v;
		scanf("%d%d",&u,&v);
		--u;--v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for(int u = 0; u < n; ++u) {
		fill(d[u],d[u]+n,0x7fffffff);
		d[u][u] = 0;
		Q.push(u);
		while(Q.size()) {
			int v = Q.front();
			Q.pop();
			for(int w : G[v]) {
				if(d[u][w] > d[u][v]+1) {
					d[u][w] = d[u][v]+1;
					Q.push(w);
				}
			}
		}
	}
	int s1,t1,l1;
	int s2,t2,l2;
	scanf("%d%d%d%d%d%d",&s1,&t1,&l1,&s2,&t2,&l2);
	--s1;--t1;--s2;--t2;
	if(d[s1][t1] > l1 || d[s2][t2] > l2) {
		printf("-1\n");
		return 0;
	}
	int need = d[s1][t1] + d[s2][t2];
	for(int a = 0; a < n; ++a) {
		for(int b = 0; b < n; ++b) {
			for(int i = 0; i < 2; swap(s1,t1),++i) {
				if(d[s1][a]+d[a][b]+d[b][t1] > l1) continue;
				if(d[s2][a]+d[a][b]+d[b][t2] > l2) continue;
				need = min(need,d[s1][a]+d[s2][a]+d[a][b]+d[b][t1]+d[b][t2]);
			}
		}
	}
	printf("%d\n",m-need);
	return 0;
}