#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2e5+50,mod=1e9+7;
int n,a[N],phi[N],mu[N],p[N],tot,mindiv[N],d[N],s1[N],s2[N],inv[N],b[N];bool inq[N];
vector<int>v[N],vv,di[N];
int sum,dat,rt,sz[N],ans;bool vis[N];
void findr(int x,int ff){
	int mx=0;sz[x]=1;
	for(int i=0,y;i<v[x].size();i++)
		if(!vis[y=v[x][i]]&&y!=ff)
			findr(y,x),sz[x]+=sz[y],mx=max(mx,sz[y]);
	mx=max(mx,sum-sz[x]);if(mx<dat)dat=mx,rt=x;
}
void dfs(int x,int ff){
	for(int i=0,y;i<v[x].size();i++)
		if(!vis[y=v[x][i]]&&y!=ff)
			d[y=v[x][i]]=d[x]+1,dfs(y,x);
}
void dfs2(int x,int ff){
	for(int i=0,y;i<di[x].size();i++){
		y=di[x][i];(s2[y]+=phi[x])%=mod;
		s1[y]=(s1[y]+1ll*d[x]*phi[x])%mod;
		if(!inq[y])vv.pb(y),inq[y]=1;
	}
	for(int i=0,y;i<v[x].size();i++)
		if(!vis[y=v[x][i]]&&y!=ff)dfs2(y,x);
}
void calc(int xx,int k){
	dfs2(xx,0);int dd=0;
	for(int i=0,x;i<vv.size();i++)
		x=vv[i],dd=(dd+1ll*s1[x]*s2[x]%mod*b[x])%mod;
	ans=(ans+2ll*k*dd)%mod;
	for(int i=0,x;i<vv.size();i++)x=vv[i],inq[x]=s1[x]=s2[x]=0;
	vv.clear();
}
void solve(int x){
	vis[x]=1;d[x]=0;dfs(x,0);calc(x,1);
	for(int i=0,y;i<v[x].size();i++)if(!vis[y=v[x][i]])
		calc(y,-1),sum=sz[y],dat=1e9,findr(y,x),solve(rt);
}
int read(){
	int x=0,c;
	while(!isdigit(c=getchar()));
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x;
}
int power(int x,int y){
	int z=1;
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;
	return z;
}
int main(){
	scanf("%d",&n);phi[1]=mu[1]=inv[1]=1;
	for(int i=2;i<=n;i++)inv[i]=mod-1ll*mod/i*inv[mod%i]%mod;
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j+=i)di[j].pb(i);
	for(int i=2;i<=n;i++){
		if(!mindiv[i])mindiv[i]=p[++tot]=i,phi[i]=i-1,mu[i]=-1;
		for(int j=1,y;j<=tot&&p[j]<=mindiv[i]&&(y=p[j]*i)<=n;j++)
			mindiv[y]=p[j],phi[y]=phi[i]*(i%p[j]?p[j]-1:p[j]),mu[y]=i%p[j]?-mu[i]:0;
	}
	for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)for(int j=0,y;j<di[i].size();j++)
        y=di[i][j],b[i]=(b[i]+1ll*y*inv[phi[y]]%mod*mu[i/y])%mod;
	for(int i=1,x,y;i<n;i++)
		x=a[read()],y=a[read()],
		v[x].pb(y),v[y].pb(x);
	sum=n;dat=1e9;findr(1,0);solve(rt);
	cout<<(1ll*ans*power(1ll*n*(n-1)%mod,mod-2)%mod+mod)%mod;
	return 0;
}