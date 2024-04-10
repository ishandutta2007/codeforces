// Problem: C. Bakry and Partitioning
// Contest: Codeforces - Codeforces Round #746 (Div. 2)
// URL: https://codeforces.ml/contest/1592/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
int t,n,k,S;
int a[N];
int sum[N];
bool can[N];
bool ans;
vector<int>e[N];
void dfs(int u,int fa){
	sum[u]=a[u];
	for(auto v:e[u])if(v!=fa){
		dfs(v,u);
		if(can[u]&&can[v])ans=1;
		can[u]|=can[v];
		sum[u]^=sum[v];
	}
	can[u]|=(sum[u]==S);
}
signed main(){
	read(t);
	while(t--){
		read(n,k);S=0,ans=0;
		for(int i=1;i<=n;i++)
			read(a[i]),S^=a[i],e[i].clear(),can[i]=0;
		for(int i=1,u,v;i<n;i++)
			read(u,v),e[u].pb(v),e[v].pb(u);
		if(S==0)puts("YES");
		else{
			dfs(1,0);
			for(int i=2;i<=n;i++)
				if(sum[i]==0&&can[i])
					ans=1;
			if(ans&&2<=k-1)puts("YES");
			else puts("NO");
		}
	}
}