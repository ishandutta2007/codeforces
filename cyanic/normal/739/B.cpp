#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=200005;
int fa[N][20],a[N],dp[N],n;
vector<pii> e[N];
ll d[N];

void dfs2(int u){
	for(auto v:e[u]){
		dfs2(v.fi);
		dp[u]+=dp[v.fi];
	}
}

void dfs(int u){
	rep(j,1,18){
		fa[u][j]=fa[fa[u][j-1]][j-1];
	}
	int x=u;
	per(j,18,0){
		if(fa[x][j]&&d[fa[x][j]]>=d[u]-a[u]){
			x=fa[x][j];
		}
	}
	dp[fa[u][0]]++,dp[fa[x][0]]--;
	for(auto v:e[u]){
		d[v.fi]=d[u]+v.se;
		dfs(v.fi);
	}
}

int main(){
	read(n);
	rep(i,1,n){
		read(a[i]);
	}
	rep(i,2,n){
		read(fa[i][0]);
		int w; read(w);
		e[fa[i][0]].pb(mp(i,w));
	}
	dfs(1);
	dfs2(1);
	rep(i,1,n){
		printf("%d%c",dp[i]," \n"[i==n]);
	}
	return 0;
}