#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
void exgcd(ll a, ll b, ll &x, ll &y) {
	if (!b) {x=1; y=0; return;}
	exgcd(b,a%b,y,x); y-=a/b*x;
}
ll gcd(ll a, ll b) {return !b ? a : gcd(b,a%b);}
int x,y,p,q;
/*ll solve() {
//	ll A=p-q,B=p
	if (p-q==0) {
		ll a=1LL*q*x-1LL*p*y;
		if (a%p!=0||a/p<0) return -1;
		return a/p;
	}
	if (p==0) {
		ll a=1LL*q*x-1LL*p*y;
		if (a%(p-q)!=0||a/(p-q)<0) return -1;
		return a/(p-q);
	}
	ll a,b; exgcd(p-q,p,a,b);
	
}*/
ll solve() {
	if (p==0) {
		return x>0?-1:0;
	}
	if (p==q) {
		return x!=y?-1:0;
	}
	ll t=max(max((y+q-1)/q,(y-x+q-p-1)/(q-p)),(x+p-1)/p);
	return q*t-y;
}
int main() {
	int t; read(t);
	while (t--) {
		read(x);read(y);read(p);read(q);
		printf("%lld\n",solve());
	}
	return 0;
}