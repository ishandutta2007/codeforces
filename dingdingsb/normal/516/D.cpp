// Problem: CF516D Drazil and Morning Exercise
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF516D
// Memory Limit: 250 MB
// Time Limit: 3500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
#define int long long
typedef long long ll;
const int N=1e5+100;
int n,q;int L;
vector<pair<int,int>>e[N];
int disa[N],disb[N],a,b;bool vis[N];
int f[N];int ans;
void dfs1(int u,int*dis){
	vis[u]=1;
	for(auto [v,w]:e[u])if(!vis[v])dis[v]=dis[u]+w,dfs1(v,dis);
}
int tot,p[N],val[N];
void dfs2(int u,int fa){
	int l=0,r=tot,ans=0;//
	while(l<=r){
		int mid=(l+r)>>1;
		if(f[u]-f[p[mid]]>L)ans=mid,l=mid+1;
		else r=mid-1;
	}
	val[p[ans]]--;
	p[++tot]=u;val[u]++;
	for(auto [v,w]:e[u])if(v!=fa)dfs2(v,u);
	tot--;
}
void dfs3(int u,int fa){
	for(auto [v,w]:e[u])if(v!=fa)
		dfs3(v,u),val[u]+=val[v];
	chkmx(ans,val[u]);
}
signed main(){
	read(n);for(int i=1,u,v,w;i<n;i++)
		read(u,v,w),e[u].pb(mp(v,w)),e[v].pb(mp(u,w));
	dfs1(1,disb);for(int i=1;i<=n;i++)if(disb[a]<disb[i])a=i;
	memset(vis,0,sizeof vis);dfs1(a,disa);for(int i=1;i<=n;i++)if(disa[b]<disa[i])b=i;
	memset(vis,0,sizeof vis);disb[b]=0;dfs1(b,disb);
	for(int i=1;i<=n;i++)f[i]=max(disa[i],disb[i]);f[0]=-0x3f3f3f3f3f3f3f3f;
	int rt=1;for(int i=1;i<=n;i++)if(f[i]<f[rt])rt=i;
	read(q);while(q--){
		read(L);ans=0;
		memset(val,0,sizeof val);
		dfs2(rt,0);
		dfs3(rt,0);
		write(ans);
		putchar('\n');
	}
}