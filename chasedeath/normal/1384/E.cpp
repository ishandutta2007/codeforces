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

const int N=30,M=1e5+10,INF=1e9+10;

int n;
char s[M],t[M];
int dp[1<<20];
int G[N],R[N],I[N],Go[N][N];

int vis[N],C;
void dfs(int u){
	if(vis[u]) return;
	vis[u]=1,I[C++]=u;
	rep(i,0,19) if(Go[u][i]||Go[i][u]) dfs(i);
}

int Solve(){
	//cout<<"-- "<<n<<endl;
	//rep(i,0,n-1) {
		//rep(j,0,n-1) cout<<((G[i]>>j)&1);
		//puts("");
	//}
	int A=(1<<n)-1; 
	rep(i,0,A) dp[i]=INF;
	dp[0]=0;
	rep(S,0,A) {
		rep(i,0,n-1) if(~S&(1<<i)) {
			cmin(dp[S|(1<<i)],dp[S]+!!(R[i]&~S));
		}
	}
	//cout<<"res"<<max(0,dp[A]-1)+n-1<<endl;
	//rep(i,0,A) cout<<"$"<<i<<' '<<dp[i]<<endl;
	return dp[A]+n-1;
}

int main(){
	rep(_,1,rd()) {
		rd(),n=0;
		scanf("%s%s",s+1,t+1);
		memset(Go,0,sizeof Go),memset(vis,0,sizeof vis);
		for(int i=1;s[i];++i) {
			int x=s[i]-'a',y=t[i]-'a';
			if(x==y) continue;
			//cout<<x<<' '<<y<<endl;
			Go[x][y]=1;
			//if(I[x]==-1) I[x]=n++;
			//if(I[y]==-1) I[y]=n++;
			//G[I[x]]|=1<<I[y],R[I[y]]|=1<<I[x]; //G[I[y]]|=1<<I[x];
			//cout<<"$"<<I[x]<<' '<<I[y]<<endl;
		}
		int ans=0;
		rep(u,0,19) if(!vis[u]) {
			C=0,dfs(u);
			rep(i,0,C) G[i]=R[i]=0;
			rep(i,0,C-1) 
				rep(j,0,C-1) if(Go[I[i]][I[j]]) G[i]|=1<<j,R[j]|=1<<i;
			n=C,ans+=Solve();
		}
		printf("%d\n",ans);
	}
}