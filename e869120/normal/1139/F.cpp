#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

struct Node {
	int l, r, val;
};

class BIT_Large {
public:
	vector<Node>vec;

	void init() {
		vec.push_back(Node{ -1, -1,0 });
	}
	void add(long long pos, int x) {
		int cx = 0; pos += (1LL << 39);
		for (int i = 39; i >= 0; i--) {
			vec[cx].val += x;
			if (pos < (1LL << i)) {
				if (vec[cx].l == -1) { vec[cx].l = vec.size(); vec.push_back(Node{ -1, -1, 0 }); }
				cx = vec[cx].l;
			}
			else {
				if (vec[cx].r == -1) { vec[cx].r = vec.size(); vec.push_back(Node{ -1, -1,0 }); }
				cx = vec[cx].r;
				pos -= (1LL << i);
			}
		}
		vec[cx].val += x;
	}
	int query(long long l, long long r, long long a, long long b, int u) {
		if (u == -1) return 0;
		if (l <= a && b <= r) return vec[u].val;
		if (r <= a || b <= l) return 0;

		int s1 = query(l, r, a, (a + b) >> 1, vec[u].l);
		int s2 = query(l, r, (a + b) >> 1, b, vec[u].r);
		return s1 + s2;
	}
	int sum(long long l, long long r) {
		// [l, r)
		l += (1LL << 39); r += (1LL << 39);
		return query(l, r, 0, (1LL << 40), 0);
	}
};

int N, M, cl[1 << 17], cr[1 << 17], b[1 << 17], inc[1 << 17], pref[1 << 17], ans[1 << 17];
vector<tuple<int, int, int>> tup;
BIT_Large Z1, Z2;

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) { scanf("%d", &cl[i]); tup.push_back(make_tuple(cl[i], 1, i)); }
	for (int i = 1; i <= N; i++) { scanf("%d", &cr[i]); tup.push_back(make_tuple(cr[i], 3, i)); }
	for (int i = 1; i <= N; i++) { scanf("%d", &b[i]); }
	for (int i = 1; i <= M; i++) { scanf("%d", &inc[i]); tup.push_back(make_tuple(inc[i], 2, i)); }
	for (int i = 1; i <= M; i++) { scanf("%d", &pref[i]); }

	sort(tup.begin(), tup.end()); Z1.init(); Z2.init();

	for (int i = 0; i < tup.size(); i++) {
		if (get<1>(tup[i]) == 1) {
			int pos = get<2>(tup[i]);
			Z1.add(b[pos] - cl[pos], 1);
			Z2.add(b[pos] + cl[pos], 1);
		}
		if (get<1>(tup[i]) == 2) {
			int pos = get<2>(tup[i]);
			long long A1 = Z1.sum(-(1LL << 39), 1LL << 39);
			long long A2 = Z1.sum(-(1LL << 39), pref[pos] - inc[pos]);
			long long A3 = Z2.sum(inc[pos] + pref[pos] + 1, 1LL << 39);
			ans[pos] = A1 - A2 - A3;
		}
		if (get<1>(tup[i]) == 3) {
			int pos = get<2>(tup[i]);
			Z1.add(b[pos] - cl[pos], -1);
			Z2.add(b[pos] + cl[pos], -1);
		}
	}

	for (int i = 1; i <= M; i++) {
		if (i >= 2) printf(" ");
		printf("%d", ans[i]);
	}
	return 0;
}