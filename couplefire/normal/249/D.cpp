#include<bits/stdc++.h>
 
#define x first
#define y second
 
using namespace std;
 
typedef double DO;
typedef long long INT;
typedef pair<INT, INT> pii;
 
template<typename T, typename U> inline void smin(T &a, U b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, U b) {if(a<b) a=b;}
 
template<class T>inline void gn(T &x) {char c, sg=0; while (c=getchar(), (c>'9' || c<'0') && c!='-');for((c=='-'?sg=1, c=getchar():0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;}
 
#define NN 100011
pii p[NN];
int n;
int a, b, c, d;
INT arr[NN];
INT dp[NN];
 
void solve() {
	cin >> n;
	scanf(" %d / %d %d / %d", &a, &b, &c, &d);
	for(int i=1; i<=n; i++) {
		int u, v; gn(u); gn(v);
		p[i] = pii((INT)c * u - (INT)d * v, (INT)b * v - (INT)a * u);
	}
	sort(p+1, p+n+1, [&] (pii u, pii v) {
		if(u.x == v.x) return u.y > v.y;
		return u.x < v.x;	
	});
	int nn=0;
	for(int i=1; i<=n; i++) {
		arr[nn++] = p[i].y;
		if(p[i].x < 0) arr[nn-1] = 0;
	}
	int ans=0;
	for(int i=0; i<=nn+2; i++) dp[i] = 1e18;
	for(int i=0; i<nn; i++) {
		if(arr[i]<=0) continue;
		int id = lower_bound(dp, dp+nn, arr[i]) - dp;
		dp[id] = arr[i];
		smax(ans, id+1);
	}
	cout << ans << endl;
}
 
int main() {
	solve();
	return 0;
}