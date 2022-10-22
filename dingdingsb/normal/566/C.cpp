// Problem: CF566C Logistical Questions
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF566C
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
const int N=2e5+100;
int n,w[N];vector<pair<int,int>>e[N];
int sz[N];bool vis[N];
double d[N],sum,sumd;pair<double,int>ans=mp(1e80,0);
void dfs(int u,int fa){
	sz[u]=1;
	for(auto E:e[u]){
		int v,w;tie(v,w)=E;
		if(v==fa||vis[v])continue;
		dfs(v,u);sz[u]+=sz[v];
	}
}
void getrt(int u,int fa,int tot,pair<int,int>&mn){
	int mx=0;
	for(auto E:e[u]){
		int v,w;tie(v,w)=E;
		if(v==fa||vis[v])continue;
		getrt(v,u,tot,mn);
		chkmx(mx,sz[v]);
	}
	chkmx(mx,tot-sz[u]);
	chkmn(mn,mp(mx,u));
}
void getd(int u,int fa,int dis,int o){
	sum+=pow(dis,1.5)*w[u];d[o]+=pow(dis,0.5)*1.5*w[u];
	for(auto E:e[u]){
		int v,w;tie(v,w)=E;
		if(v==fa)continue;
		getd(v,u,dis+w,o);
	}
}
void calc(int u){
	if(vis[u])return;
	pair<int,int>tmp=mp(0x3f3f3f3f,0);
	dfs(u,0);getrt(u,0,sz[u],tmp);
	int rt=tmp.se;sum=sumd=0;vis[rt]=1;
	for(auto E:e[rt]){
		int v,w;tie(v,w)=E;
		d[v]=0;getd(v,rt,w,v);sumd+=d[v];
	}
	chkmn(ans,mp(sum,rt));
	for(auto E:e[rt]){
		int v,w;tie(v,w)=E;
		if(sumd-2*d[v]<0)return calc(v);
	}
}
signed main(){
	read(n);
	for(int i=1;i<=n;i++)read(w[i]);
	for(int i=1,a,b,c;i<n;i++)read(a,b,c),e[a].eb(b,c),e[b].eb(a,c);
	calc(1);
	printf("%d %.9f",ans.se,ans.fi);
	return 0;
}