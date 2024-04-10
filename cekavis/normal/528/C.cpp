#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005, M = 500005;
int n, m, num, cur[N], d[N], h[N], e[M], pre[M];
bool o, vis[M/2];
void add(int x, int y){
	e[++num]=y, pre[num]=h[x], h[x]=num;
	e[++num]=x, pre[num]=h[y], h[y]=num;
	++d[x], ++d[y];
}
void dfs(int u){
	for(int &i=h[u], v; i; i=pre[i]) if(!vis[i>>1]){
		vis[i>>1]=1, dfs(v=e[i]);
		if(o) printf("%d %d\n", u, v); else printf("%d %d\n", v, u);
		o^=1;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	num=1;
	for(int i=1, x, y; i<=m; ++i) scanf("%d%d", &x, &y), add(x, y);
	for(int i=1, x=0; i<=n; ++i) if(d[i]&1){ if(x) add(i, x), x=0; else x=i;}
	if(num/2&1) add(1, 1);
	printf("%d\n", num/2);
	memcpy(cur+1, h+1, n<<2);
	dfs(1);
	return 0;
}