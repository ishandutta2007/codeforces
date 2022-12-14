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

int solve(vi a, vi b) {
	int n = a.size(), m = b.size();
	if(n == 0 || m == 0) return 0;
	vi yes(n), aux(n);
	for(int i = 0; i < n; i++)
		aux[i] = a[i] - i;
	for(int i = n - 1; i >= 0; i--) {
		int pos = lower_bound(ALL(b), a[i]) - b.begin();
		if(pos < m && b[pos] == a[i])
			yes[i]++;
		if(i + 1 < n)
			yes[i] += yes[i + 1];
	}
	int ans = yes[0];
	for(int i = 0; i < m; i++) {
		// move to b[i] - 1
		int x = b[i] - 1;
		// aux[j] <= x
		int pos = upper_bound(ALL(aux), x) - aux.begin();
		if(pos) {
			pos--;
			// 0, ... pos
			int cans = 0;
			if(pos + 1 < n) 
				cans += yes[pos + 1];
			int l = b[i], r = b[i] + pos; // [l, r] 
			cans += upper_bound(ALL(b), r) - upper_bound(ALL(b), l - 1);
			ans = max(ans, cans);
		}
	}
	return ans;
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vi a1, a2, b1, b2;
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if(x < 0) a1.PB(-x);
			else a2.PB(x);
		}
		reverse(ALL(a1));
		for(int i = 0; i < m; i++) {
			int x;
			cin >> x;
			if(x < 0) b1.PB(-x);
			else b2.PB(x);
		}
		reverse(ALL(b1));
		int ans = solve(a1, b1) + solve(a2, b2);
		cout << ans << '\n';
	}

}