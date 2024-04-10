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
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
const int inf=0x3f3f3f3f3f3f3f3f;
const int N=610;
int n,m;vector<pair<int,int>>e[N];
int vis[N],dis[N];
void dij(int pos){
	for(int i=0;i<=n;i++)dis[i]=inf,vis[i]=0;
	for(auto [v,w]:e[pos])
		chkmn(dis[v],w);
	for(int o=1;o<=n;o++){
		int u=0;
		for(int i=1;i<=n;i++)if(!vis[i]&&dis[i]<dis[u])u=i;
		chkmn(dis[u%n+1],dis[u]+1);vis[u]=1;
		for(auto [v,w]:e[u]){
			v=(dis[u]+v-1)%n+1;
			chkmn(dis[v],dis[u]+w);
		}
	}
	for(int i=1;i<=n;i++)write(pos==i?0:dis[i]),putchar(' ');
	putchar('\n');
}
signed main(){
	read(n,m);
	for(int i=1,u,v,w;i<=m;i++)
		read(u,v,w),e[u+1].pb(mp(v+1,w));
	for(int i=1;i<=n;i++)dij(i);
}