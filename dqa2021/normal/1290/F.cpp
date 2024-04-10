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
const int mod=998244353;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])

int n,m;
int X[8],Y[8];

int dp[2][2][2][22][22][22][22];

void solve(){
	n=read(),m=read(); const int lim=(1<<n)-1;
	rep(i,1,n) X[i]=read(),Y[i]=read();
	auto F=dp[0],G=dp[1];
	rep(u,0,1) rep(v,0,1) F[u][v][0][0][0][0]=1;
	rep(_,0,29){
		swap(F,G);
		memset(F,0,22*22*22*22<<4);
		rep(p,0,1) rep(q,0,1)
			rep(a,0,19) rep(b,0,19) rep(c,0,19) rep(d,0,19){
				const int &V=G[p][q][a][b][c][d];
				if (!V) continue;
				//if (_<=3) printf("test %d %d %d %d %d %d: %d\n",p,q,a,b,c,d,V);
				rep(msk,0,lim){
					int A=a,B=b,C=c,D=d;
					rep(i,1,n) if (msk>>i-1&1){
						if (X[i]>0) A+=X[i];
						else B-=X[i];
						if (Y[i]>0) C+=Y[i];
						else D-=Y[i]; 
					}
					if ((A^B)&1) continue;
					if ((C^D)&1) continue;
					const bool o=m>>_&1;
					rep(u,0,1) rep(v,0,1){
						if (u&&(A&1)>o) continue;
						if (v&&(C&1)>o) continue;
						if ((u&&(A&1)==o)!=p) continue;
						if ((v&&(C&1)==o)!=q) continue;
						//if (_<=3) printf("  to %d %d %d %d %d %d\n",u,v,A>>1,B>>1,C>>1,D>>1);
						add(F[u][v][A>>1][B>>1][C>>1][D>>1],V);
					}
				}
			}
	}
	int z=F[1][1][0][0][0][0];
	iadd(z,1);
	printf("%d\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}