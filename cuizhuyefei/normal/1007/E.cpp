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
const int N = 203;
int n,t,k;ll a[N],b[N],c[N],A[N],B[N],f[N][N][2],g[N][N][2];
int main() {
	memset(f,0x3f,sizeof(f));memset(g,0x3f,sizeof(g));
	const ll inf=f[0][0][0];
	memset(f[0],0,sizeof(f[0]));memset(g[0],0,sizeof(g[0]));
	read(n);read(t);read(k);
	rep(i,1,n){read(a[i]);read(b[i]);read(c[i]);}
	++n;a[n]=b[n]=0x3f3f3f3f;c[n]=inf;
	rep(i,1,n)A[i]=A[i-1]+a[i];
	rep(i,1,n)B[i]=B[i-1]+b[i];
//	rep(i,1,n)C[i]=C[i-1]+c[i];
	rep(i,1,n)rep(j,0,t)rep(q,0,1){
		//1
		if(q*a[i]+b[i]*j<=c[i]&&f[i-1][j][q]<inf){
			umin(f[i][j][q],f[i-1][j][q]);
			ll gs=(q*A[i-1]+B[i-1]*j+k-1)/k;
			if(gs*k<=q*A[i]+B[i]*j)umin(g[i][j][q],gs);
		}
		//2
		rep(r,0,j-1)if(g[i][r][q]<inf){
			ll rem=q*A[i]+B[i]*r-g[i][r][q]*k;
			ll gs=max((rem+(j-r)*b[i]-c[i]+k-1)/k,0ll);
			if(gs*k<=rem&&f[i-1][j-r][0]<inf){
				umin(f[i][j][q],g[i][r][q]+gs+f[i-1][j-r][0]);
				//if(g[i-1][j-r][0]<inf)
				if((B[i-1]*(j-r)+k-1)/k*k<=B[i]*(j-r)+rem-k*gs)
					umin(g[i][j][q],g[i][r][q]+gs+(B[i-1]*(j-r)+k-1)/k);
			//	if(i==3&&j==2&&q==0)std::cerr<<"B "<<g[i][r][q]+gs+(B[i-1]*(j-r)+k-1)/k<<' '<<(B[i-1]*(j-r)+k-1)/k*k<<' '<<B[i-1]*(j-r)+rem-k*gs<<std::endl;
			}
		}
	//	printf("%d %d %d:%lld %lld\n",i,j,q,f[i][j][q],g[i][j][q]);
	}
	cout<<f[n][t][1];
	return 0;
}