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
ll n,x;
ll gcd(ll a, ll b){return !b?a:gcd(b,a%b);}
void add(ll y){
	x=gcd(x,y);
}
ll solve(ll X){
	x=X;ll val=n/x;
	for(int i=2;1LL*i*i<=val;i++)if(val%i==0){
		add(i);while(val%i==0)val/=i;
	}
	if(val>1)add(val);
	return x;
}
int main() {
	read(n);
	for(int x=2;1LL*x*x<=n;x++)if(n%x==0){
		cout<<solve(x);return 0;
	}
	cout<<n;
	return 0;
}