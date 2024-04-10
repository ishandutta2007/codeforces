#include<bits/stdc++.h> 
using namespace std;

#define reg register
typedef long long ll;
typedef unsigned int ui;
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)

#define pb push_back
template <class T> inline void cmin(T &a,T b){ if(a>b) a=b; }
template <class T> inline void cmax(T &a,T b){ if(a<b) a=b; }

char IO;
int rd(){
	int s=0;
	int f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=3e5+10,P=998244353;

int n;

struct Edge{
	int to,nxt;
} e[N<<1];
int head[N],ecnt;
void AddEdge(int u,int v) {
	e[++ecnt]=(Edge){v,head[u]};
	head[u]=ecnt;
}
#define erep(u,i) for(reg int i=head[u];i;i=e[i].nxt)

ll dp[N][2][2],tmp[2][2];
void dfs(int u,int f) {
	dp[u][0][0]=dp[u][0][1]=1;
	erep(u,i) {
		int v=e[i].to;
		if(v==f) continue;
		dfs(v,u);
		memset(tmp,0,sizeof tmp);
		rep(a,0,1) rep(b,0,1) {
			rep(c,0,1) rep(d,0,1) {
				if(!b || !d) tmp[1][b]=(tmp[1][b]+dp[u][a][b]*dp[v][c][d])%P;
				if(c || !d) tmp[a][b]=(tmp[a][b]+dp[u][a][b]*dp[v][c][d])%P;
			}
		}
		memcpy(dp[u],tmp,sizeof dp[u]);
	}
}





int main(){
	n=rd();
	rep(i,2,n) {
		int u=rd(),v=rd();
		AddEdge(u,v),AddEdge(v,u);
	}
	dfs(1,0);
	ll ans=(P+dp[1][0][0]+dp[1][1][0]+dp[1][1][1]-1)%P;
	printf("%lld\n",ans);
}