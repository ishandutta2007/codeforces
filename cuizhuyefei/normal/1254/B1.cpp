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
const int N = 2666666;
int n;ll a[N],res=7e18;
bool ck(ll k){
	ll ans=0;
	rep(i,1,n){
		ll x=a[i]%k;
		ans+=min(x,k-x);
	}
	umin(res,ans);
}
int main() {
	read(n);rep(i,1,n)read(a[i]),a[i]+=a[i-1];
	if(a[n]<=1){puts("-1");return 0;}
	ll x=a[n];
	for(ll i=2;i*i<=x;i++)if(x%i==0){
		ck(i);while(x%i==0)x/=i;
	}
	if(x>1)ck(x);
	cout<<res;
	return 0;
}