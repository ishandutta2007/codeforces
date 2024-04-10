#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
#define ll long long
const int N=3004,mod=1e9+7;
int n,D,f[N][N],fac[N],inv[N];
vector<int>e[N];
void dfs(int x){
	for(int i=1;i<=n;i++)f[x][i]=1;
	for(auto v:e[x]){
		dfs(v);
		for(int i=1;i<=n;i++)f[x][i]=(ll)f[x][i]*f[v][i]%mod;
	}
	for(int i=1;i<=n;i++)f[x][i]=(f[x][i]+f[x][i-1])%mod;
}
inline int ksm(int x,int r){
	int ret=1;
	for(int i=0;(1<<i)<=r;i++){
		if((1<<i)&r)ret=(ll)ret*x%mod;
		x=(ll)x*x%mod;
	}
	return ret;
}
inline int lglr(int x){
	if(x<=n)return f[1][x];
	//$f(x)=\sum^n_{i=0}f(x_i)\prod^n_{j=0,j!=i}\frac{x-x_j}{x_i-x_j}$
	int ret=0,tmp=1;
	for(int i=0;i<=n;i++)tmp=(ll)tmp*(x-i)%mod;
	inv[0]=inv[1]=fac[0]=fac[1]=1;
	for(int i=2;i<=n;i++)fac[i]=(ll)fac[i-1]*i%mod;
	inv[n]=ksm(fac[n],mod-2);
	for(int i=n-1;i>1;i--)inv[i]=(ll)inv[i+1]*(i+1)%mod;
	for(int i=0;i<=n;i++)
		ret=((ll)((n-i)&1?mod-1:1)*f[1][i]%mod*tmp%mod*ksm(x-i,mod-2)%mod*inv[n-i]%mod*inv[i]+ret)%mod;
	return ret;
}
int main(){
	n=read();D=read();
	for(int i=2;i<=n;i++)e[read()].push_back(i);
	dfs(1);
	cout<<lglr(D); 
	return (0-0);
}