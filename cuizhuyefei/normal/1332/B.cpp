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

const int N = 66666;
Vi p={2,3,5,7,11,13,17,19,23,29,31};
int n,a[N],b[N];
int main() {
	
	int t;read(t);while(t--){
		read(n);rep(i,1,n)read(a[i]);
		map<int,int>Map;int tot=0;
		rep(i,1,n){
			int x=2;while(a[i]%x)x++;
			if(!Map[x])Map[x]=++tot;b[i]=Map[x];
		}
		printf("%d\n",tot);
		rep(i,1,n)printf("%d ",b[i]);puts("");
	}
	return 0;
}