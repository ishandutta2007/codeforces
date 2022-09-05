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
const int N = 666666;
int n;Pii a[N];
Pii operator-(Pii a, Pii b){return Pii(a.fi-b.fi,a.se-b.se);}
bool ck(){
	if(n&1)return 0;
	rep(i,1,n/2){
		Pii x=a[i+1]-a[i],y=a[i+n/2]-a[i+n/2+1];
		if(x.fi!=y.fi||x.se!=y.se)return 0;
	}
	return 1;
}
int main() {
	read(n);
	rep(i,1,n)read(a[i].fi),read(a[i].se);
	a[n+1]=a[1];
	if(ck())puts("YES");else puts("NO");
	return 0;
}