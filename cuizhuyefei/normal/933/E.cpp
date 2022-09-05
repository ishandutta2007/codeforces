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
const int N = 366666;const ll inf=1e18;
int n,a[N];Vi ans;ll dp[N],pre[N];
void ope(int x){ans.pb(x);int y=min(a[x],a[x+1]);a[x]-=y;a[x+1]-=y;}
void solve(int p){
	if(a[p]&&a[p-1])ope(p-1);
	if(a[p]&&a[p+1])ope(p);
}
void solve(int p, int q){
	if(a[p]&&a[q])ope(p);
	if(a[p-1]&&a[p])ope(p-1);
	if(a[q]&&a[q+1])ope(q);
}
int main() {
	read(n);rep(i,1,n)read(a[i]);
	rep(i,0,n+2)dp[i]=inf;dp[0]=0;
	rep(i,1,n){
		ll x=dp[max(i-2,0)]+a[i-1];
		ll y=i-3>=0?dp[max(i-3,0)]+max(a[i-1],a[i-2]):inf;
		dp[i]=min(x,y);pre[i]=x<=y?2:3;
	}
	int p=n;
	if(dp[n-1]+a[n]<dp[n]){p=n-1;solve(n);}
	while(p>0){
		if(pre[p]==2)solve(p-1),p=max(p-2,0);
		else solve(p-2,p-1),p-=3;
	}
	printf("%d\n",SZ(ans));
	for(int x:ans)printf("%d\n",x);
	return 0;
}