#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+(c&15), c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=5007;
const ll INF=1e18;
int n, m, x, y, p[N];
ll f[N][N];
char a[N], b[N];
inline void work() {
	n=read(), x=read(), y=read();
	scanf("%s%s", a+1, b+1), m=0;
	for (int i=1; i<=n; i++) if (a[i]^b[i]) p[++m]=i;
	if (m&1) {puts("-1"); return;}
	if (y<=x) {
		if (m!=2) printf("%lld\n", (ll)m/2*y);
		else if (p[1]+1!=p[2]) printf("%d\n", y);
		else printf("%d\n", min(y<<1, x));
		return;
	}
	ll ans=0;
	for (int i=1; i<=m; i+=2)
		ans+=min((ll)y, (ll)(p[i+1]-p[i])*x);
	ll res=0; int cnt=0;
	for (int i=1; i<m; i++) if (p[i]+1==p[i+1]) res+=x, cnt+=2, i++;
	res+=(ll)(m-cnt)/2*y, ckmin(ans, res);
	for (int i=0; i<=m; i++)
		for (int j=0; j<=i; j++) f[i][j]=INF;
	f[0][0]=0;
	for (int i=1; i<=m; i++)
		for (int j=0; j<i; j++) {
			if (j<=i-2) ckmin(f[i][j], f[i-2][j]+min((ll)y, (ll)(p[i]-p[i-1])*x));
			if (!j) ckmin(f[i][i], f[i-1][j]);
			else ckmin(f[i][0], f[i-1][j]+min((ll)y, (ll)(p[i]-p[j])*x));
		}
	ckmin(ans, f[m][0]);
	printf("%lld\n", ans);
}
int main() {
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	for (int T=read(); T; T--) work();
	return 0;
}