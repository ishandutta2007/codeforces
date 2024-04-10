// Problem: D. Potion Brewing Class
// Contest: Codeforces - Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)
// URL: https://codeforces.com/contest/1654/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pb push_back
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
const int mod=998244353;
struct mint{
	int x;mint(int o=0){x=o;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}mint&operator/=(mint a){return*this*=(a^=mod-2);}
	friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}
	friend mint operator^(mint a, int b){return a^=b;}mint operator-(){return 0-*this;}
};
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
const int N=2e5+100;
int t,n;
int pr[N];
int mn[N],buc[N];
vector<tuple<int,int,int>>e[N];//uv xy
mint val[N];
void add(int x,int op){while(x>1)buc[pr[x]]+=op,x/=pr[x];}
void chk(int x){while(x>1)chkmx(mn[pr[x]],-buc[pr[x]]),x/=pr[x];}
void dfs(int u,int fa){
	for(auto E:e[u]){
		int v,x,y;
		tie(v,x,y)=E;
		if(v==fa)continue;
		add(x,1);add(y,-1);chk(y);
		dfs(v,u);
		add(x,-1);add(y,1);
	}
}
void calc(int u,int fa){
	for(auto E:e[u]){
		int v,x,y;
		tie(v,x,y)=E;
		if(v==fa)continue;
		val[v]=val[u]*x/y;
		calc(v,u);
	}
}
signed main(){
	for(int i=2;i<N;i++)if(!pr[i])
		for(int j=i;j<N;j+=i)pr[j]=i;
	read(t);
	while(t--){
		read(n);
		for(int i=1;i<=n;i++)e[i].clear(),buc[i]=mn[i]=0;
		for(int i=1,u,v,x,y;i<n;i++)
			read(u,v,x,y),
			e[u].pb(mt(v,y,x)),
			e[v].pb(mt(u,x,y));
		dfs(1,0);
		val[1]=1;
		for(int i=1;i<=n;i++)if(mn[i])val[1]*=(mint(i)^mn[i]);
		calc(1,0);
		mint ans=0;
		for(int i=1;i<=n;i++)ans+=val[i];
		writeln(ans.x);
	}
}