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
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline void read(ui &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 10200000;
const ll inf = 6e18;
int n,l,r;ll a[N];
ui x,y,z,b[N];
int main() {
	int T;read(T);
	while(T--){
		read(n);read(l);read(r);read(x);read(y);read(z);
		read(b[1]);read(b[2]);
		rep(i,3,n)b[i]=b[i-2]*x+b[i-1]*y+z;
		rep(i,1,n)a[i]=1LL*b[i]%(1LL*r-l+1)+l;
		bool gg=1;rep(i,1,n-1)gg&=a[i]>=a[i+1];
		if(gg){puts("IMPOSSIBLE");continue;}
		ll res=inf,mn=inf;
		rep(i,1,n){
			mn=min(mn,a[i]);if(a[i]>=0&&mn<=0&&mn<a[i])res=min(res,a[i]*mn);
		}
		if(res<=0){printf("%lld\n",res);continue;}
		int p=0;while(p+1<=n&&a[p+1]>0)p++;//[1,p] [p+1,n]
		mn=inf;
		rep(i,1,p){mn=min(mn,a[i]);if(a[i]>mn)res=min(res,a[i]*mn);}
		mn=inf;
		rep(i,p+1,n)a[i]=-a[i];
		per(i,n,p+1){mn=min(mn,a[i]);if(a[i]>mn)res=min(res,a[i]*mn);}
		printf("%lld\n",res);
	}
	return 0;
}