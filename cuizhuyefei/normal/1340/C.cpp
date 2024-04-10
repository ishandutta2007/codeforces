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
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 10005, M = 10005*1003, inf = 0x3f3f3f3f;
int tot,m,d[N],g,r,dis[N][1003];
Pii q[M*2];
int main() {
	read(tot);read(m);
	rep(i,1,m)read(d[i]);
	read(g);read(r);
	sort(d+1,d+m+1);
	memset(dis,inf,sizeof(dis));
	dis[1][0]=0;
	int F=M,R=M+1;q[F]=mp(1,0);
	int res=inf;
	while(F!=R){
		Pii u=q[F++];int x=u.fi,t=u.se;
		if(x>1&&t+d[x]-d[x-1]<=g&&dis[x-1][t+d[x]-d[x-1]]>dis[x][t])
			dis[x-1][t+d[x]-d[x-1]]=dis[x][t],q[--F]=mp(x-1,t+d[x]-d[x-1]);
		if(x+1<=m&&t+d[x+1]-d[x]<=g&&dis[x+1][t+d[x+1]-d[x]]>dis[x][t])
			dis[x+1][t+d[x+1]-d[x]]=dis[x][t],q[--F]=mp(x+1,t+d[x+1]-d[x]);
		if(t==g&&dis[x][0]>dis[x][t]+1)
			dis[x][0]=dis[x][t]+1,q[R++]=mp(x,0);
		if(x==m)umin(res,dis[x][t]*(g+r)+t);
	}
	printf("%d",res<inf?res:-1);
	return 0;
}