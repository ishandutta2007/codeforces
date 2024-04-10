#include<cstdio>
#include<vector>
using namespace std;
const int o=1.3e6;
int n,k,ls[o],rs[o],rt,cnt;vector<int> mn[o],mx[o],ans[o];
void ins(int&u,int val,int dep){
	if(!u) u=++cnt;
	if(dep<0) return;
	if((val>>dep)&1) ins(rs[u],val,dep-1);
	else ins(ls[u],val,dep-1);
}
void dfs(int u,int dep){
	if(dep==-1){mn[u]=mx[u]=vector<int>(1,0);ans[u]=vector<int>(1,o);return;}
	mn[u]=ans[u]=vector<int>(1<<(dep+1),o);mx[u]=vector<int>(1<<(dep+1),0);
	if(ls[u]){
		dfs(ls[u],dep-1);
		for(int i=0;i<(1<<dep);++i)
			mn[u][i]=min(mn[u][i],mn[ls[u]][i]),mx[u][i]=max(mx[u][i],mx[ls[u]][i]);
		for(int i=(1<<dep);i<(1<<(dep+1));++i)
			mn[u][i]=min(mn[u][i],mn[ls[u]][i^(1<<dep)]^(1<<dep)),mx[u][i]=max(mx[u][i],mx[ls[u]][i^(1<<dep)]^(1<<dep));
		for(int i=0;i<(1<<(dep+1));++i) ans[u][i]=min(ans[u][i],ans[ls[u]][i&((1<<dep)-1)]);
	}
	if(rs[u]){
		dfs(rs[u],dep-1);
		for(int i=0;i<(1<<dep);++i)
			mn[u][i]=min(mn[u][i],mn[rs[u]][i]^(1<<dep)),mx[u][i]=max(mx[u][i],mx[rs[u]][i]^(1<<dep));
		for(int i=(1<<dep);i<(1<<(dep+1));++i)
			mn[u][i]=min(mn[u][i],mn[rs[u]][i^(1<<dep)]),mx[u][i]=max(mx[u][i],mx[rs[u]][i^(1<<dep)]);
		for(int i=0;i<(1<<(dep+1));++i) ans[u][i]=min(ans[u][i],ans[rs[u]][i&((1<<dep)-1)]);
	}
	if(ls[u]&&rs[u]){
		for(int i=0;i<(1<<dep);++i)
			ans[u][i]=min(ans[u][i],mn[rs[u]][i]-mx[ls[u]][i]+(1<<dep));
		for(int i=(1<<dep);i<(1<<(dep+1));++i)
			ans[u][i]=min(ans[u][i],mn[ls[u]][i^(1<<dep)]-mx[rs[u]][i^(1<<dep)]+(1<<dep));
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int a;n--;ins(rt,a,k-1)) scanf("%d",&a);
	dfs(rt,k-1);
	for(int i=0;i<(1<<k);++i) printf("%d ",ans[rt][i]);
	return 0;
}