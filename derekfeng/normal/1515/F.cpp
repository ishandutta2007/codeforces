#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,X,u,v,ans[300004];
ll cur;
int L=1,R;
ll a[300004];
vector<int>g[300004],num[300004];
bool vis[300004];
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(vis[y])continue;
		dfs(y);
		if(a[x]+a[y]>=X){
			a[x]=a[x]+a[y]-X;
			ans[L++]=num[x][i];
		}else ans[R--]=num[x][i];
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&X);R=n-1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),cur+=a[i];
	if(cur<(ll)(n-1)*X)return puts("NO"),0;
	for(int i=1;i<=m;i++)scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u),num[u].push_back(i),num[v].push_back(i);
	dfs(1);
	puts("YES");
	for(int i=1;i<n;i++)printf("%d\n",ans[i]);
}