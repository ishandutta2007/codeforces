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
//#define int long long
typedef long long ll;
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
const int N=2e5+100;
int t,n;
vector<int>e[N];
bool vis[N],ins[N];
int dp[N];
bool dfs(int u){
	vis[u]=ins[u]=1;
	for(auto v:e[u]){
		if(ins[v])
			return 0;
		if(!vis[v]&&!dfs(v))
			return 0;
		chkmx(dp[u],dp[v]+(v>u));
	}
	ins[u]=0;
	return 1;
}
signed main(){
	read(t);
	while(t--){
		read(n);
		for(int i=1;i<=n;i++){
			dp[i]=1;vis[i]=ins[i]=0;e[i].clear();
			int k,x;read(k);
			while(k--)read(x),e[i].pb(x);
		}
		bool res=1;
		for(int i=1;i<=n&&res;i++)
			if(!vis[i])
				if(!dfs(i))
					res=0;
		if(!res)puts("-1");
		else write(*max_element(dp+1,dp+1+n)),putchar('\n');
	}
}