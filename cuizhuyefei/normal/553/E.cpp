#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
#define pi acos(-1)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1<<16|3;const double inf=1e14;
struct E {
	double a,b; //a+bi
	double imag() {return b;}
	double real() {return a;}
	E(double A=0, double B=0) {a=A; b=B;}	
};
inline E operator + (const E &x, const E &y) {return E(x.a+y.a,x.b+y.b);}
inline E operator - (const E &x, const E &y) {return E(x.a-y.a,x.b-y.b);}
inline E operator * (const E &x, const E &y) {return E(x.a*y.a-x.b*y.b,x.a*y.b+x.b*y.a);}
inline void fft(E *a, int n, int tp) {
	static E w[N];
	for (int i=1,j=0; i<n; i++) {
		for (int k=(n>>1); !((j^=k)&k); k>>=1);
		if (i<j) swap(a[i],a[j]);
	}
	for (int j=2; j<=n; j<<=1) {
		w[0]=1; w[1]=E(cos(2*pi/j),tp*sin(2*pi/j));
		int m=(j>>1)-1; rep(i,2,m) w[i]=w[i-1]*w[1];
		for (register int i=0; i<n; i+=j) rep(k,0,m) {
			E x=a[i+k+(j>>1)]*w[k];
			a[i+k+(j>>1)]=a[i+k]-x; a[i+k]=a[i+k]+x;
		}
	}
}
inline void mul(double *A, double *B, int l1, int l2, double *c) {//a[0..l1] * b[0..l2]
	int n;for(n=1;n<=l1+l2;n<<=1);
	if(n<=128){
		rep(i,0,l1+l2)c[i]=0;
		rep(i,0,l1)rep(j,0,l2)c[i+j]+=A[i]*B[j];
		return;
	}
	/*printf("mul %d %d\n",l1,l2);
	rep(i,0,l1)printf("%lf ",A[i]);puts("");
	rep(i,0,l2)printf("%lf ",B[i]);puts("");*/
	static E a[N],b[N];
	rep(i,0,l1)a[i]=E(A[i],0);rep(i,l1+1,n-1)a[i]=E(0,0);
	rep(i,0,l2)b[i]=E(B[i],0);rep(i,l2+1,n-1)b[i]=E(0,0);
	fft(a,n,1); fft(b,n,1);
	rep(i,0,n-1) a[i]=a[i]*b[i];
	fft(a,n,-1);
	rep(i,0,n-1) c[i]=(a[i].real())/n;
//	rep(i,0,l1+l2)printf("%lf ",c[i]);puts("");
}
int t,n,m,x,A[N],B[N],C[N];Vi e[N];
double dis[N],f[52][20200],dp[102][20200],p[102][20002],hz[102][20002];bool vis[N];
void solve(int l, int r){
	if(l==r){
		if(l==t)return;
		rep(i,1,n){
			f[i][l]=inf;
			rep(j,0,SZ(e[i])-1){
				umin(f[i][l],C[e[i][j]]+dp[e[i][j]][l]+f[B[e[i][j]]][t]*hz[e[i][j]][t-l+1]);
			//	if(l==t-1&&i==3)printf("%lf %lf\n",C[e[i][j]]+dp[e[i][j]][l],f[B[e[i][j]]][t]*hz[e[i][j]][t-l+1]);
			}
			if(i==n)f[i][l]=0;
		}
		return;
	}
	int mid=(l+r)>>1;solve(mid+1,r);
	rep(j,1,m){
		static double a[N],b[N],c[N];
		rep(i,0,r-l)a[i]=b[i]=0;rep(i,mid+1,r)a[i-mid]=f[B[j]][i];
		rep(i,0,r-l)b[r-l-i]=p[j][i];
		/*if(l==t-2&&r==t&&j==3){
			rep(i,0,r-l)printf("%lf %lf\n",a[i],b[i]);
			printf("qwq %lf\n",dp[j][t-1]);
		}*/
		mul(a,b,r-mid,r-l,c);
		rep(i,r-mid,r-l)dp[j][i+mid-r+l]+=c[i];
	//	if(l==t-2&&r==t&&j==3)printf("qwq %lf\n",dp[j][t-1]);
	}
	solve(l,mid);
}
int main() {
	read(n);read(m);read(t);read(x);t++;
	rep(i,1,m){
		read(A[i]),read(B[i]),read(C[i]);e[A[i]].pb(i);
		rep(j,1,t-1){int x;read(x);p[i][j]=x/100000.0;}
		per(j,t,1)hz[i][j]=hz[i][j+1]+p[i][j];
	}
	rep(i,1,n)dis[i]=inf;dis[n]=0;
	rep(tt,1,n){
		int u=0;rep(i,1,n)if(!vis[i]&&(!u||dis[i]<dis[u]))u=i;
		vis[u]=1;
		rep(i,1,m)if(B[i]==u)umin(dis[A[i]],dis[B[i]]+C[i]);
	}
	rep(i,1,n)f[i][t]=dis[i]+x;
	solve(0,t);
	/*rep(i,1,n){
		rep(j,0,t)printf("%.3lf ",f[i][j]);puts("");
	}*/
	printf("%.9lf\n",f[1][0]);
	return 0;
}