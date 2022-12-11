#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
#define G getchar()
ll read()
{
	ll x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
//typedef pair<int,int> P;
/*const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}*/
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n; ll S;
ll a[100010];
ll b[100010];

void work(ll v){
	rep(i,1,n){
		ll l=0,r=a[i],mid;
		while (l<r){
			mid=l+r+1>>1;
			if (a[i]-3*mid*mid-3*mid-1>=v) l=mid;
			else r=mid-1;
		}
		b[i]=l;
	}
}

ll check(ll x){
	work(x);
	ll tot=0;
	rep(i,1,n) tot+=b[i];
	return tot;
}

void solve(){
	n=read(),S=read();
	rep(i,1,n) a[i]=read();
	ll l=-4e18,r=4e18,mid;
	while (l<r){
		mid=l+(r-l+1>>1);
		if (check(mid)>=S) l=mid;
		else r=mid-1;
	}
	//printf("test %lld  %lld\n",l,check(l));
	work(l);
	static ll c[100010];
	rep(i,1,n) c[i]=b[i];
	work(l+1);
	ll tot=S;
	rep(i,1,n) tot-=b[i];
	rep(i,1,n){
		ll t=min(tot,c[i]-b[i]);
		printf("%lld ",b[i]+t);
		tot-=t;
	}
	puts("");
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}