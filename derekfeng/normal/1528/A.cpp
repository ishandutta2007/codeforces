#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,l[200004],r[200004];
ll f[200004][2];
vector<int>g[200004];
void dfs(int x,int fa){
	f[x][0]=f[x][1]=0;
	for(auto y:g[x])if(y!=fa){
		dfs(y,x);
		f[x][0]+=max(f[y][0]+abs(l[x]-l[y]),f[y][1]+abs(l[x]-r[y]));
		f[x][1]+=max(f[y][0]+abs(r[x]-l[y]),f[y][1]+abs(r[x]-r[y]));
	}
}
void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)g[i].clear(),scanf("%d%d",&l[i],&r[i]);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	dfs(1,0);
	printf("%lld\n",max(f[1][0],f[1][1]));
}
int main(){
	int Tc;scanf("%d",&Tc);
	while(Tc--)sol();
}