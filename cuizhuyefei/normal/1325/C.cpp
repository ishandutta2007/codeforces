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
mt19937 R(chrono::system_clock().now().time_since_epoch().count());
const int N = 666666;
int ans[N],tot,n,A[N],B[N];Vi e[N];
void put(int x){if(ans[x]==-1)ans[x]=tot++;}
void print(){rep(i,1,n-1)printf("%d\n",ans[i]);exit(0);}
int main() {
	memset(ans,-1,sizeof(ans));
	read(n);rep(i,1,n-1){int u,v;read(u);read(v);e[u].pb(i);e[v].pb(i);A[i]=u;B[i]=v;}
	rep(i,1,n)if(SZ(e[i])>=3){
		for(int j:e[i])put(j);
		rep(j,1,n-1)put(j);
		print();return 0;
	}
	rep(i,1,n-1)put(i);print();
	return 0;
}