#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define pi acos(-1)
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1100000;
struct E {
	double a,b; //a+bi
	double imag() {return b;}
	double real() {return a;}
	E(double A=0, double B=0) {a=A; b=B;}	
};
E operator + (const E &x, const E &y) {return E(x.a+y.a,x.b+y.b);}
E operator - (const E &x, const E &y) {return E(x.a-y.a,x.b-y.b);}
E operator * (const E &x, const E &y) {return E(x.a*y.a-x.b*y.b,x.a*y.b+x.b*y.a);}
E w[N],a[N],b[N];
int c[N],f[N];char s[N];
inline void fft(E *a, int n, int tp) {
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
inline void mul(E *a, E *b, int m, int *c) {
	int n;for(n=1;n<=m;n<<=1);
	fft(a,n,1); fft(b,n,1);
	rep(i,0,n-1) a[i]=a[i]*b[i];
	fft(a,n,-1);
	rep(i,0,n-1) c[i]=(a[i].real())/n+0.5;
}
Vi ans;
int main() {
	int T;read(T);
	while(T--){
		int n;read(n);scanf("%s",s+1);rep(i,0,4*n)a[i]=b[i]=0;
		rep(i,1,n)a[n-i]=s[i]=='V',b[i]=s[i]=='K';
		mul(a,b,n+n,c);rep(i,1,n)f[i]=c[n-i]+c[n+i];
		rep(i,0,n+n)c[i]=0;rep(i,1,n)for(int j=i;j<=n;j+=i)c[i]|=f[j];
		ans.clear();rep(i,1,n)if(!c[i])ans.pb(i);
		printf("%d\n",SZ(ans));int l=SZ(ans)-1;rep(i,0,l)printf("%d ",ans[i]);puts("");
	}
	return 0;
}