#include<cstdio>
#include<cstring>
#include<vector>
#include<complex>
#include<iostream>
#include<algorithm>
#include<cmath>
#define fi first
#define se second
#define pi acos(-1)
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef complex<double> E;
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 800008;
int ans[N];
bool tmp[N];
char s[N],t[N],ch[]={'A','G','C','T'};
E a[N],b[N],w[N];
inline void fft(E *a, int n, int tp) {
	for (int i=1,j=0; i<n; i++) {
		for (int k=n>>1; !((j^=k)&k); k>>=1);
		if (i<j) swap(a[i],a[j]);
	}
	for (int j=2; j<=n; j<<=1) {
		w[0]=1; w[1]=E(cos(2*pi/j),tp*sin(2*pi/j));
		rep(i,2,(j>>1)-1) w[i]=w[i-1]*w[1];
		for (int k=0; k<n; k+=j) rep(i,0,(j>>1)-1) {
			E x=a[k+i],y=w[i]*a[k+i+(j>>1)];
			a[k+i]=x+y; a[k+i+(j>>1)]=x-y;
		}
	}
}
inline void mul(E *a, int n, E *b, int m) {
	m=n+m; for (n=1; n<=m; n<<=1);
	fft(a,n,1); fft(b,n,1);
	rep(i,0,n-1) a[i]=a[i]*b[i];
	fft(a,n,-1); rep(i,0,m) ans[i]+=int(a[i].real()/n+0.5);
	rep(i,0,n-1) {a[i]=0; b[i]=0;}
}
int main() { //freopen("1.in","r",stdin);
	int n,m,k; read(n); read(m); read(k);
	scanf("%s%s",s+1,t+1);
	rep(p,0,3) {
		memset(tmp,0,sizeof(tmp));
		rep(i,1,m) b[i]=t[i]==ch[p];
		int lst=-k-1;
		rep(i,1,n) {if (s[i]==ch[p]) lst=i; tmp[i]=(i-lst)<=k;}
		lst=n+k+1; per(i,n,1) {if (s[i]==ch[p]) lst=i; tmp[i]|=(lst-i)<=k;}
		rep(i,1,n) a[i]=tmp[n-i+1];
		mul(a,n,b,m);
	}
	int res=0; //rep(i,0,n+m) printf("%d ",ans[i]); puts("");
	rep(i,0,n+m) res+=(ans[i]==m);
	printf("%d",res);
	return 0;
}