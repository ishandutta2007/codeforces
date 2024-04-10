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
const int N = 900000;


inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
ll p,k,a[N],f[N];
int main() {
	read(p); read(k); int d;
	rep(i,0,N-1) {
		a[i]=-p/k;
		while (p+k*a[i]<0) a[i]++;
		while (p+k*a[i]>=k) a[i]--;
		f[i]=p+k*a[i]; p=a[i]; if (!p) {d=i; break;}
	}
	printf("%d\n",d+1);
	rep(i,0,d) printf("%lld ",f[i]);
	return 0;
}