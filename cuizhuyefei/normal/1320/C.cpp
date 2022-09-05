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
	static ui seed=613;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1e6+11,inf=2e9,lim=1e6+1;
int n,m,p,c[N];Pii a[N];pair<int,Pii>b[N];ll res=-2e9;

int val[N<<2],lzy[N<<2];
void upd(int k){val[k]=max(val[k<<1],val[k<<1|1]);}
void pushdown(int k){
	if(lzy[k]){
		val[k<<1]+=lzy[k];lzy[k<<1]+=lzy[k];
		val[k<<1|1]+=lzy[k];lzy[k<<1|1]+=lzy[k];
		lzy[k]=0;
	}
}
void build(int k, int l, int r){
	if(l==r){val[k]=c[l];return;}
	int mid=(l+r)>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	upd(k);
}
void mdy(int k, int l,int r, int x, int L, int R){
	if(l==L&&r==R){val[k]+=x;lzy[k]+=x;return;}
	int mid=(L+R)>>1;pushdown(k);
	if(r<=mid)mdy(k<<1,l,r,x,L,mid);
	else if(l>mid)mdy(k<<1|1,l,r,x,mid+1,R);
	else mdy(k<<1,l,mid,x,L,mid),mdy(k<<1|1,mid+1,r,x,mid+1,R);
	upd(k);
}

int main() {
	read(n);read(m);read(p);
	rep(i,1,n)read(a[i].fi),read(a[i].se);
	rep(i,1,lim)c[i]=-inf;
	rep(i,1,m){int x,y;read(x);read(y);umax(c[x],-y);}
	rep(i,1,p)read(b[i].fi),read(b[i].se.fi),read(b[i].se.se);
	sort(a+1,a+n+1);sort(b+1,b+p+1);
	build(1,1,lim);
	for(int i=1,j=0;i<=n;i++){
		while(j+1<=p&&b[j+1].fi<a[i].fi)j++,mdy(1,b[j].se.fi+1,lim,b[j].se.se,1,lim);
		umax(res,-1ll*a[i].se+val[1]);
	}
	cout<<res;
	return 0;
}