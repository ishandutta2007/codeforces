#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
using ui = unsigned int;
using ull = unsigned long long;
using ui128 = __uint128_t;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e6 + 2, LOG = 21, INF = 1e8;
int check (int take, vector<int> a, vector<int> b) {
	a[1] -= take; b[1] -= take; int n = a.size() - 1;
	for (int i = 2; i <= n; i++) {
		a[i] -= b[i-1]; int take = max(min(a[i],b[i]),0);
		 a[i] -= take; b[i] -= take;
		if (a[i] > 0) return -1;
	}
	a[1] -= b[n];
	return a[1] <= 0;
}
void solve () {
	int n;
	scanf ("%d",&n);
	vector<int> a(n+1), b(n+1);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]);
	for (int i = 1; i <= n; i++) scanf ("%d",&b[i]);
	int low = 0, high = b[1], mid;
	while (low <= high) {
		mid = (low + high) / 2;
		int go = check(mid,a,b);
		if (go == 1) return (void) printf ("YES\n");
		else if (go == 0) low = mid + 1;
		else high = mid - 1;
	}
	printf ("NO\n");
}
int main () { 
	int t;
	scanf ("%d",&t);
	while (t--) solve();
    return 0;
}