#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#define pb push_back
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
const int INF=1e9;

int n;
int c[200010];
vector<int> e[200010];

int dp[2][200010];
void dfs(int x,int f,int V){
	for (auto y: e[x]) if (y^f) dfs(y,x,V);
	if (c[x]^2){
		int fir=0,sec=0;
		for (auto y: e[x]){
			if (y==f) continue;
			int thi=min(dp[0][y],dp[1][y]+1);
			if (thi>=INF){fir=sec=INF;break;}
			if (thi>fir) sec=fir,fir=thi;
			else if (thi>sec) sec=thi;
		}
		if (fir+sec>=V) dp[0][x]=INF;
		else dp[0][x]=fir;
	}
	else dp[0][x]=INF;
	if (c[x]^1){
		int fir=0,sec=0;
		for (auto y: e[x]){
			if (y==f) continue;
			int thi=min(dp[0][y]+1,dp[1][y]);
			if (thi>=INF){fir=sec=INF;break;}
			if (thi>fir) sec=fir,fir=thi;
			else if (thi>sec) sec=thi;
		}
		if (fir+sec>=V) dp[1][x]=INF;
		else dp[1][x]=fir;
	}
	else dp[1][x]=INF;
}

bool check(int x){
	dfs(1,0,x);
	return dp[1][1]!=INF||dp[0][1]!=INF;
}

void init(){
	for (int i=1;i<=n;i++) e[i].clear();
}
void solve(){
	n=read();
	for (int i=1;i<=n;i++) c[i]=read();
	for (int i=1;i<n;i++){
		int u=read(),v=read();
		e[u].pb(v); e[v].pb(u);
	}
	int l=1,r=n,mid;
	while (l<r){
		mid=l+r>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l+2>>1);
}
int main()
{
	for (int T=read();T--;) init(),solve();
	return 0;
}