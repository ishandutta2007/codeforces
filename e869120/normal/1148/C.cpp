#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, A[1 << 19], P[1 << 19], id[1 << 19];
vector<pair<int, int>>E;

void swaps(int u, int v) {
	if (u == v) return;
	E.push_back(make_pair(u, v));
	int t1 = A[u], t2 = A[v];
	swap(A[u], A[v]);
	swap(id[t1], id[t2]);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) { scanf("%d", &A[i]); P[i] = A[i]; id[A[i]] = i; }
	int mid = (N + 1) / 2;

	vector<pair<int, int>>G;
	for (int i = 1; i <= N; i++) G.push_back(make_pair(abs(i - mid), i));
	sort(G.begin(), G.end());

	for (int i = 0; i < G.size(); i++) {
		int pos = G[i].second; if (pos == id[pos]) continue;
		if (pos <= mid) {
			int F = id[pos];
			if (F <= mid) { swaps(F, N); F = N; }
			else { swaps(1, F); swaps(1, N); F = N; }
			swaps(pos, F);
		}
		else {
			int F = id[pos];
			if (F <= mid) { swaps(F, N); swaps(1, N); F = 1; }
			else { swaps(1, F); F = 1; }
			swaps(F, pos);
		}
	}

	cout << E.size() << endl;
	for (int i = 0; i < E.size(); i++) printf("%d %d\n", E[i].first, E[i].second);
	return 0;
}