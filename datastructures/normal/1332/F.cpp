#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
using namespace std;
int n,u[600005],v[600005],first[300005],nxt[600005],f[300005][2][2];
inline void dfs(int now,int fa){
	int num0=1,num1=1,num2=1;
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==fa)continue;
		dfs(v[i],now);
		num0=num0*(f[v[i]][0][0]+f[v[i]][0][1]+f[v[i]][1][0]+f[v[i]][1][1])%mod;
		num1=num1*(f[v[i]][0][0]+f[v[i]][1][0]+f[v[i]][1][1])%mod;
		num2=num2*(f[v[i]][1][0]+f[v[i]][1][1])%mod;
	}
	f[now][0][0]=num0;
	f[now][0][1]=num1;
	f[now][1][0]=num0;
	f[now][1][1]=(num1-num2+mod)%mod;
	return;
}
signed main(){
	cin>>n;
	for (int i=1;i<n;i++){
		scanf("%lld%lld",&u[i],&v[i]);
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	dfs(1,0);
	cout<<(f[1][1][0]+f[1][1][1]-1+mod)%mod<<endl;
	return 0;
}