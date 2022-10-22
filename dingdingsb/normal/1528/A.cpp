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
const int N=1e5+10;
int t,n,dp[N][2],l[N],r[N];
vector<int>e[N];
void dfs(int u,int fa){
	dp[u][0]=dp[u][1]=0;
	for(auto v:e[u])if(v!=fa){
		dfs(v,u);
		dp[u][0]+=max(dp[v][0]+abs(l[v]-l[u]),dp[v][1]+abs(r[v]-l[u]));
		dp[u][1]+=max(dp[v][0]+abs(l[v]-r[u]),dp[v][1]+abs(r[v]-r[u]));
	}
}
signed main(){
	read(t);while(t--){
		read(n);for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<=n;i++)read(l[i],r[i]);
		for(int i=1,u,v;i<n;i++)
			read(u,v),e[u].pb(v),e[v].pb(u);
		dfs(1,0);write(max(dp[1][0],dp[1][1]));putchar('\n');
	}
}