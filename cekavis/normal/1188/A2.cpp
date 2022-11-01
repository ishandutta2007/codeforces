#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1005;
int n, num, root, d[N], h[N], e[N<<1], pre[N<<1], w[N<<1];
vector<vector<int>> ans;
void add(int x, int y, int z){ e[++num]=y, w[num]=z, pre[num]=h[x], h[x]=num;}
int dfs(int u, int fa=0, int wfa=0){
	int x=0, y=0, s=0;
	for(int i=h[u]; i; i=pre[i]) if(e[i]!=fa){
		(x?y:x)=dfs(e[i], u, w[i]);
		s+=w[i];
	}
	if(fa){
		if(d[u]==1) s=wfa, ans.push_back({u, root, wfa});
		else if(d[u]==2){ if(s!=wfa) puts("NO"), exit(0);}
		else if((wfa^s)&1) puts("NO"), exit(0);
		else
			ans.push_back({x, root, (wfa-s)/2}),
			ans.push_back({y, root, (wfa-s)/2}),
			ans.push_back({x, y, -(wfa-s)/2});
	}
	return x?x:u;
}
int main() {
	scanf("%d", &n);
	for(int i=1, x, y, z; i<n; ++i)
		scanf("%d%d%d", &x, &y, &z), add(x, y, z), add(y, x, z), ++d[x], ++d[y];
	for(int i=1; i<=n; ++i) if(d[i]==2 && w[h[i]]!=w[pre[h[i]]])
		return puts("NO"), 0;
	for(int i=1; i<=n; ++i) if(d[i]==1) root=i;
	dfs(root);
	puts("YES");
	printf("%d\n", (int)ans.size());
	for(auto i:ans) printf("%d %d %d\n", i[0], i[1], i[2]);
	return 0;
}