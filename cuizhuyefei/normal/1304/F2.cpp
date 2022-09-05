#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 20050,inf=0x3f3f3f3f;
int n,m,k,f[52][N],a[52][N];
namespace zkw{
	int m,a[N<<2];
	void ini(int n, int *s){
		for(m=1;m<=n+1;m<<=1);
		rep(i,0,m<<1)a[i]=-inf;
		rep(i,1,n)a[m+i]=s[i];
		per(i,m-1,1)a[i]=max(a[i<<1],a[i<<1|1]);
	}
	int qry(int l,int r){
		l=m+l-1;r=m+r+1;int res=-inf;
		while((l>>1)!=(r>>1)){
			if(~l&1)umax(res,a[l+1]);
			if(r&1)umax(res,a[r-1]);
			l>>=1;r>>=1;
		}
		return res;
	}
}
int main() {
	read(n);read(m);read(k);
	rep(i,1,n)rep(j,1,m)read(a[i][j]),a[i][j]+=a[i][j-1];
	rep(j,1,m-k+1)f[1][j]=a[1][j+k-1]-a[1][j-1];
	rep(i,2,n){
		static int qz[N],hz[N];
		rep(j,1,m-k+1)qz[j]=hz[j]=f[i-1][j]+a[i][j+k-1]-a[i][j-1];
		rep(j,1,m-k+1)umax(qz[j],qz[j-1]);
		per(j,m-k+1,1)umax(hz[j],hz[j+1]);
		rep(j,1,m-k+1){
			int x=j;
			if(x-k>=1)umax(f[i][j],qz[x-k]+a[i][j+k-1]-a[i][j-1]);
			if(x+k<=m)umax(f[i][j],hz[x+k]+a[i][j+k-1]-a[i][j-1]);
		}
		static int s[N];rep(j,1,m-k+1)s[j]=f[i-1][j]-a[i][j-1];
		zkw::ini(m-k+1,s);
		rep(j,1,m-k+1){
			int l=max(j-k+1,1),r=j;if(l<=r)umax(f[i][j],zkw::qry(l,r)+a[i][j+k-1]);
		}
		rep(j,1,m-k+1)s[j]=f[i-1][j]+a[i][j+k-1];
		zkw::ini(m-k+1,s);
		rep(j,1,m-k+1){
			int l=j,r=min(j+k-1,m-k+1);if(l<=r)umax(f[i][j],zkw::qry(l,r)-a[i][j-1]);
		}
	}
	int res=0;rep(j,1,m-k+1)umax(res,f[n][j]);cout<<res;
	return 0;
}