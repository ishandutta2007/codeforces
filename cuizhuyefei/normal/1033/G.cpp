#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
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
const int N = 233333;
int n,m,a[N],mx,mx1,L,R,c;
ll xs,hs,v[N];
int query(int x){x=max(2*x,c-x);return (mx>=x)+(mx1>=x);}//>=x
int inter(int l, int r, int L, int R){return max(0,min(r,R)-max(l,L)+1);}
void find0(int l, int r){
	a[n+1]=c-1;rep(i,1,n+1){
		int L=c-a[i],R=c-(a[i-1]+1);
		if(n-i+1&1)xs+=inter(l,r,L,R);else hs+=inter(l,r,L,R);
	}
}
void find1(int l, int r){
	a[n+1]=c-1;rep(i,1,n+1){
		int L=c-a[i],R=c-(a[i-1]+1);
		if(n-i+1&1)xs+=inter(l,r,L,R);
	}
}
void add1(int l, int r){
	if(l<=r&&query(l)==0){
		int L=l+1,R=r,res=l;
		while(L<=R){
			int mid=(L+R)>>1;
			if(query(mid)==0)res=mid,L=mid+1;else R=mid-1;
		}
		find0(l,res);l=res+1;
	}
	if(l<=r&&query(l)==1){
		int L=l+1,R=r,res=l;
		while(L<=R){
			int mid=(L+R)>>1;
			if(query(mid)==1)res=mid,L=mid+1;else R=mid-1;
		}
		find1(l,res);l=res+1;
	}
	//rep(i,l,r)if(query(i)==0)find0(i,i);
	//rep(i,l,r)if(query(i)==1)find1(i,i);
}
void add2(int l, int r){
	if(l<=r&&query(r)==0){
		int L=l,R=r-1,res=r;
		while(L<=R){
			int mid=(L+R)>>1;
			if(query(mid)==0)res=mid,R=mid-1;else L=mid+1;
		}
		find0(res,r);r=res-1;
	}
	if(l<=r&&query(r)==1){
		int L=l,R=r-1,res=r;
		while(L<=R){
			int mid=(L+R)>>1;
			if(query(mid)==1)res=mid,R=mid-1;else L=mid+1;
		}
		find1(res,r);r=res-1;
	}
	
	//rep(i,l,r)if(query(i)==0)find0(i,i);
	//rep(i,l,r)if(query(i)==1)find1(i,i);
}
int main() {
	read(n);read(m);rep(i,1,n)read(v[i]);
	for(c=1;c<=m*2;c++){
		rep(i,1,n)a[i]=v[i]%c;mx=-1,mx1=-1;sort(a+1,a+n+1);
		rep(i,1,n)if(a[i]>mx){mx1=mx;mx=a[i];}else if(a[i]>mx1)mx1=a[i];
		L=max(1,c-m);R=(c-1)/2;
		rep(i,1,n)if(a[i]*2<=c)umax(L,a[i]+1);else umax(L,c-a[i]);
		add1(L,min(n/3,R));add2(max(n/3+1,L),R);
	}
	xs*=2;hs*=2;rep(a,1,m){
		ll cnt=0;rep(j,1,n)cnt+=v[j]/a,cnt%=2;if(cnt&1)xs++;else hs++;
	}
	ll x=(1LL*m*m-xs-hs)/2;printf("%lld %lld %lld %lld",x,x,xs,hs);
	return 0;
}