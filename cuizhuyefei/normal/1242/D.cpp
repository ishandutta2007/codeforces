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
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
ll n,k;
ll getblock(ll n){return (n-1)/(k*k+1);}
ll getend(ll i, ll t){return i*(k*k+1)+t*k+k;}
//ll getend(ll i, ll t){return i*(k*k+1)+t*k+k;}
ll getans(ll x){
	if(!x)return k*(k+1)/2;
	ll i=x/k,t=x%k;
	ll pos=getans(i);
	ll off=max(min(getend(i,t)-pos+1,k),0LL);
	return (i*k+t)*(k*k+1)-t+k*(k+1)/2+off;
}
ll getcnt(ll x){return x+(x-1)/k;}
int main() {
	int T;read(T);while(T--){
		read(n);read(k);
		ll x=getblock(n);
		ll pos=getans(x);
		ll res;
		if(pos==n)res=(x/k*k+x%k+1)*(k+1);
		else res=x*k*(k+1)+getcnt(n-x*(k*k+1)-(pos<n));
		printf("%lld\n",res);
	}
	return 0;
}