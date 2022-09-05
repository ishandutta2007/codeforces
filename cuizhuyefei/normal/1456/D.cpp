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
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

template<class T> inline T Abs(const T &x){return x>0?x:-x;}
const int N = 5007;
int n,t[N],x[N],l[N],r[N];bool f[N][N];
void upd_(int i, int L, int R){umin(l[i],L);umax(r[i],R);}//f[i][0]=1;}
void doit(int i, int L, int R){
	rep(j,1,n)if(x[j]>=L&&x[j]<=R)f[i][j]=1;
	f[i][0]=1;umin(l[i],x[i]);umax(r[i],x[i]);
}
void upd(int l, int r, int t, int x, int i){
	int mn=min(Abs(l-x),Abs(r-x));if(l<=x&&r>=x)mn=0;
	if(t>=mn)upd_(i,x-(t-mn),x+(t-mn));
	int lo=1e9,hi=-1e9;
	if(l<=x-t&&x-t<=r)umin(lo,x-t),umax(hi,x);
	if(l<=x+t&&x+t<=r)umin(lo,x),umax(hi,x+t);
	if(Abs(x-l)<=t){
		if(l<x)umin(lo,l-(t-Abs(x-l))/2),umax(hi,x);
		else umin(lo,x-(t-Abs(x-l))/2),umax(hi,l);
	}
	if(Abs(x-r)<=t){
		if(r>x)umin(lo,x),umax(hi,r+(t-Abs(x-r))/2);
		else umin(lo,r),umax(hi,x+(t-Abs(r-x))/2);
	}
	if(lo<=hi)doit(i,lo,hi);
}
int main() {
	read(n);rep(i,1,n)read(t[i]),read(x[i]),l[i]=x[i]+1,r[i]=x[i]-1;
	f[0][0]=1;rep(i,1,n)if(x[i]==0)f[0][i]=1;
	rep(i,0,n-1){
		rep(j,0,n)if(f[i][j]){
		//	umin(l[i],x[i]),umax(r[i],x[i]);

			if(Abs(x[i+1]-x[i])<=t[i+1]-t[i])f[i+1][j]=1;
		}
		if(f[i][i+1]){
			if(i+1==n)return puts("YES"),0;
			upd(x[i]-(t[i+1]-t[i]),x[i]+(t[i+1]-t[i]),t[i+2]-t[i+1],x[i+2],i+2);
		}
		if(l[i]<=r[i])upd(l[i],r[i],t[i+1]-t[i],x[i+1],i+1);
	}
	rep(i,0,n)if(f[n][i]||l[n]<=r[n])return puts("YES"),0;
	puts("NO");
	return 0;
}