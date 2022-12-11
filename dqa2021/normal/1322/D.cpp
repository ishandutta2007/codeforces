#include<bits/stdc++.h>
#define pb push_back
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
//typedef pair<int,int> P;
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
#define forall(x,y) for (const int &y: e[x])
int INF;

int n,m;
int w[2010];
int s[2010],c[4010],d[4010];  //d \sum c
int lim,bt;
int dp[2][2010][2048];

inline void chk(int &x,const int &y){if (y>x) x=y;}
inline int getsum(int l,int r){
	return d[r]-d[l-1];
}
inline int getval(int x,int *w){
	int z=0;
	while (x&1) z+=*w,++w,x>>=1;
	z+=*w;
	return z;
}

int A;

void work(int x,int y){
	if (w[y]+bt<w[x]){
		if (A==-INF) return;
		chk(dp[0][y][1],A+s[y]+c[w[y]]);
		//chk(dp[1][y][1],A+c[w[y]+bt]+s[y]+c[w[y]]);
		return;
	}
	if (w[y]==w[x]){
		rep(e,0,1) rep(msk,0,lim-1){
			const int &V=dp[e][x][msk];
			if (V==-INF) continue;
			chk(dp[e][y][msk],V-s[x]+s[y]);
			if (msk==lim-1){
				if (!e) continue;
				chk(dp[0][y][0],V+s[y]+getsum(w[x],w[x]+bt-1));
				continue;
			}
			chk(dp[e][y][msk+1],V+s[y]+getval(msk,c+w[x]));
		}
		return;
	}
	{
		rep(e,0,1) rep(msk,0,lim-1){
			const int &V=dp[e][x][msk];
			if (V==-INF) continue;
			const int d=w[x]-w[y];
			if (!e){
				chk(dp[0][y][(msk<<d|1)&(lim-1)],V+s[y]+c[w[y]]);
				if ((msk>>bt-d)!=(1<<d)-1) chk(dp[1][y][(msk<<d|1)&(lim-1)],V+s[y]+c[w[y]]+getval(msk>>bt-d,c+w[x]+bt-d));
				//else chk(dp[1][y][(msk<<d|1)&(lim-1)],V+s[y]+c[w[y]]+getsum(w[x]+bt-d,w[x]+bt-1));
			}
			else{
				if ((msk>>bt-d)!=(1<<d)-1) continue;
				chk(dp[1][y][(msk<<d|1)&(lim-1)],V+s[y]+c[w[y]]+getsum(w[x]+bt-d,w[x]+bt-1));
			}
		}
		return;
	}
}

void solve(){
	n=read(),m=read();
	rep(i,1,n) w[i]=read();
	rep(i,1,n) s[i]=-read();
	rep(i,1,n+m) c[i]=read(),d[i]=d[i-1]+c[i];
	for (lim=1,bt=0;lim<=n;lim<<=1,++bt);
	memset(dp,-0x3f,sizeof dp); INF=-dp[0][0][0];
	rep(i,1,n){
		dp[0][i][1]=s[i]+c[w[i]];
		//dp[1][i][1]=dp[0][i][1]+c[w[i]+bt];
	}
	int ans=0;
	rep(i,1,n){
		rep(j,0,lim-1){
			ans=max(ans,dp[0][i][j]);
		}
		/*rep(e,0,1) rep(j,0,lim-1){
			printf("dp %d %d %d = %d\n",e,i,j,dp[e][i][j]);
		}*/
		A=-INF;
		rep(msk,0,lim-1){
			const int &V=dp[0][i][msk];
			if (V==-INF) continue;
			A=max(A,V);
		}
		static bool vis[2010];
		memset(vis,0,sizeof vis);
		rep(j,i+1,n){
			if (w[j]>w[i]) continue;
			if (vis[w[j]]) continue;
			vis[w[j]]=1; work(i,j);
		}
	}
	printf("%d\n",ans);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}