#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;

vvi T;
vvi E;

void dfs(int u, int v, double t) {
	int sz = T[v].size(),q=0;
	if(u==-1) q = -1;
	for(int i = 0; i < T[v].size(); ++i) {
		int w = T[v][i], j = E[v][i];
		// cout << v << " AND " << w << endl;
		if(w == u) continue;

		++q;
		double d = fmod(t + q*2.0/sz,2);
		// cout << d << endl;
		if(d > 1) {
			printf("1 %d %d %d %.12lf\n",j,w+1,v+1,d-1);
			dfs(v,w,d-1);
		} else {
			printf("1 %d %d %d %.12lf\n",j,v+1,w+1,d);
			dfs(v,w,d+1);
		}
	}
}

int main() {
	int n;
	scanf("%d",&n);
	T = vvi(n);
	E = T;
	for(int i = 1; i < n; ++i) {
		int u,v;
		scanf("%d%d",&u,&v);
		T[--u].pb(--v);
		T[v].pb(u);
		E[u].pb(i);
		E[v].pb(i);
	}
	printf("%d\n",n-1);
	dfs(-1,0,0);
}