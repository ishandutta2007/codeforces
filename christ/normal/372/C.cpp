// Problem : C. Watching Fireworks is Fun
// Contest : Codeforces Round #219 (Div. 1)
// URL : https://codeforces.com/problemset/problem/372/C
// Memory Limit : 256.000000 MB
// Time Limit : 4000.000000 milisec
// Powered by CP Editor (https://github.com/coder3101/cp-editor)
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll dp[150005];
ll tree[300005]; int n;
void build  () {
	for (int j = n; j < (n << 1); j++) tree[j] = dp[j-n+1];
	for (int j = n-1; j; j--) tree[j] = max(tree[j<<1],tree[j<<1|1]);
}
ll query (int l, int r) {
	ll ret = LLONG_MIN;
	for (l+=n-1,r+=n;l<r;l>>=1,r>>=1) {
		if (l&1) ret = max(ret,tree[l++]);
		if (r&1) ret = max(ret,tree[--r]);
	}
	return ret;
}
int main () {
	int m,d;
	scanf ("%d %d %d",&n,&m,&d);
	int last=0;
	for (int i = 1; i <= m; i++) {
		int a,b,t;
		scanf ("%d %d %d",&a,&b,&t);
		int since = t-last;
		for (int j = 1; j <= n; j++) {
			dp[j] = query(max(1LL,j-(ll)since*d),min((ll)n,j+(ll)since*d))+b-abs(j-a);
		}
		build();
		last = t;
	}
	printf ("%lld\n",query(1,n));
	return 0;
}