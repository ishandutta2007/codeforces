#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int N, K, A;
int M;

struct range_t {
	int b, e;
	
	bool operator < (const range_t & other) const {
		return b < other.b;
	}
	int get_cnt() const {
		return (e + 1 - b) / (A + 1);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> K >> A;
	cin >> M;
	
	set<range_t> S;
	S.insert({1, N + 1});
	int boat_cnt = S.begin()->get_cnt();
	for(int m = 1; m <= M; ++m) {
		int x;
		cin >> x;
		auto it = S.upper_bound(range_t({x, 0}));
		--it;
		range_t r = *it;
		range_t r1({r.b, x}), r2({x + 1, r.e});
		S.erase(it);
		if(r1.b < r1.e) S.insert(r1);
		if(r2.b < r2.e) S.insert(r2);
		boat_cnt += -r.get_cnt() + r1.get_cnt() + r2.get_cnt();
		if(boat_cnt < K) {
			cout << m;
			return 0;
		}
	}
	cout << -1;
}