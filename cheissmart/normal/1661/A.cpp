#include <bits/stdc++.h>
#define IO_OP ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;
const ll oo = 1e18;

void solve() {
	int n;
	cin >> n;
	vi a(n), b(n);	
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	ll ans = 0;
	for(int i = 1; i < n; i++) {
		if(abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]) > abs(a[i] - b[i - 1]) + abs(b[i] - a[i - 1]))
			swap(a[i], b[i]);
		ans += abs(a[i] - a[i - 1]);
		ans += abs(b[i] - b[i - 1]);
	}
	cout << ans << '\n';	
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	
}