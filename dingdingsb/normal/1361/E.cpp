// Problem: CF1361E James and the Chase
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1361E
// Memory Limit: 250 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=1e5+100;
int t,n,m;
vector<int>e[N];
bool vis[N],ins[N];
mt19937 rnd(random_device{}());
#define rd(l,r) uniform_int_distribution<int>(l,r)(rnd)
bool ans;
void dfs1(int u){
	vis[u]=ins[u]=1;
	for(auto v:e[u]){
		if(!vis[v])dfs1(v);
		else if(!ins[v])ans=0;
	}
	ins[u]=0;
}
bool dp[N];
int dep[N],cha[N],fr[N];
void chk(int&x,int y){
	if(!y)return;
	if(!x)x=y;
	else if(dep[x]>dep[y])x=y;
}
void dfs2(int u){
	vis[u]=1;
	for(auto v:e[u]){
		if(!vis[v])dep[v]=dep[u]+1,dfs2(v),chk(fr[u],fr[v]);
		else cha[v]--,cha[u]++,chk(fr[u],v);
	}
}
void dfs3(int u){
	vis[u]=1;
	for(auto v:e[u])
		if(!vis[v])dfs3(v),cha[u]+=cha[v];
}
void dfs4(int u){
	vis[u]=1;
	if(cha[u]==1&&dp[fr[u]])dp[u]=1;
	for(auto v:e[u])
		if(!vis[v])dfs4(v);
}
void solve(){
	read(n,m);
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1,u,v;i<=m;i++)
		read(u,v),e[u].pb(v);
	int SJYAKIOI=100;
	while(SJYAKIOI--){
		int u=rd(1,n);
		for(int i=1;i<=n;i++)vis[i]=0,ins[i]=0;
		ans=1;dfs1(u);
		for(int i=1;i<=n;i++)if(!vis[i])ans=0;
		if(!ans)continue;
		for(int i=1;i<=n;i++)fr[i]=0,cha[i]=0;
		for(int i=1;i<=n;i++)vis[i]=0;
		dfs2(u);
		for(int i=1;i<=n;i++)vis[i]=0;
		dfs3(u);
		for(int i=1;i<=n;i++)vis[i]=dp[i]=0;
		dp[u]=1;
		dfs4(u);
		vector<int>ans;
		for(int i=1;i<=n;i++)if(dp[i])ans.pb(i);
		if(ans.size()*5<n)return puts("-1"),void();
		for(auto x:ans)write(x),pc(' ');pc('\n');
		return;
	}
	puts("-1");
}
signed main(){
	read(t);
	while(t--)solve();
}