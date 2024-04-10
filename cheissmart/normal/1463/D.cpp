#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int n;

vi go(vi a, vi b) {
	vi ans(n + 1);
	int lb = 0, rb = n;
	while(lb <= rb) {
		int mb = (lb + rb) / 2;
		bool ok = true;
		for(int i = 0; i < mb; i++) {
			if(a[i] > b[mb - i - 1]) ok = false;
		}
		if(ok) lb = mb + 1;
		else rb = mb - 1;
	}
	for(int i = 0; i <= rb; i++) ans[i] = 1;
	return ans;
}

void solve() {
	cin >> n;
	vi yes(n * 2 + 1);
	vi a(n), b;
	for(int i = 0; i < n; i++) cin >> a[i], yes[a[i]] = 1;
	for(int i = n * 2; i >= 1; i--) if(!yes[i]) b.PB(i);
	// a is increasing, b is decreasing
	vi x = go(a, b);
	reverse(ALL(a)), reverse(ALL(b));
	vi y = go(b, a);
	int ans = 0;
	for(int i = 0; i <= n; i++) {
		if(x[i] && y[n - i]) ans++;
	}
	cout << ans << '\n';
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) solve();

}