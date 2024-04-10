#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 160000;
const ll inf = 1e16;
int n,m,d,a[N],b[N],t[N];
ll f[N][2];
ll q[N],pos[N],F,R;
void ins(ll p, ll v) {
	while (F!=R&&q[R-1]<=v) R--; q[R]=v; pos[R]=p; R++;
}
void era(ll p) {if (F!=R&&pos[F]==p) F++;}
int Abs(int x) {return x>0?x:-x;}
int main() {
	read(n); read(m); read(d);
	rep(i,1,m) read(a[i]),read(b[i]),read(t[i]);
	rep(i,1,n) f[i][1]=-inf;
	rep(j,1,m) { //f[i][j&1]=b[j]-Abs(a[j]-i)+max(f[k][(j&1)^1],i-d*(t[j]-t[j-1])<=k<=i+d*(t[j]-t[j-1]))
		ll len=min(1LL*d*(t[j]-t[j-1]),1LL*n); //i-len<=k<=i+len
		F=0; R=0; rep(i,1,len) ins(i,f[i][(j&1)^1]);
		rep(i,1,n) {
			if (i-len-1>=1) era(i-len-1);
			if (i+len<=n) ins(i+len,f[i+len][(j&1)^1]);
			f[i][j&1]=q[F];
		}
		rep(i,1,n) f[i][j&1]+=b[j]-Abs(a[j]-i),f[i][(j&1)^1]=-inf;
	//	printf("%lld %lld %lld\n",f[20][j&1],f[26][j&1],f[29][j&1]);
	}
	ll ans=-inf; rep(i,1,n) ans=max(ans,f[i][m&1]); cout<<ans;
	return 0;
}