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
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vi v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	sort(ALL(v));
	for(int i = 0; i < n - 1; i++) if(v[i+1] == v[i] + 1) {
		cout << "YES" << endl;
		return;
	}
	int cnt = 0;
	for(int i = 0; i < n; i++) if(v[i] & 1) cnt++;
	if((cnt & 1) == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
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