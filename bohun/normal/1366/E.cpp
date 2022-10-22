#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 5e5 + 101;
const int MOD = 998244353;

int n, m;
int a[N], b[N];
vector <int> vec;

int r[N];

void nope() {
	printf ("0\n");
	exit(0);
}

int main() {
	scanf ("%d%d", &n, &m);
	rep(i, 1, n)
		scanf ("%d", a + i), vec.pb(a[i]);
	rep(i, 1, m)
		scanf ("%d", b + i), vec.pb(b[i]);
	
	sort(all(vec));
	vec.erase(unique(all(vec)), vec.end());
	
	rep(i, 1, n)
		a[i] = (int) (lower_bound(all(vec), a[i]) - vec.begin());
	rep(j, 1, m)
		b[j] = (int) (lower_bound(all(vec), b[j]) - vec.begin());
	
	rep(i, 1, n) {
		r[a[i]] = i;
		if (a[i] < b[1]) {
			nope();
		}
	}
	
	if (r[b[1]] == 0) {
		nope();
	}
		
	int ans = 1;
	rep(i, 1, m - 1) {
		int R = -1;
		rep(j, b[i], b[i + 1] - 1)
			R = max(R, r[j]);
		if (!r[b[i + 1]]) nope();
		int g = max(0, r[b[i + 1]] - R);
		ans = 1LL * ans * g % MOD;
	}
	printf ("%d\n", ans);
		
		
	
	
	return 0;
}