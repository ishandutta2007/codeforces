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
int cmin(ll &a,ll b){ return a>b?a=b,1:0; }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=2e5+10,INF=1e9+10;

int n,a[N];
vector <int> G[N];

ll dp[N][2];
int son[N],mk[N];
void dfs(int u,int f){
	ll mi=1e18;
	for(int v:G[u]) if(v!=f) {
		dfs(v,u);
		dp[u][0]+=dp[v][1];
		if(cmin(mi,dp[v][0]-dp[v][1])) son[u]=v;
		dp[u][1]+=dp[v][1];
	}
	if(mi==1e18) {
		dp[u][0]=0,dp[u][1]=a[u];
	} else {
		dp[u][0]+=mi,mk[u]=cmin(dp[u][1],dp[u][0]+a[u]);
	}
}

vector <int> ans;
void dfs(int u,int f,int k) {
	if(f && G[u].size()==1) {
		if(k&2) ans.pb(u);
		return;
	}
	if(k&2) {
		if(dp[u][1]==dp[u][0]+a[u]) ans.pb(u);
		if(mk[u]) k^=2,k|=1;
	}
	int c=0;
	for(int v:G[u]) if(v!=f && dp[v][0]-dp[v][1]==dp[son[u]][0]-dp[son[u]][1]) c++;
	for(int v:G[u]) if(v!=f) {
		int s=0;
		if(k&1) {
			if(c==1) {
				if(v!=son[u]) s|=2;
				else s|=1;
			} else {
				if(dp[v][0]-dp[v][1]==dp[son[u]][0]-dp[son[u]][1]) s|=1;
				s|=2;
			}
		} 
		if(k&2) s|=2;
		dfs(v,u,s);
	}
}

int main(){
	rep(i,1,n=rd()) a[i]=rd();
	rep(i,2,n) {
		int u=rd(),v=rd();
		G[u].pb(v),G[v].pb(u);
	}
	dfs(1,0),dfs(1,0,2);
	cout<<dp[1][1]<<' '<<ans.size()<<endl;
	sort(ans.begin(),ans.end());
	for(int i:ans) printf("%d ",i);
}