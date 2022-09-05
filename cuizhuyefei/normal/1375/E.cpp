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

const int N = 1777;
int n,p[N],q[N];Pii a[N];vector<Pii>ans;
int main() {
	read(n);rep(i,1,n)read(p[i]),a[i]=mp(p[i],i);
	sort(a+1,a+n+1);
	rep(i,1,n)p[a[i].se]=i;
	rep(i,1,n)q[p[i]]=i;
	rep(i,1,n)per(j,n-1,i)if(q[j]>q[j+1]){
		int x=q[j],y=q[j+1];
		if(x>y)swap(x,y);
		ans.pb(mp(x,y));
		swap(p[x],p[y]);swap(q[j],q[j+1]);
	}
	printf("%d\n",SZ(ans));
	for(auto x:ans)printf("%d %d\n",x.fi,x.se);
	return 0;
}