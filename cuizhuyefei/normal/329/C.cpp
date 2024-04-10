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
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 666666;
int n,m,s[N];Vi e[N];bool ok[N];
bool ck(int u, int v){
	for(int x:e[u])if(x==v)return 0;
	return 1;
}
int main() {
	read(n);read(m);
	rep(i,1,m){int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);}
	rep(i,1,n)s[i]=i;
	rep(t,1,100){
		rep(i,1,n)swap(s[i],s[R()%n+1]),ok[i]=0;int cnt=0;
		rep(i,1,n)ok[i]=ck(s[i],s[i<n?i+1:1]),cnt+=ok[i];
		if(cnt>=m){
			cnt=m;
			rep(i,1,n)if(ok[i]&&cnt)
				cnt--,printf("%d %d\n",s[i],s[i<n?i+1:1]);
			return 0;
		}
	}
	puts("-1");
	return 0;
}