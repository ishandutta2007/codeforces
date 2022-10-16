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
	// IO_OP;

	int n;
	cin >> n;
	V<pi> even, odd;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) {
			if((i + j) % 2 == 0) even.EB(i, j);
			else odd.EB(i, j);
		}
	for(int i = 0; i < n * n; i++) {
		int x;
		cin >> x;
		assert(even.size() || odd.size());
		if(even.size() && odd.size()) {
			if(x == 1) {
				cout << 2 << " " << even.back().F << " " << even.back().S << endl;
				even.pop_back();
			} else {
				cout << 1 << " " << odd.back().F << " " << odd.back().S << endl;
				odd.pop_back();
			}
		} else {
			if(odd.size()) {
				if(x != 1) {
					cout << 1 << " " << odd.back().F << " " << odd.back().S << endl;
					odd.pop_back();
				} else {
					cout << 3 << " " << odd.back().F << " " << odd.back().S << endl;
					odd.pop_back();
				}
			} else {
				if(x != 2) {
					cout << 2 << " " << even.back().F << " " << even.back().S << endl;
					even.pop_back();
				} else {
					cout << 3 << " " << even.back().F << " " << even.back().S << endl;
					even.pop_back();
				}
			}
		}
	}
	assert(even.empty() && odd.empty());
}