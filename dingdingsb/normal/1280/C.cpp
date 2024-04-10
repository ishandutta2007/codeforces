#include<bits/stdc++.h>
#define mp make_pair
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
#define lowbit(x) ((x)&-(x))
const int N=2e5+100;
int t,n,k;vector<pair<int,int>>e[N];
int sz[N];ll mx,mn;
void dfs(int u,int fa){
	sz[u]=1;
	for(auto E:e[u]){
		int v,w;tie(v,w)=E;
		if(v==fa)continue;
		dfs(v,u);sz[u]+=sz[v];
		mn+=1ll*w*(sz[v]&1);
		mx+=1ll*w*min(sz[v],n-sz[v]);
	}
}
signed main(){
	read(t);while(t--){
		read(k);n=k<<1;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1,u,v,w;i<n;i++)read(u,v,w),e[u].pb(mp(v,w)),e[v].pb(mp(u,w));
		mx=mn=0;dfs(1,0);writeln(mn,mx);
	}
}