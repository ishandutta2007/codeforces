#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
 
using ll = long long;
using ld = long double;
using namespace std;		

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
 
#define ull unsigned long long
 
const int N = 5e5 + 5;
 
vector <int> occur[N];
int n, L;
ull r[N], H[N], ans;
map <ull, int> m;
 
int main() {
	srand(time(NULL));
	scanf ("%d", &n);
	rep(i, 1, n) 
		r[i] = uniform_int_distribution<ull>(0, 1e18)(rng);
	m[0]++;
	rep(i, 1, n) {
		int x;
		scanf ("%d", &x);
		occur[x].pb(i);
		H[i] = H[i - 1] + (sz(occur[x]) % 3 ? x[r] : -2 * x[r]);
		if (sz(occur[x]) >= 4)
			while (L + 1 <= occur[x][sz(occur[x]) - 4]) 
				m[H[L++]]--;
		ans += m[H[i]]++;
	}
	printf ("%llu\n", ans);
	return 0;
}