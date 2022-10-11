#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	long long to, cap, rev;
};

class Flow {
public:
	vector<Edge> G[240];
	bool used[240];

	void add_edge(long long u, long long v, long long c) {
		G[u].push_back(Edge{ v, c, (long long)G[v].size() });
		G[v].push_back(Edge{ u, 0LL, (long long)G[u].size() - 1 });
	}
	long long dfs(int pos, int to, long long f) {
		if (pos == to) return f;

		used[pos] = true;
		for (int i = 0; i < G[pos].size(); i++) {
			if (used[G[pos][i].to] == true || G[pos][i].cap == 0) continue;

			long long V = dfs(G[pos][i].to, to, min(f, G[pos][i].cap));
			if (V > 0) {
				G[pos][i].cap -= V;
				G[G[pos][i].to][G[pos][i].rev].cap += V;
				return V;
			}
		}
		return 0;
	}
	long long max_flow(int u, int v) {
		long long sum = 0;
		while (true) {
			for (int i = 0; i < 240; i++) used[i] = false;
			long long r = dfs(u, v, (1LL << 60));
			if (r == 0) break;
			sum += r;
		}
		return sum;
	}
};

long long N, M;
long long lx[1 << 18], ly[1 << 18], rx[1 << 18], ry[1 << 18];
vector<long long> X, Y;

bool used[240][240];
Flow Z;

int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> lx[i] >> ly[i] >> rx[i] >> ry[i]; rx[i]++; ry[i]++;
		X.push_back(lx[i]); Y.push_back(ly[i]);
		X.push_back(rx[i]); Y.push_back(ry[i]);
	}
	X.push_back(1); X.push_back(N + 1);
	Y.push_back(1); Y.push_back(N + 1);
	sort(X.begin(), X.end()); X.erase(unique(X.begin(), X.end()), X.end());
	sort(Y.begin(), Y.end()); Y.erase(unique(Y.begin(), Y.end()), Y.end());

	for (int i = 1; i <= M; i++) {
		lx[i] = lower_bound(X.begin(), X.end(), lx[i]) - X.begin();
		ly[i] = lower_bound(Y.begin(), Y.end(), ly[i]) - Y.begin();
		rx[i] = lower_bound(X.begin(), X.end(), rx[i]) - X.begin();
		ry[i] = lower_bound(Y.begin(), Y.end(), ry[i]) - Y.begin();

		for (int j = lx[i]; j < rx[i]; j++) {
			for (int k = ly[i]; k < ry[i]; k++) used[j][k] = true;
		}
	}

	for (int i = 0; i < X.size(); i++) {
		for (int j = 0; j < Y.size(); j++) {
			if (used[i][j] == false) continue;
			Z.add_edge(i, j + X.size(), 1LL << 40);
		}
	}
	for (int i = 0; i < X.size() - 1; i++) Z.add_edge(X.size() + Y.size() + 0, i, X[i + 1] - X[i]);
	for (int i = 0; i < Y.size() - 1; i++) Z.add_edge(X.size() + i, X.size() + Y.size() + 1, Y[i + 1] - Y[i]);

	cout << Z.max_flow(X.size() + Y.size() + 0, X.size() + Y.size() + 1) << endl;
	return 0;
}