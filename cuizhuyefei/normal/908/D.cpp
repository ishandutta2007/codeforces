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
const int N = 2350, mo = 1e9+7;
int k,a,b,tot,intot;
int f[N][N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline void exgcd(int a, int b, int &x, int &y) {
	if (!b) {x=1; y=0; return;}
	exgcd(b,a%b,y,x); y-=a/b*x;
}
inline int inv(int a) {int x,y; exgcd(a,mo,x,y); return x>=0 ? x : x+mo;}
int main() { //freopen("1.in","r",stdin);
	read(k); read(a); read(b); tot=a+b; intot=inv(tot);
	rep(i,1,k) rep(j,k,k*2) f[i][j]=j;
	f[k][0]=(k+1LL*a*inv(b)%mo)%mo;
	rep(i,1,k-1) f[k][i]=(f[k][0]+i)%mo;
	per(i,k-1,1) per(j,k-1,0) {
		if (i>0) {
			f[i][j]=1LL*a*intot%mo*f[i+1][j]%mo+1LL*b*intot%mo*f[i][i+j]%mo;
			f[i][j]%=mo;
		}
	} printf("%d",f[1][0]);
	return 0;
}