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

const int N=5e5+10,INF=1e9+10,P=998244353;

int n;
vector <int> G[N];
int sz[N],Pow[N];

struct Node{
	int s,c;
	Node(){}
	Node(int s,int c):s(s),c(c){}
	Node operator + (const Node __) const { return Node((s+__.s)%P,(c+__.c)%P); }
	Node operator * (const Node __) const { return Node((1ll*s*__.c+1ll*c*__.s)%P,1ll*c*__.c%P); }
	Node operator + (const int x) const { return Node((s+1ll*c*x)%P,c); }
	Node operator * (const int x) const { return Node(1ll*s*x%P,1ll*c*x%P); }
} dp[N][2],t[2];

int ans;
void dfs(int u,int f){
	dp[u][0]=Node(0,1),sz[u]=1;
	for(int v:G[u]) if(v!=f) {
		dfs(v,u);
		t[0]=t[1]=Node(0,0);
		rep(i,0,1) t[i]=dp[u][i]*Pow[sz[v]-1];
		rep(i,0,1) rep(j,0,1) {
			if(!i && !j) t[1]=t[1]+(dp[u][i]*dp[v][j]+1);
			else t[i]=t[i]+dp[u][i]*dp[v][j];
		}
		dp[u][0]=t[0],dp[u][1]=t[1];
		sz[u]+=sz[v];
	}
	//cout<<"$"<<u<<' '<<dp[u][0].c<<' '<<dp[u][1].c<<endl;
	//cout<<"$"<<dp[u][0].s<<' '<<dp[u][1].s<<endl;
	ans=(ans+1ll*Pow[max(0,n-sz[u]-1)]*(dp[u][0].s+dp[u][1].s))%P;
}

int main(){
	n=rd();
	rep(i,2,n){
		int u=rd(),v=rd();
		G[u].pb(v),G[v].pb(u);
	}
	rep(i,*Pow=1,n) Pow[i]=Pow[i-1]*2,Mod1(Pow[i]);
	dfs(1,0);
	printf("%d\n",ans*2%P);
}