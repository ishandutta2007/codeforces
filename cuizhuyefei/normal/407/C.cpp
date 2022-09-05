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
#define SZ(x) (int(x.size()))
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
const int N = 200002, mo = 1e9+7;
int n,m,C[102000][105]; ll a[N];
struct node {int l,r,m;};
vector<node> q,Q;
void trans(ll *a) {
	if (!SZ(q)) return;
	per(i,n,1) a[i]=(a[i]-a[i-1]+mo)%mo;
	per(i,SZ(q)-1,0) (a[q[i].r+1]+=mo-C[q[i].m+q[i].r-q[i].l][q[i].m])%=mo;
	per(i,SZ(q)-1,0) if (q[i].m==0) a[q[i].l]++;
//	vector<node> Q;
	Q.clear(); per(i,SZ(q)-1,0) if (q[i].m-1>=0) Q.push_back((node){q[i].l,q[i].r,q[i].m-1}); q=Q;
	trans(a);
	rep(i,1,n) a[i]=(a[i]+a[i-1])%mo;
}
int main() {
	read(n); read(m); rep(i,1,n) scanf("%lld",&a[i]);
	rep(i,1,m) {
		int l,r,x; read(l); read(r); read(x);
		q.push_back((node){l,r,x});
	}
//	rep(i,1,n+100) C[0][0]=1;
	C[0][0]=1;
	rep(i,1,n+100) {
		C[i][0]=1;
		rep(j,1,100) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	}
	trans(a);
	rep(i,1,n) printf("%lld ",(a[i]%mo+mo)%mo);
	return 0;
}