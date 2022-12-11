#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
using namespace std;

//#define DEBUG
#ifdef DEBUG
template<typename ...Args>
int debug(const Args &...args){
	return fprintf(stderr,args...);
}
#else
#define debug(...) void()
#endif

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
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])

int n,q;
char s[100010];
int t[100010][26];
int dp[256][256][256];

char a[256],b[256],c[256];
int A,B,C;

void append(int o,char d){
	if (o==1){
		a[++A]=d;
		rep(y,0,B) rep(z,0,C) dp[A][y][z]=n+1;
		rep(y,0,B) rep(z,0,C){
			int &V=dp[A-1][y][z];
			if (V>n) continue;
			int &U=dp[A][y][z];
			U=min(U,t[V][d-'a']);
		}
		rep(y,0,B) rep(z,0,C){
			int &V=dp[A][y][z];
			if (V>n) continue;
			if (y<B){
				int &U=dp[A][y+1][z];
				U=min(U,t[V][b[y+1]-'a']);
			}
			if (z<C){
				int &U=dp[A][y][z+1];
				U=min(U,t[V][c[z+1]-'a']);
			}
		}
	}
	else if (o==2){
		b[++B]=d;
		rep(x,0,A) rep(z,0,C) dp[x][B][z]=n+1;
		rep(x,0,A) rep(z,0,C){
			int &V=dp[x][B-1][z];
			if (V>n) continue;
			int &U=dp[x][B][z];
			U=min(U,t[V][d-'a']);
		}
		rep(x,0,A) rep(z,0,C){
			int &V=dp[x][B][z];
			if (V>n) continue;
			if (x<A){
				int &U=dp[x+1][B][z];
				U=min(U,t[V][a[x+1]-'a']);
			}
			if (z<C){
				int &U=dp[x][B][z+1];
				U=min(U,t[V][c[z+1]-'a']);
			}
		}
	}
	else{
		c[++C]=d;
		rep(x,0,A) rep(y,0,B) dp[x][y][C]=n+1;
		rep(x,0,A) rep(y,0,B){
			int &V=dp[x][y][C-1];
			if (V>n) continue;
			int &U=dp[x][y][C];
			U=min(U,t[V][d-'a']);
		}
		rep(x,0,A) rep(y,0,B){
			int &V=dp[x][y][C];
			if (V>n) continue;
			if (x<A){
				int &U=dp[x+1][y][C];
				U=min(U,t[V][a[x+1]-'a']);
			}
			if (y<B){
				int &U=dp[x][y+1][C];
				U=min(U,t[V][b[y+1]-'a']);
			}
		}
	}
}

void erase(int o){
	if (o==1) --A;
	else if (o==2) --B;
	else --C;
}

void solve(){
	n=read(),q=read();
	scanf("%s",s+1);
	rep(e,0,25) t[n][e]=n+1;
	per(i,0,n-1){
		auto F=t[i],G=t[i+1];
		memcpy(F,G,26<<2);
		F[s[i+1]-'a']=i+1;
	}
	dp[0][0][0]=0;
	while (q--){
		char o[2],p[2]; scanf("%s",o); int x=read();
		if (o[0]=='+') scanf("%s",p);
		if (o[0]=='+') append(x,p[0]);
		else erase(x);
		puts(dp[A][B][C]<=n?"YES":"NO");
		//rep(x,0,A) rep(y,0,B) rep(z,0,C) printf("  dp %d %d %d: %d\n",x,y,z,dp[x][y][z]);
	}
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}