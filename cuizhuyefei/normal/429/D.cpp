#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
const int N = 300003;
int n,a[N];
ll ans=2e18;
struct dot {
	int x,y;
	dot(int X=0, int Y=0) {x=X; y=Y;}
} s[N],t[N];
bool cmp(dot a, dot b) {return a.y<b.y;}
bool cmp1(dot a, dot b) {return a.x!=b.x?a.x<b.x:a.y<b.y;}
bool cmp2(dot a, dot b) {return a.y!=b.y?a.y<b.y:a.x<a.x;}
ll sqr(ll x){return x*x;}
inline void solve(int l, int r) {
	if (l>=r) return;
//	sort(s+l,s+r+1,cmp1);
	int mid=(l+r)>>1;
	solve(l,mid); solve(mid+1,r);
	int len=0; ll mx=sqrt(ans);
	rep(i,l,r) if (abs(s[i].x-s[mid].x)<=mx) t[++len]=s[i];
	sort(t+1,t+len+1,cmp);
	rep(i,1,len) rep(j,i+1,len) {
		ans=min(ans,sqr(t[j].x-t[i].x)+sqr(t[j].y-t[i].y));
		if (t[j].y-t[i].y>mx) break;
	}
}
int main() { //freopen("1.in","r",stdin);
	read(n); rep(i,1,n) {int x;read(x);a[i]=a[i-1]+x; s[i]=dot(i,a[i]);}
	sort(s+1,s+n+1,cmp1);
	solve(1,n);
	printf("%lld",ans);
	return 0;
}