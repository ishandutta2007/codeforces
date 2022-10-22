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
const int N=400000+100;
int n,m,cnt;int a[N];
namespace G{
	int n;
	vector<int>e[N];
	int dfn[N],low[N],col[N],deg[N],cnt,cc;
	bool ins[N];stack<int>s;
	void dfs(int u){
		dfn[u]=low[u]=++cnt;s.push(u);ins[u]=1;
		for(auto v:e[u]){
			if(!dfn[v])
				dfs(v),chkmn(low[u],low[v]);
			else if(ins[v])chkmn(low[u],dfn[v]);
		}
		if(dfn[u]==low[u]){
			int tmp=-1;++cc;
			while(tmp!=u){
				tmp=s.top();
				s.pop();
				col[tmp]=cc;
				ins[tmp]=0;
			}
		}
	}
	void work(){
		for(int i=1;i<=n;i++)if(!dfn[i])dfs(i);
		for(int i=1;i<=n;i++)for(auto v:e[i])if(col[i]!=col[v])deg[col[v]]++;
		int cnt=0;for(int i=1;i<=cc;i++)if(deg[i]==0)cnt++;
		write(cnt);
	}
}
signed main(){
	read(n,m);
	//n=400000,m=1;
	auto M=vector<vector<char>>(n+2,vector<char>(m+2));
	auto id=vector<vector<int>>(n+2,vector<int>(m+2));
	auto down=vector<vector<int>>(n+2,vector<int>(m+2));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			M[i][j]=getchar();
			while(M[i][j]!='#'&&M[i][j]!='.')
				M[i][j]=getchar();
			//M[i][j]='#';
			if(M[i][j]=='#')
				id[i][j]=++cnt;
		}
	for(int i=1;i<=m;i++)read(a[i]);
	for(int j=1;j<=m;j++)
		for(int i=n;~i;i--){
			down[i][j]=down[i+1][j];
			if(id[i][j])
				down[i][j]=id[i][j];
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)if(id[i][j]){
			if(id[i-1][j])G::e[id[i][j]].pb(id[i-1][j]);
			if(down[i+1][j])G::e[id[i][j]].pb(down[i+1][j]);
			if(down[i][j-1])G::e[id[i][j]].pb(down[i][j-1]);
			if(down[i][j+1])G::e[id[i][j]].pb(down[i][j+1]);
		}
	}
	G::n=cnt;
	G::work();
}