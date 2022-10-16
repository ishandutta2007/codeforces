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


void solve2() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int cnt = 0;
	V<pair<char, int>> ans;
	while(true) {
		if(a == c && b == d) break;
		if(a == d && b == c) {
			ans.EB('R', 1);
			break;
		}
		if(min(c, d) < min(a, b) || c == d) {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
		if(c > d) {
			swap(c, d);
			ans.EB('R', 1);
		}
		if(c == a || c == b) {
			if(c == a) {
				if((d - b) % c == 0) {
					ans.EB('P', (d - b) / c);
					cnt += (d - b) / c;
					d = b;
				} else {
					cout << "IMPOSSIBLE" << endl;
					return;
				}
			} else {
				if((d - a) % c == 0) {
					ans.EB('P', (d - a) / c);
					cnt += (d - a) / c;
					d = a;
				} else {
					cout << "IMPOSSIBLE" << endl;
					return;
				}
			}
		} else {
			ans.EB('P', d / c);
			cnt += d / c;
			d %= c;
		}
	}
	reverse(ALL(ans));
	if(cnt <= 200000) {
		cout << "SMALL" << endl;
		string s;
		for(auto p:ans) {
			for(int i = 0; i < p.S; i++)
				s.PB(p.F);
		}
		cout << s.size() << endl;
		cout << s << endl;
	} else {
		cout << "BIG" << endl;
		cout << cnt << endl;
	}
}

bool ok(vi& b) {
	for(int i = 0; i < b.size() - 1; i++)
		if(b[i] >= b[i + 1])
			return false;
	return true;
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	if(n == 1) {
		int a, b;
		cin >> a >> b;
		if(a == b) cout << "SMALL\n0\n";
		else cout << "IMPOSSIBLE\n";
		return 0;
	}
	if(n == 2) {
		solve2();
		return 0;
	}
	vi a(n), b(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	int cnt = 0;
	string ans;
	while(true) {
		if(b == a) break;
		reverse(ALL(b));
		if(b == a) {
			ans.PB('R');
			break;
		}
		reverse(ALL(b));
		if(!ok(b)) {
			reverse(ALL(b));
			ans.PB('R');
		}
		if(!ok(b)) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		cnt++;
		for(int i = n - 1; i > 0; i--) b[i] -= b[i - 1];
		ans.PB('P');
	}
	reverse(ALL(ans));
	if(cnt <= 200000) {
		cout << "SMALL" << endl;
		cout << ans.size() << endl;
		cout << ans << endl;
	} else {
		cout << "BIG" << endl;
		cout << cnt << endl;
	}
}