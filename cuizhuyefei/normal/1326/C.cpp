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

const int N = 666666,mo=998244353;
int n,k,a[N];ll ans1,ans2=1;
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	rep(i,1,n)cin>>a[i];
	rep(i,n-k+1,n)ans1+=i;
	rep(i,1,n)if(a[i]>=n-k+1){
		int j=i+1;while(j<=n&&a[j]<n-k+1)j++;
		if(j<=n)ans2=1ll*ans2*(j-i)%mo;
	}
	cout<<ans1<<' '<<ans2;
	return 0;
}