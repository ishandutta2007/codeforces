#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

void solve() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	if(n * a != m * b) {
		cout << "NO" << endl;
		return;
	}
	V<vi> v(n, vi(m));
	vi cnt(m);
	queue<int> q;
	for(int i = 0; i < m; i++) q.push(i);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < a; j++) {
			int k = q.front(); q.pop();
			cnt[k]++;
			v[i][k] = 1;
			if(cnt[k] < b) q.push(k);
		}
	}
	cout << "YES" << endl;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) cout << v[i][j];
		cout << endl;
	}
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) solve();	
	
}