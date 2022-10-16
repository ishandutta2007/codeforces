#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
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

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) [&] () {
		int n;
		cin >> n;
		vi a(n), b(n);
		V<pi> he, be;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			if(i) {
				he.EB(a[i - 1], a[i]);
				if(he.back().F > he.back().S) swap(he.back().F, he.back().S);
			}
		}
		for(int i = 0; i < n; i++) {
			cin >> b[i];
			if(i) {
				be.EB(b[i - 1], b[i]);
				if(be.back().F > be.back().S) swap(be.back().F, be.back().S);
			}
		}
		sort(ALL(he)), sort(ALL(be));
		if(he != be || a[0] != b[0] || a[n - 1] != b[n - 1]) {
			cout << "NO" << '\n';
			return;
		}
		V<pi> ans;
		auto rev = [&] (int l, int r) {
			ans.EB(l, r);
			reverse(a.begin() + l, a.begin() + r + 1);
		};

		for(int i = 1; i < n - 1; i++) {
			if(a[i] == b[i]) continue;
			for(int j = i + 1; j + 1 < n; j++) {
				if(a[j] == b[i] && a[j + 1] == a[i - 1]) {
					rev(i - 1, j + 1);
					break;
				}
			
			}
			if(a[i] == b[i]) continue;
			int j;
			for(j = i; j + 1 < n; j++)
				if(a[j + 1] == b[i] && a[j] == a[i - 1])
					break;
			assert(j + 1 < n);
			for(int l = i - 1; l < j; l++) {
				bool bk = false;
				for(int k = j + 1; k < n; k++) {
					if(a[k] == a[l]) {
						rev(l, k);
						bk = true;
						break;
					}
				}
				if(bk) break;
			}
			for(int j = i + 1; j + 1 < n; j++) {
				if(a[j] == b[i] && a[j + 1] == a[i - 1]) {
					rev(i - 1, j + 1);
					break;
				}
			}
			assert(a[i] == b[i]);
		}


		assert(a == b);

		cout << "YES" << '\n';
		cout << SZ(ans) << '\n';
		for(auto[l, r]:ans) {
			cout << l + 1 << " " << r + 1 << '\n';
		}

	}();
}