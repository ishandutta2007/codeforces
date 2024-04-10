#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;char c=getchar();bool f=false;
	for(;!isdigit(c);c=getchar())f!=c=='-';
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	if(f)x=-x;
}
template<typename T ,typename ...Arg>
inline void read(T &x,Arg &...args){
	read(x);read(args...);
}
template<typename T>
inline void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
const int N=1e6+10;
int n,a[N];typedef long long ll;
ll f[N],sum,sz[N];vector<int>e[N];
void dfs1(int u,int fa,int dep){
	f[1]+=1ll*dep*a[u],sz[u]=a[u];
	for(auto v:e[u])if(v!=fa)
		dfs1(v,u,dep+1),
		sz[u]+=sz[v];
}
void dfs2(int u,int fa){
	for(auto v:e[u])
		if(v!=fa){
			f[v]=f[u]+sum-sz[v]-sz[v];
			dfs2(v,u);
		}
}
signed main(){
	read(n);
	for(int i=1;i<=n;i++)
		read(a[i]),sum+=a[i];
	for(int i=1,u,v;i<n;i++)
		read(u,v),e[u].push_back(v),e[v].push_back(u);
	dfs1(1,0,0);dfs2(1,0);
	ll ans=-1;
	for(int i=1;i<=n;i++)
		ans=max(ans,f[i]);
	write(ans);
}