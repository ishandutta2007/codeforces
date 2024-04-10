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

int n, m;
ll a[105], less_cnt;

bool ok(ll mb) {
	ll cnt = mb;
	for(int i = 0; i < n; i++) if(a[i] < mb) cnt--;
	return cnt > less_cnt;
}

void solve() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		ll mask = 0;
		for(int j = 0; j < m; j++) {
			if(s[j] == '1') mask |= 1LL << (m - j - 1);
		}
		a[i] = mask;
	}
	less_cnt = ((1LL << m) - n - 1) / 2;
	ll lb = 0, rb = (1LL << m) - 1;
	while(lb <= rb) {
		ll mb = (lb + rb) / 2;
		if(ok(mb)) rb = mb - 1;
		else lb = mb + 1;
	}
	lb--;
	for(int i = 0; i < m; i++) {
		cout << char((lb >> (m-i-1) & 1) + '0');
	}
	cout << '\n';
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) solve();
	
}