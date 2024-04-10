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
const int N = 20200;
int a[N],n,m;Vi b[N];
int main() {
	read(n);read(m);
	while(m--){
		int x,y;read(x);read(y);
		int d=y>=x?y-x:y-x+n;b[x].pb(d);
	}
	rep(i,1,n)sort(b[i].begin(),b[i].end());
	rep(i,1,n)if(SZ(b[i]))a[i]=b[i][0]+n*(SZ(b[i])-1);else a[i]=-1e9;
	rep(i,1,n){
		int res=0;
		for(int j=i,t=0;t<n;t++,j=j+1<=n?j+1:1)umax(res,t+a[j]);
		printf("%d ",res);
	}
	return 0;
}