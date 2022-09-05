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
typedef vector<ll> Vl;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1<<9|3;
int n,A[N],B[N],q;//ll a[N][N];
int solve(int k, vector<Vl>a){
	if(!k)return a[0][0]>0;
	vector<Vl>f;
	Vl line(1<<k,0);
	rep(i,1,1<<k)f.pb(line);int all=(1<<k)-1;
	rep(tt,1,q){
		int x=A[tt],y=B[tt];
		rep(i,0,all)rep(j,0,all)f[i+x&all][j+y&all]^=a[i][j];
	}
	vector<Vl>b[2][2];
	line.resize(1<<k-1);
	rep(i,1,1<<k-1)b[0][0].pb(line);
	b[0][1]=b[1][0]=b[1][1]=b[0][0];
	rep(i,0,(1<<k)-1)rep(j,0,(1<<k)-1)b[i&1][j&1][i/2][j/2]=f[i][j];
	return solve(k-1,b[0][0])+solve(k-1,b[0][1])+solve(k-1,b[1][0])+solve(k-1,b[1][1]);
}
int main() {
	int k;read(k);int all=(1<<k)-1;
	vector<Vl>f;
	Vl line(1<<k,0);
	rep(i,1,1<<k)f.pb(line);
	rep(i,0,all)rep(j,0,all)read(f[i][j]);
	read(q);rep(i,1,q){
		int x,y;read(x);read(y);x--;y--;A[i]=x;B[i]=y;
	//	rep(i,0,all)rep(j,0,all)f[i+x&all][j+y&all]^=a[i][j];
	}
//	rep(i,0,all){rep(j,0,all)printf("%lld ",f[i][j]);puts("");}
	printf("%d\n",solve(k,f));
	return 0;
}