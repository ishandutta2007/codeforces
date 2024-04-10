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
const int N=3e5+100;
int n,m,d[N],vis[N],ci[N];
vector<pair<int,int>>e[N];
vector<int>ans;
void dfs(int u,int fa,int eid){
	vis[u]=1;
	for(auto E:e[u]){
		int v,w;tie(v,w)=E;
		if(vis[v])continue;
		dfs(v,u,w);
	}
	if(d[u]!=-1&&ci[u]!=d[u]){
		ci[fa]^=1;
		ans.pb(eid);
	}
}
signed main(){
	read(n,m);int rt=0,Xor=0;
	for(int i=1;i<=n;i++){
		read(d[i]);Xor^=d[i];
		if(d[i]==-1)rt=i;
	}
	if(!rt&&Xor)return puts("-1"),0;
	if(!rt)rt=1;
	for(int i=1,u,v;i<=m;i++)read(u,v),e[u].pb(mp(v,i)),e[v].pb(mp(u,i));
	dfs(rt,0,0);
	writeln(ans.size());
	for(auto x:ans)writeln(x);
}