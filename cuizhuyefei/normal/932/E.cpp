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
const int N = 5050, mo = 1e9+7;


inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
int n,k,s[N][N],fac[N];

inline void exgcd(int a, int b, int &x, int &y) {
	if (!b) {x=1; y=0; return;}
	exgcd(b,a%b,y,x); y-=a/b*x;
}
inline int inv(int a) {int x,y; exgcd(a,mo,x,y); return x>=0?x:x+mo;}
inline int power(int a, int n) {
	if (n<0) return 0; //??????????????????????
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo;
		n>>=1;
	}
	return res;
}
inline int C(int n, int m) {
	int res=1,res1=1;
	rep(i,1,m) {res=1LL*res*(n-i+1)%mo; res1=1LL*res1*i%mo;}
	return 1LL*res*inv(res1)%mo;
}
int main() { //freopen("1.in","r",stdin);
	read(n); read(k); ll ans=0;
	s[0][0]=1;
	rep(i,1,k) rep(j,1,i) s[i][j]=(s[i-1][j-1]+1LL*s[i-1][j]*j)%mo;
	fac[0]=1; rep(i,1,k) fac[i]=1LL*fac[i-1]*i%mo;
	rep(j,0,k) {
		ll tmp=1LL*s[k][j]*fac[j]%mo; tmp=tmp*power(2,n-j)%mo;
		tmp=tmp*C(n,j)%mo;
		ans+=tmp; //printf("%d\n",s[k][j]);
	}
	printf("%lld",ans%mo);
	return 0;
}