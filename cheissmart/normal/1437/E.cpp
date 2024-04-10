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

const int INF = 1e9 + 7, N = 5e5 + 7;

int a[N];

int go(int l, int r) {
	vi v;
	for(int i = l + 1; i < r; i++) {
		if(a[i] < a[l] || a[i] > a[r]) continue;
		if(v.empty() || a[i] >= v.back()) v.PB(a[i]);
		else *upper_bound(ALL(v), a[i]) = a[i];
	}
	return r - l - 1 - v.size();
}

signed main()
{
	IO_OP;

	int n, k;
	cin >> n >> k;
	a[0] = -INF;
	a[n + 1] = INF;
	for(int i = 1; i <= n; i++) cin >> a[i], a[i] -= i;
	vi b;
	b.PB(0);
	for(int i = 0; i < k; i++) {
		int x;
		cin >> x;
		b.PB(x);
	}
	b.PB(n + 1);
	int ans = 0;
	for(int i = 0; i < b.size() - 1; i++) {
		if(a[b[i]] > a[b[i + 1]]) {
			cout << -1 << endl;
			return 0;
		}
		ans += go(b[i], b[i + 1]);
	}
	cout << ans << endl;

}