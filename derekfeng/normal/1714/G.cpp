#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
vector<piii>gr[200004];
int n,N,ans[200004];
ll sta[200004];
void dfs(int x,ll a,ll b){
	sta[++N]=b;
	ans[x]=upper_bound(sta+1,sta+N+1,a)-sta-2;
	for(auto [y,p]:gr[x])
		dfs(y,a+p.first,b+p.second);
	--N;
}
void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)gr[i].clear();
	for(int i=2;i<=n;i++){
		int p,a,b;scanf("%d%d%d",&p,&a,&b);
		gr[p].push_back({i,{a,b}});
	}
	dfs(1,0,0);
	for(int i=2;i<=n;i++)printf("%d ",ans[i]);puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)sol();
}