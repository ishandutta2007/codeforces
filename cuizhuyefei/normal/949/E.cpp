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
const int N = 666666;
inline Vi solve(int bit, Vi a){
	if(a.empty())return {};
	if(SZ(a)==1&&a[0]==1)return {bit};
	if(SZ(a)==1&&a[0]==-1)return {-bit};
	bool fd=0;rep(i,0,SZ(a)-1)fd|=a[i]&1;
	if(!fd){rep(i,0,SZ(a)-1)a[i]>>=1;return solve(bit<<1,a);}
	Vi b;rep(i,0,SZ(a)-1)if(a[i]){//+1<<bit
		if(!(a[i]&1))b.pb(a[i]>>1);else if(a[i]-1)b.pb((a[i]-1)>>1);
	}
	sort(b.begin(),b.end());b.erase(unique(b.begin(),b.end()),b.end());
	Vi B=solve(bit<<1,b);B.pb(bit);
	Vi c;rep(i,0,SZ(a)-1)if(a[i]){//-1<<bit
		if(!(a[i]&1))c.pb(a[i]>>1);else if(a[i]+1)c.pb((a[i]+1)>>1);
	}
	sort(c.begin(),c.end());c.erase(unique(c.begin(),c.end()),c.end());
	Vi C=solve(bit<<1,c);C.pb(-(bit));
	return SZ(B)<SZ(C)?B:C;
}
int main() {
	int n,x;read(n);Vi b;rep(i,1,n){read(x);if(x)b.pb(x);}
	sort(b.begin(),b.end());Vi res=solve(1,b);
	printf("%d\n",SZ(res));rep(i,0,SZ(res)-1)printf("%d ",res[i]);
	return 0;
}