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

const int N = 1<<21|3;
int h,need,n,s[N],len,a[N];
bool ck(int u){
	if(!a[u])return 0;
	static int dot[N];int sz=0;
	while(1){
		dot[++sz]=u;
		if(!a[u<<1]&&!a[u<<1|1])break;
		if(a[u<<1]>a[u<<1|1])u=u<<1;else u=u<<1|1;
	}
	if(dot[sz]<(1<<need))return 0;
	s[++len]=dot[1];
	rep(i,1,sz-1)a[dot[i]]=a[dot[i+1]];a[dot[sz]]=0;
	return 1;
}
void solve(int u){
	if(u>n)return;
	while(ck(u));
	solve(u<<1);solve(u<<1|1);
}
int main() {
	int t;read(t);while(t--){
		read(h);read(need);n=(1<<h)-1;len=0;
		rep(i,0,(1<<h+1)-1)a[i]=0;
		rep(i,1,n)read(a[i]);
		solve(1);
		ll sum=0;rep(i,1,(1<<need)-1)sum+=a[i];printf("%lld\n",sum);
		rep(i,1,len)printf("%d ",s[i]);puts("");
	}
	return 0;
}