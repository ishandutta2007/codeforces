#include<bits/stdc++.h>
#define pb push_back
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
int n;vector<int>e[N];
vector<pair<int,int>>ans;
int deg[N],md;
void dfs(int u,int fa,int tim){
	ans.push_back({u,tim});
	int now=tim;
	for(auto v:e[u])if(v!=fa){
		if(now==md)
			ans.push_back({u,now-=deg[u]});
		dfs(v,u,++now);
		ans.push_back({u,now});
	}
	if(u!=1&&now!=tim-1)
		ans.push_back({u,tim-1});
}
signed main(){
	read(n);
	for(int i=1,u,v;i<n;i++)
		read(u,v),e[u].push_back(v),e[v].push_back(u),
		deg[u]++,deg[v]++;
	for(int i=1;i<=n;i++)chkmx(md,deg[i]);
	dfs(1,0,0);
	write(ans.size());putchar('\n');
	for(auto kk:ans)write(kk.first),putchar(' '),write(kk.second),putchar('\n');
}