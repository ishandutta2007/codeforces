#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define LL long long
#define LD long double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);


using namespace std;		

const int nax = 220;
const int mod = 998244353;

void add(int &a, int b) {
	a += b;
	if (a >= mod) 
		a -= mod;
}

LL pt(LL a, LL b) {
	if (b == 0) return 1;
	if (b & 1) return a * pt(a, b - 1) % mod;
	return pt(a * a % mod, b / 2);
}

int n;
int l[nax];
int r[nax];

vector <int> v;
vector <pair<int, int>> p;
int dl[nax];

int t[nax][nax];
int dp[nax][nax];

bool in(int a, int b) {
	return l[a] <= p[b].fi && p[b].se <= r[a];
}

int main() {	
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d %d", l + i, r + i);
		v.pb(l[i]);
		v.pb(r[i]);
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	for (int i = 0; i < ss(v); ++i) {
		p.pb({v[i], v[i]});
		if (i + 1 != ss(v) && v[i + 1] != v[i] + 1)
			p.pb({v[i] + 1, v[i + 1] - 1});
	}
	
	for (int i = 0; i < ss(p); ++i)
		dl[i] = p[i].se - p[i].fi + 1;
		
	
	for (int i = 0; i < ss(p); ++i) {
		for (int j = 1; j <= n; ++j) {
			int res = 1;
			for (int k = dl[i]; k <= dl[i] + j - 1; ++k)
				res = (LL) res * k % mod;
			for (int k = 2; k <= j; ++k)
				res = (LL) res * pt(k, mod - 2) % mod;
			t[i][j] = res;
		}
	}
	
	for (int i = 0; i < ss(p); ++i) 
		dp[1][i] = in(1, i);
	
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = ss(p) - 1; 0 <= j; --j) {
			if (i > 1) add(dp[i][j], dp[i][j + 1]);
			if (!in(i, j)) continue;
			for (int k = 1; k <= n; ++k) {
				if (i + k > n + 1) break;
				if (!in(i + k - 1, j)) break;
				int ways = (LL) dp[i][j] * t[j][k] % mod; 
				if (i + k == n + 1) {
					add(ans, ways);
					continue;
				}
				if (!j) continue;
				add(dp[i + k][j - 1], ways);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		ans = (LL) ans * pt(r[i] - l[i] + 1, mod - 2) % mod;
	printf ("%d\n", ans);		
	
	return 0;
}