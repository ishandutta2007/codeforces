#include <bits/stdc++.h>

using namespace std;

struct range_t {
	int b,  e;	//[b, e)
	bool operator < (const range_t & other) const {
		return b < other.b;
	}
};

int N, M;
string S;
set<range_t> R;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	cin >> S;
	S += '\n';
	
	int period_cnt = 0;
	for(int i = 0, b = -1; i < S.length(); ++i) {
		if(S[i] == '.') {
			if(b == -1)
				b = i;
			++period_cnt;
		}
		if(S[i] != '.') {
			if(b >= 0)
				R.insert(range_t({b, i}));
			b = -1;
		}
	}
	
	while(M--) {
		int x;
		char c;
		cin >> x >> c;
		--x;
		if(c == '.') {
			if(S[x] != '.') {
				++period_cnt;
				int b = x, e = x + 1;
				auto up = R.upper_bound(range_t({x, 0}));
				if(up != R.begin()) {
					auto lo = prev(up);
					if(x == lo->e) {
						b = lo->b;
						R.erase(lo);
					}
				}
				if(up != R.end()) {
					if(x + 1 == up->b) {
						e = up->e;
						R.erase(up);
					}
				}
				R.insert(range_t({b, e}));
			}
		} else {
			if(S[x] == '.') {
				--period_cnt;
				int b1 = x, e1 = x, b2 = x + 1, e2 = x + 1;
				auto up = R.upper_bound(range_t({x, 0}));
				if(up != R.begin()) {
					auto lo = prev(up);
					b1 = lo->b;
					e2 = lo->e;
					R.erase(lo);
					if(b1 < e1)
						R.insert(range_t({b1, e1}));
					if(b2 < e2)
						R.insert(range_t({b2, e2}));
				}
			}
		}
		cout << period_cnt - R.size() << '\n';
		S[x] = c;
		
		/*cout << '\n';
		for(auto & r : R) {
			cout << r.b << ' ' << r.e << '\n';
		}
		cout << '\n';*/
	}
}