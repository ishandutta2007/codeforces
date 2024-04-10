#include<bits/stdc++.h>
#define int long long
const int N=2050,mod=1e9+7;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N*2];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}

int f[N],a[N],d,n,ans;
void dfs(int k,int fa,int r){
	f[k]=1;
	fore(k)if(_to!=fa&&a[_to]<a[r]&&a[r]/N-a[_to]/N<=d)
		dfs(_to,k,r),f[k]=f[k]*(1+f[_to])%mod
;}

main(){
	ios::sync_with_stdio(false);
	cin>>d>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]=a[i]*N+i;
	for(int i=1,x,y;i<n;i++)cin>>x>>y,add(x,y),add(y,x);
	for(int i=1;i<=n;i++)dfs(i,0,i),ans+=f[i];
	cout<<ans%mod;
}