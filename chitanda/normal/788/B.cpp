#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
int fa[1001000], du[1001000];
bool cc[1001000];
ll ans;

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void merge(int u, int v){
	u = find(u), v = find(v);
	fa[u] = v;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) fa[i] = i;
	int cnt = 0;
	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		if(u != v){
			du[u]++;
			du[v]++;
		}else cnt++;
		cc[u] = cc[v] = 1;
		merge(u, v);
	}
	bool flag = 1; int rt = 1;
	while(!cc[rt]) ++rt;
	for(int i = 1; i <= n; ++i){
		if(find(i) != find(rt) && cc[i]) flag = 0;
		ans += (ll)du[i] * (du[i] - 1) / 2;
	}
	ans += (ll)cnt * (m - cnt) + (ll)cnt * (cnt - 1) / 2;
	printf("%lld\n", ans * flag);
	return 0;
}