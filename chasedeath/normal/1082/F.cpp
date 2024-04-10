#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=510,INF=1e9+10;

int n,m;
int trie[N][10],cnt,c[N];
char s[N];
int dp[N][N][12];
int F[N][12],G[12],dep[N];

void dfs(int u) {
	for(int v:trie[u]) if(v) dep[v]=dep[u]+1,dfs(v);
	memset(F,63,sizeof F);
	rep(i,0,dep[u]) F[i][0]=c[u]*(dep[u]-i);
	for(int v:trie[u]) if(v) {
		rep(j,0,dep[u]) {
			rep(k,0,m) G[k]=F[j][k],F[j][k]=INF;
			rep(k,0,m) rep(d,0,m-k) cmin(F[j][k+d],G[k]+dp[v][j][d]);
		}
	}
	rep(d,0,dep[u]) {
		rep(i,0,m) dp[u][d][i]=INF;
		rep(i,0,m) {
			cmin(dp[u][d][i+1],F[dep[u]][i]);
			cmin(dp[u][d][i],F[d][i]);
		}
	}
}

int main(){
	n=rd(),m=rd();
	rep(i,1,n) {
		scanf("%s",s+1);
		int u=0;
		for(int j=1;s[j];++j) {
			int &v=trie[u][s[j]-'0'];
			if(!v) v=++cnt;
			u=v;
		}
		c[u]+=rd();
	}
	dfs(0);
	int ans=INF;
	rep(i,0,m) cmin(ans,dp[0][0][i]);
	printf("%d\n",ans);
}