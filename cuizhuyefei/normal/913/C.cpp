#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 55;
int n,m,v[N];
ll ans;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline ll dp(int m) {
    if (!m) return 0;
	per(k,30,0) if ((m>>k)&1) {
		ll mn=3e18,mn1=3e18;
		rep(i,k+1,n-1) mn=min(mn,v[i]);
		rep(i,0,min(k,n-1)) mn1=min(mn1,1LL*v[i]*(1<<k-i));
		return min(mn,mn1+dp(m-(1<<k)));
	}
}
int main() {
	read(n); read(m); rep(i,0,n-1) read(v[i]);
	/*rep(k,0,30) if ((m>>k)&1) {
		int mx=min(n-1,k);
		ll mn=1e11;
		rep(i,0,mx) mn=min(mn,1LL*v[i]*(1<<k-i));
		rep(i,mx+1,n-1) mn=min(mn,v[i]);
		ans+=mn;
	}*/
	cout<<dp(m);
	return 0;
}