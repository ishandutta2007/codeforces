#include<bits/stdc++.h>
#define pb emplace_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
typedef pair<ll,int> P;
/*const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}*/
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n,m,S,T;
int w[2010];
vector<P> e[2010];

void dijkstra(int S,ll *dis){
	rep(i,1,n) dis[i]=1e18;
	dis[S]=0;
	static P hp[100010]; int top=1;
	hp[1]=P(dis[S],S);
	const auto cmp=[&](const P &x,const P &y){return x>y;};
	while (top){
		const P c=hp[1];
		hp[1]=hp[top--];
		pop_heap(hp+1,hp+top+1,cmp);
		if (dis[c.se]^c.fi) continue;
		int u=c.se;
		for (const auto &[w,v]: e[u])
			if (dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				hp[++top]=P(dis[v],v);
				push_heap(hp+1,hp+top+1,cmp);
			}
	}
}

ll disS[2010],disT[2010];

ll dp[2][2010][2010],f[2][2010][2010],h[2][2010][2010];
int g[2][2010][2010];

void solve(){
	n=read(),m=read(),S=read(),T=read();
	rep(i,1,n) w[i]=read();
	while (m--){
		int u=read(),v=read(),w=read();
		e[u].pb(w,v);
		e[v].pb(w,u);
	}
	dijkstra(S,disS);
	dijkstra(T,disT);
	
	static int A[2010],B[2010];
	
	rep(i,1,n) A[i]=B[i]=i;
	sort(A+1,A+n+1,[&](const int &x,const int &y){return disS[x]<disS[y];});
	sort(B+1,B+n+1,[&](const int &x,const int &y){return disT[x]<disT[y];});
	
	rep(i,0,n){
		static bool ban[2010];
		rep(j,1,i) ban[B[j]]=1;
		rep(j,i+1,n) ban[B[j]]=0;
		rep(j,1,n){
			f[0][j][i]=f[0][j-1][i];
			if (!ban[A[j]]) f[0][j][i]+=w[A[j]];
		}
		per(j,0,n-1){
			if (ban[A[j+1]]||(j+1<n&&disS[A[j+1]]==disS[A[j+2]])) g[0][j][i]=g[0][j+1][i];
			else g[0][j][i]=j+1;
		}
	}
	rep(i,0,n){
		static bool ban[2010];
		rep(j,1,i) ban[A[j]]=1;
		rep(j,i+1,n) ban[A[j]]=0;
		rep(j,1,n){
			f[1][i][j]=f[1][i][j-1];
			if (!ban[B[j]]) f[1][i][j]+=w[B[j]];
		}
		per(j,0,n-1){
			if (ban[B[j+1]]||(j+1<n&&disT[B[j+1]]==disT[B[j+2]])) g[1][i][j]=g[1][i][j+1];
			else g[1][i][j]=j+1;
		}
	}
	per(i,0,n) per(j,0,n){
		if (g[0][i][j]){
			dp[0][i][j]=h[1][g[0][i][j]][j]-f[0][i][j];
		}
		if (g[1][i][j]){
			dp[1][i][j]=h[0][i][g[1][i][j]]+f[1][i][j];
		}
		h[1][i][j]=dp[1][i][j]+f[0][i][j];
		if (i<n) h[1][i][j]=max(h[1][i][j],h[1][i+1][j]);
		h[0][i][j]=dp[0][i][j]-f[1][i][j];
		if (j<n) h[0][i][j]=min(h[0][i][j],h[0][i][j+1]);
	}
	const ll ans=dp[0][0][0];
	if (ans>0) puts("Break a heart");
	else if (ans==0) puts("Flowers");
	else puts("Cry");
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}