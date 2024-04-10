#include<bits/stdc++.h>
typedef long long ll;
const int N=2e5+3;
int n,ls[N],rs[N],siz[N],t,rt,dfc;ll x,a[N],lz[N],dp[N],ans;
unsigned val[N];
inline int Rand(){return(unsigned)rand()*(unsigned)rand()*(unsigned)rand()%998244353u;}
inline void Up(int k){siz[k]=1+siz[ls[k]]+siz[rs[k]];}
inline void Down(int k){
	if(!lz[k])return;
	lz[ls[k]]+=lz[k],lz[rs[k]]+=lz[k];
	a[ls[k]]+=lz[k],a[rs[k]]+=lz[k];
	lz[k]=0;
}
void Merge(int k0,int k1,int&rt){
	if(!k0||!k1){rt=k0|k1;return;}
	if(val[k0]<val[k1]){
	  Down(k0);
	  Merge(rs[k0],k1,rt);
	  rs[k0]=rt,Up(k0);
	  rt=k0;
	}
	else{
	  Down(k1);
	  Merge(k0,ls[k1],rt);
	  ls[k1]=rt,Up(k1);
	  rt=k1;
	}
}
void Split(int k,int c,int&rt0,int&rt1){
	if(!k){rt0=rt1=0;return;}
	Down(k);
	if(c<=siz[ls[k]]){
	  Split(ls[k],c,rt0,rt1);
	  ls[k]=rt1,Up(k);
	  rt1=k;
	}
	else{
	  Split(rs[k],c-siz[ls[k]]-1,rt0,rt1);
	  rs[k]=rt0,Up(k);
	  rt0=k;
	}
}
int Findfirst(int c,int k,ll x){
	if(!k)return-1;
	Down(k);
	if(a[k]<=(c+siz[ls[k]]+1)*x){
	  int tmp=Findfirst(c,ls[k],x);
	  return~tmp?tmp:c+siz[ls[k]]+1;
	}return Findfirst(c+siz[ls[k]]+1,rs[k],x);
}
void Dfs(int k){
	if(!k)return;
	Down(k);
	Dfs(ls[k]),++dfc,dp[dfc]=dp[dfc-1]+a[k],ans=std::max(ans,dp[dfc]),Dfs(rs[k]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	  scanf("%lld",&x);
	  int j,rt0,rt1,u;
	  j=Findfirst(0,rt,x),j=~j?j:t+1;
	  Split(rt,j-1,rt0,rt1);
	  u=++t,val[u]=Rand(),siz[u]=1,a[u]=j*x;
	  if(rt1)lz[rt1]+=x,a[rt1]+=x;
	  Merge(rt0,u,rt0),Merge(rt0,rt1,rt);
	}
	Dfs(rt);
	printf("%lld\n",ans);
	return 0;
}