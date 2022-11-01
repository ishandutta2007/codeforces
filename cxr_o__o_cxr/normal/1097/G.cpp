#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
#define ll long long
const int N=1e5+4,K=204,mod=1e9+7;
vector<int>e[N];
int n,k,ans,s[K][K],siz[N],cou[N],f[N][K];//k() 
void dfs(int x,int fa){
	siz[x]=f[x][0]=1;
	for(auto v:e[x]){
		if(v==fa)continue;
		dfs(v,x);
		for(int i=min(siz[x],k);i>=0;i--){
			for(int j=min(siz[v],k-i);j>=0;j--){// 
				cou[i+j]=((ll)f[x][i]*f[v][j]+cou[i+j])%mod;// 
				f[x][i+j]=((ll)f[x][i]*f[v][j]+f[x][i+j])%mod;
			}
		}
		for(int i=min(siz[v],k);i>=0;i--)f[x][i]=(f[x][i]+f[v][i])%mod;// 
		siz[x]+=siz[v];
	}
	for(int i=min(siz[x],k);i;i--)f[x][i]=(f[x][i]+f[x][i-1])%mod;// 
}
int main(){
//	freopen("1.in","r",stdin);
	n=read();k=read();
	s[1][1]=1;
	for(int i=2;i<=k;i++)
		for(int j=1;j<=i;j++)
			s[i][j]=((ll)s[i-1][j]*j+s[i-1][j-1])%mod;
	for(int i=1,u,v;i<n;i++){
		u=read();v=read();
		e[u].push_back(v);e[v].push_back(u);
	}
	dfs(1,0);
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=k;j++)cerr<<f[i][j]<<" ";cerr<<"\n";
//	}
//	cerr<<"\n";
//	for(int i=0;i<=k;i++)cerr<<cou[i]<<" ";cerr<<"\n";
	for(int i=1,fac=1;i<=k;i++){
		fac=(ll)fac*i%mod;
		ans=((ll)cou[i]*fac%mod*s[k][i]+ans)%mod;
	}
	cout<<ans;
	return (0-0);
}