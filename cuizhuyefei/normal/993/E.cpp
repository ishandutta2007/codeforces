#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define pi acos(-1)
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
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
const int N = 555555;
int n,v[N],q[N]; ll ans[N],c[N];
struct E {
	double a,b; //a+bi
	E(double A=0, double B=0){a=A;b=B;}
	inline double real(){return a;}
	inline double imag(){return b;}
};
E operator + (E x, E y){return E(x.a+y.a,x.b+y.b);}
E operator - (E x, E y){return E(x.a-y.a,x.b-y.b);}
E operator * (E x, E y){return E(x.a*y.a-x.b*y.b,x.a*y.b+x.b*y.a);}
E w[N],a[N],b[N];
inline void fft(E *a, int n, int tp){
	for(int i=1,j=0;i<n;i++){
		for(int k=n>>1;!((j^=k)&k);k>>=1);
		if(i<j)swap(a[i],a[j]);
	}
	for(int j=2;j<=n;j<<=1){
		w[0]=1;w[1]=E(cos(2*pi/j),tp*sin(2*pi/j));int m=(j>>1)-1;
		rep(i,2,m)w[i]=w[i-1]*w[1];
		for(register int k=0;k<n;k+=j)rep(i,0,m){
			E x=a[k+i+(j>>1)]*w[i];
			a[k+i+(j>>1)]=a[k+i]-x;	a[k+i]=a[k+i]+x;
		}
	}
}
inline void mul(E *a, E *b, int m, ll *c){
	int n;for(n=1;n<=m+m;n<<=1);//WA1
	fft(a,n,1);fft(b,n,1);
	rep(i,0,n-1)a[i]=a[i]*b[i];
	fft(a,n,-1);rep(i,0,n-1)c[i]=ll(a[i].real()/n+0.5);
}
int main() {
	read(n);int x;read(x);rep(i,1,n)read(v[i]),q[i]=v[i]<x,v[i]=v[i-1]+q[i];
	rep(i,0,n)b[v[i]]=b[v[i]]+1,a[n-v[i]]=a[n-v[i]]+1;
	mul(a,b,n,c);rep(i,0,n)ans[i]=c[i+n];ans[0]=0;
//	rep(i,1,n)printf("q[]=%d\n",q[i]);
	rep(i,1,n)if(q[i]==0){
		int j;for(j=i;j<=n;j++)if(q[j]==1)break;
		ans[0]+=1LL*(j-i)*(j-i+1)/2;i=j-1;
	}
	rep(i,0,n)printf("%lld ",ans[i]);
	return 0;
}