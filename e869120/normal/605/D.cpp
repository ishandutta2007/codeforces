#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
#pragma warning (disable: 4996)

const int MAX_N = 600000;
set<pair<int, int>>dat[MAX_N];

class SegmentTree {
public:
	int size_ = 1, ly = 0; vector<int>Z;

	void init(int sz) {
		while (size_ <= sz) size_ *= 2;
	}
	void add(int px, int py, int num) {
		px += size_; dat[px].insert(make_pair(py, num));
		while (px >= 1) {
			px >>= 1;
			dat[px].insert(make_pair(py, num));
		}
	}
	void lose(int px, int py, int num) {
		px += size_; dat[px].erase(make_pair(py, num));
		while (px >= 1) {
			px >>= 1;
			dat[px].erase(make_pair(py, num));
		}
	}
	void query(int l, int r, int a, int b, int u) {
		if (r <= a || b <= l) return;
		if (l <= a && b <= r) {
			auto itr = dat[u].begin();
			while (itr != dat[u].end()) {
				pair<int, int> D = *itr;
				if (D.first > ly) break;
				Z.push_back(D.second);
				itr++;
			}
			return;
		}
		query(l, r, a, (a + b) >> 1, u * 2);
		query(l, r, (a + b) >> 1, b, u * 2 + 1);
	}
	vector<int> remains(int px, int py) {
		Z.clear(); ly = py; px++;
		query(0, px, 0, size_, 1);
		return Z;
	}
};

int N, A[100009], B[100009], C[100009], D[100009], dist[100009], pre[100009];
vector<int>X, Y;
SegmentTree I;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
		X.push_back(A[i]); X.push_back(C[i]);
		Y.push_back(B[i]); Y.push_back(D[i]);
	}
	sort(X.begin(), X.end()); X.erase(unique(X.begin(), X.end()), X.end());
	sort(Y.begin(), Y.end()); Y.erase(unique(Y.begin(), Y.end()), Y.end());
	for (int i = 0; i < N; i++) {
		A[i] = lower_bound(X.begin(), X.end(), A[i]) - X.begin();
		B[i] = lower_bound(Y.begin(), Y.end(), B[i]) - Y.begin();
		C[i] = lower_bound(X.begin(), X.end(), C[i]) - X.begin();
		D[i] = lower_bound(Y.begin(), Y.end(), D[i]) - Y.begin();
	}

	I.init(X.size() + 2);
	for (int i = 0; i < N; i++) { if (X[A[i]] + Y[B[i]] >= 1) I.add(A[i], B[i], i); }
	
	queue<int>Q;
	for (int i = 0; i < N; i++) { dist[i] = (1 << 30); if (X[A[i]] == 0 && Y[B[i]] == 0) { Q.push(i); dist[i] = 0; } }
	for (int i = 0; i < N; i++) pre[i] = -1;

	while (!Q.empty()) {
		int pos = Q.front(); Q.pop();
		vector<int> E = I.remains(C[pos], D[pos]);
		for (int i = 0; i < E.size(); i++) {
			dist[E[i]] = dist[pos] + 1; pre[E[i]] = pos;
			Q.push(E[i]);
			I.lose(A[E[i]], B[E[i]], E[i]);
		}
	}

	if (dist[N - 1] == (1 << 30)) {
		cout << "-1" << endl;
		return 0;
	}

	int cx = N - 1; vector<int>vec;
	while (cx != -1) {
		vec.push_back(cx);
		cx = pre[cx];
	}
	reverse(vec.begin(), vec.end());
	
	printf("%d\n", (int)vec.size());
	for (int i = 0; i < vec.size(); i++) { if (i) printf(" "); printf("%d", vec[i] + 1); }
	printf("\n");
	return 0;
}