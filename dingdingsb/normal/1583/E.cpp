// Problem: E. Moment of Bloom
// Contest: Codeforces - Codeforces Round #749 (Div. 1 + Div. 2, based on Technocup 2022 Elimination Round 1)
// URL: https://codeforces.com/contest/1586/problem/E
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
const int N=3e5+100;
int n,m,q;vector<int>ans[N];
vector<int>e[N],g[N];
bool vis[N];int fa[N],dep[N];
void dfs(int u){
	vis[u]=1;
	for(auto v:g[u])if(!vis[v]){
		e[u].pb(v);fa[v]=u;dep[v]=dep[u]+1;
		dfs(v);
	}
}
int sum[N];
int lca(int x,int y){
	while(x!=y){
		if(dep[x]<dep[y])swap(x,y);
		x=fa[x];
	}
	return x;
}
int f[N];bool flag[N];
//f[u]
//flag
void dp(int u){
	if(e[u].size()==0)return;
	int tmp=0;
	for(auto v:e[u]){
		dp(v);
		f[u]+=f[v];
		if(!sum[v]&&flag[v])f[u]++;
		else if(sum[v])tmp++;
	}
	f[u]+=tmp/2;
	flag[u]=tmp%2;
}
signed main(){
	read(n,m);
	for(int i=1,u,v;i<=m;i++)
		read(u,v),g[u].pb(v),g[v].pb(u);
	dfs(1);
	read(q);
	for(int SJYAK=1;SJYAK<=q;SJYAK++){
		int a,b;read(a,b);
		int l=lca(a,b);
		while(a!=l)sum[a]^=1,ans[SJYAK].pb(a),a=fa[a];
		ans[SJYAK].pb(a);
		vector<int>tmp;
		while(b!=l)sum[b]^=1,tmp.pb(b),b=fa[b];
		reverse(tmp.begin(),tmp.end());
		for(auto kk:tmp)ans[SJYAK].pb(kk);
	}
	dp(1);
	if(!f[1]&&!flag[1]){
		puts("YES");
		for(int i=1;i<=q;i++){
			write(ans[i].size());pc('\n');
			for(auto x:ans[i])write(x),pc(' ');pc('\n');
		}
	}else{
		puts("NO");
		write(f[1]+flag[1]);
	}
}