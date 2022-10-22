#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define vi vector <int>

using namespace std;			

int n;
map<int, int> x, y;
map<pair<int, int>, int> k;
int a, b;

int main() {	
	scanf ("%d", &n);
	rep(i, 1, n) {
		scanf ("%d%d", &a, &b);
		k[{a, b}] += 1;
		x[a] += 1;
		y[b] += 1;
	}
	LL ans = 0;
	for (auto it : x)
		ans += (LL) it.se * (it.se - 1) / 2;
	for (auto it : y)
		ans += (LL) it.se * (it.se - 1) / 2;
	for (auto it : k)
		ans -= (LL) it.se * (it.se - 1) / 2;
	printf ("%lld\n", ans);
	
	return 0;
}