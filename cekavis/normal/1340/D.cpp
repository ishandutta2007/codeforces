#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
int n, k, num, cnt, h[N], d[N], e[N*2], pre[N*2];
pair<int,int> ans[N*3];
void add(int x, int y){ e[++num]=y, pre[num]=h[x], h[x]=num;}
void dfs(int u, int fa=0, int x=0){
	ans[++cnt]=make_pair(u, x);
	int y=x, z=d[u]-1;
	for(int i=h[u]; i; i=pre[i]) if(e[i]!=fa){
		if(y==k) ans[++cnt]=make_pair(u, y=x-1-z);
		dfs(e[i], u, ++y), --z;
		ans[++cnt]=make_pair(u, y);
	}
	if(fa && y!=x-1) ans[++cnt]=make_pair(u, x-1);
}
int main() {
	scanf("%d", &n);
	for(int i=1, x, y; i<n; ++i)
		scanf("%d%d", &x, &y), ++d[x], ++d[y], add(x, y), add(y, x);
	for(int i=1; i<=n; ++i) k=max(k, d[i]);
	dfs(1);
	printf("%d\n", cnt);
	for(int i=1; i<=cnt; ++i) printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}