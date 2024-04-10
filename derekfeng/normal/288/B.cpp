#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int n,K,ans;
int p[9];
bool F(int x,int dep){
	if(dep>K)return 0;
	if(x==1)return 1;
	return F(p[x],dep+1);
}
void dfs(int x){
	if(x>K){
		bool tmp=1;
		for(int i=1;i<=K&&tmp;i++)tmp&=F(p[i],0);
		if(tmp)ans++;
		return;
	}
	for(int i=1;i<=K;i++)p[x]=i,dfs(x+1);
}
int main(){
	scanf("%d%d",&n,&K);
	dfs(1);
	for(int i=K+1;i<=n;i++)ans=1ll*ans*(n-K)%MOD;
	printf("%d\n",ans);
}