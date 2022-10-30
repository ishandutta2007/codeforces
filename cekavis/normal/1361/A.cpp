#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 500005;
int n, m, a[N], vis[N];
vector<int> b[N], e[N];
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1, x, y; i<=m; ++i)
		scanf("%d%d", &x, &y), e[x].push_back(y), e[y].push_back(x);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), b[a[i]].push_back(i);
	for(int i=1; i<=n; ++i) for(int j:b[i]){
		for(int v:e[j]) vis[a[v]]=j;
		int x=1;
		while(vis[x]==j) ++x;
		if(x!=a[j]) return puts("-1"), 0;
	}
	for(int i=1; i<=n; ++i) for(int j:b[i]) printf("%d ", j);
	return 0;
}