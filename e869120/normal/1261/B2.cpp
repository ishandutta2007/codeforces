#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

class BIT {
public:
	vector<int> bit;
	int size_ = 0;

	void init(int sz) {
		size_ = sz + 2;
		bit.resize(size_ + 2, 0);
	}
	void add(int pos, int x) {
		pos++;
		while (pos <= size_) {
			bit[pos] += x;
			pos += (pos & -pos);
		}
	}
	int sum(int pos) {
		int s = 0; pos++;
		while (pos >= 1) {
			s += bit[pos];
			pos -= (pos & -pos);
		}
		return s;
	}
	int searchs(int pos) {
		int cl = 0, cr = size_ + 1, cm, minx = (1 << 30);
		for (int i = 0; i < 22; i++) {
			cm = ((cl + cr) >> 1);
			int v = sum(cm);
			if (v >= pos) { minx = min(minx, cm); cr = cm; }
			else { cl = cm; }
		}
		return minx;
	}
};

int N, A[1 << 18];
int Q, K[1 << 18], P[1 << 18], ans[1 << 18];
vector<pair<int, int>> rem;
vector<int> G[1 << 18];

BIT Z;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
	scanf("%d", &Q);
	for (int i = 1; i <= Q; i++) scanf("%d%d", &K[i], &P[i]);

	for (int i = 1; i <= N; i++) rem.push_back(make_pair(-A[i], i));
	for (int i = 1; i <= Q; i++) G[K[i]].push_back(i);
	sort(rem.begin(), rem.end());

	Z.init(N + 2);
	for (int i = 1; i <= N; i++) {
		Z.add(rem[i - 1].second, 1);
		for (int j = 0; j < G[i].size(); j++) {
			int idx = G[i][j];
			int val = Z.searchs(P[idx]);
			ans[idx] = A[val];
		}
	}

	for (int i = 1; i <= Q; i++) printf("%d\n", ans[i]);
	return 0;
}