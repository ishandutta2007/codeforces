#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 666666;
ll n,q,l,res;
ll b[N],a[N];
void ins(ll p, ll v){
	res-=(a[p-1]==0&&a[p]==1)+(a[p]==0&&a[p+1]==1);
	b[p]=v;a[p]=v>l;
	res+=(a[p-1]==0&&a[p]==1)+(a[p]==0&&a[p+1]==1);
}
int main() {
	read(n);read(q);read(l);rep(i,1,n)read(b[i]);
	rep(i,1,n)ins(i,b[i]);
	while(q--){
		ll op;read(op);
		if(op==0)printf("%lld\n",res);
		else {ll x,y;read(x);read(y);ins(x,b[x]+y);}
	}
	return 0;
}