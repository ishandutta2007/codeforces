#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); i++)
#define all(x) x.begin(), x..end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
const int N = 200100;
const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	priority_queue<int> a, b;
	vi v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int sum = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		sum += x;
		if(v[i] == 0) a.push(x);
		else b.push(x);
	}
	if(a.empty() || b.empty()) {
		cout << sum << '\n';
		return;
	}
	if(a.top() < b.top()) swap(a, b);
	int x = min((int)a.size(), (int)b.size());
	vi w;
	bool eq = sz(a) == sz(b);
	int y = 0;
	for(int i = 0; i < x; i++) {
		sum += a.top();
		sum += b.top();
		y = min(a.top(), b.top());
		a.pop();
		b.pop();
	}
	if(eq) sum -= y;
	cout << sum << '\n';
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> t;
	while(t--) {
		solve();
	}
}