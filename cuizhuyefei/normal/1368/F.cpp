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

const int N = 266666;
bool a[N],b[N];int n,k;
int calc(int k){return n-(n+k-1)/k-(k-1);}
int main() {
	read(n);
	k=1;rep(i,2,n)if(calc(i)>calc(k))k=i;
//	cerr<<calc(k)<<' '<<k<<endl;
	rep(i,1,n)a[i]=1;
	for(int i=k;i<=n;i+=k)a[i]=0;a[n]=0;
	int gs=0;while(gs<calc(k)){
		Vi c;rep(i,1,n)if(a[i]&&!b[i]&&SZ(c)<k)c.pb(i);
		assert(k==SZ(c));
		printf("%d ",k);for(int x:c)printf("%d ",x),b[x]=1;
		puts("");fflush(stdout);
		int x;read(x);rep(tt,1,k){b[x]=0;x++;if(x>n)x=1;}
		gs=0;rep(i,1,n)gs+=a[i]&&b[i];
	}
	puts("0");fflush(stdout);
	return 0;
}