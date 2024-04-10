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

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	V<vi> a(n, vi(m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	auto out = [&] (vi a) {
		cout << "Yes\n";
		for(int i:a) cout << i << " ";
		cout << '\n';
		exit(0);
	};
	for(int i = 1; i < n; i++) {
		vi diff;
		for(int j = 0; j < m; j++)
			if(a[i][j] != a[0][j])
				diff.PB(j);
		if(diff.size() >= 5) {
			cout << "No\n";
			return 0;
		}
		if(diff.size() == 4) {
			auto ok = [&] (vi b) {
				for(int i = 0; i < n; i++) {
					int cnt = 0;
					for(int j = 0; j < m; j++) {
						if(a[i][j] != b[j])
							cnt++;
					}
					if(cnt > 2) return false;
				}
				return true;
			};
			for(int c0 = 0; c0 < 4; c0++) {
				for(int c1 = 0; c1 < c0; c1++) {
					vi b = a[0];
					b[diff[c0]] = a[i][diff[c0]];
					b[diff[c1]] = a[i][diff[c1]];
					if(ok(b)) out(b);
				}
			}
			cout << "No\n";
			return 0;
		} else if(diff.size() == 3) {
			auto ok = [&] (vi& b, int k) {
				unordered_set<int> s;
				for(int i = 0; i < n; i++) {
					int cnt = 0;
					for(int j = 0; j < m; j++) if(j != k) {
						if(a[i][j] != b[j])
							cnt++;
					}
					if(cnt > 2) return false;
					if(cnt == 2) s.insert(a[i][k]);
				}
				if(s.size()) b[k] = *s.begin();
				return s.size() <= 1;
			};
			for(int c0 = 0; c0 < 3; c0++) {
				for(int c1 = 0; c1 < 3; c1++) if(c0 != c1) {
					vi b = a[0];
					b[diff[c0]] = a[i][diff[c0]];
					if(ok(b, diff[c1])) {
						out(b);
					}
				}
			}
			cout << "No\n";
			return 0;
		}
	}
	out(a[0]);

}