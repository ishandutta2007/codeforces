#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register ll i=a; i<=b; i++)
#define per(i,a,b) for (register ll i=a; i>=b; i--)
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
ll n,P,Q,k,l,res=-1;
//sum=k+1 && y
int main() {
	read(n);read(P);read(Q);read(k);l=Q-P+1;if(l<=0)l+=n;
	if(n<=3000000){
		rep(x,0,n){
			ll y=(k-l)%(n+x),a=(k-l)/(n+x);
			if(y<=l&&y<=x&&x-y<=n-l&&k-l>=0&&x>=0&&y>=0&&a>=0)res=max(res,x);
		}
		k++;
		rep(x,0,n){
			ll y=(k-l)%(n+x),a=(k-l)/(n+x);
			if(y<=l&&y<=x&&x-y<=n-l&&k-l>=0&&x>=0&&y>0&&a>=0)res=max(res,x);
		}
		cout<<res;
		return 0;
	}
	rep(a,1,k/n){
		ll c=k-l-a*n;//ax+y=c
		if(c<0)continue;
		ll x=c/a,y=c-a*x;
		if(y<0){
			ll xs=-y/a;x-=xs;y+=xs*a;
			while(y<0)x--,y+=a;
		}
		if(x-y>n-l){
			ll xs=(x-y-(n-l))/(a+1);x-=xs;y+=xs*a;
			while(x-y>n-l)x--,y+=a;
		}
		if(x>=0&&y>=0&&y<=l&&x-y>=0&&x-y<=n-l)res=max(res,x);
	}
	ll y=k-l,x=y+n-l;
	if(x>=0&&y>=0&&y<=l&&x-y>=0&&x-y<=n-l)res=max(res,x);
	k++;
	rep(a,1,k/n){
		ll c=k-l-a*n;//ax+y=c
		if(c<0)continue;
		ll x=c/a,y=c-a*x;
		if(y<=0){
			ll xs=-y/a;x-=xs;y+=xs*a;
			while(y<=0)x--,y+=a;
		}
		if(x-y>n-l){
			ll xs=(x-y-(n-l))/(a+1);x-=xs;y+=xs*a;
			while(x-y>n-l)x--,y+=a;//WA
		}
		if(x>=0&&y>0&&y<=l&&x-y>=0&&x-y<=n-l)res=max(res,x);
	}
	y=k-l,x=y+n-l;
	if(x>=0&&y>=0&&y<=l&&x-y>=0&&x-y<=n-l)res=max(res,x);
	cout<<res;return 0;
}