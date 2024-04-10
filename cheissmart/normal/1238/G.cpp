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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

struct s{
	int t, a, b;
	bool operator<(const s tt) const{
		return t < tt.t;
	}
} a[500005];

void solve() {
	int n, m, c, c0, ans = 0, sum = 0, last = 0;
	cin >> n >> m >> c >> c0;
	for(int i=0;i<n;i++) 
		cin >> a[i].t >> a[i].a >> a[i].b;
	sort(a, a+n);
	a[n++] = {m, 0, INF};
	map<int, int> s;
	s[0] = c0;
	sum = c0;
	for(int i=0;i<n;i++) {
		while(last < a[i].t) {
			if(s.empty()) {
				cout << -1 << endl;
				return;
			}
			int k = s.begin()->F;
			int d = min(a[i].t - last, s[k]);
			s[k] -= d;
			sum -= d;
			last += d;
			ans += k * d;
			if(s[k] == 0) s.erase(k); 
		}
		sum += a[i].a;
		s[a[i].b] += a[i].a;
		while(sum > c) {
			int k = s.rbegin()->F;
			int d = min(sum - c, s[k]);
			s[k] -= d;
			sum -= d; 
			if(s[k] == 0) s.erase(k); 
		}
	}
	cout << ans << endl;
}

int32_t main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		solve();
	}	
	
}