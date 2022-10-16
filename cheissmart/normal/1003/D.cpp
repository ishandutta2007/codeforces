#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[200005], n, q;
map<int, int> m;


void solve() {
	map<int, int> mm = m;
	int b, ans = 0;
	cin >> b;
	int c = 0;
	for(int j=40;j>=0;j--) {
		int use = min((b - c) / (1<<j), mm[j]);
		mm[j] -= use;
		ans += use;
		c += (1 << j) * use;
	}
	if(c != b) {
		cout << -1 << endl;
		return;
	}
	cout << ans << endl;
}

int32_t main()
{
	IO_OP;
	
	cin >> n >> q;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		int t = 0;
		while((1LL<<t) < a[i]) t++;
		m[t]++;
	}
	while(q--) {
		solve();
	}

}