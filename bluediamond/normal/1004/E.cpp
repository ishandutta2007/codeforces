#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <cassert>
#include <deque>

bool home = true;

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
	home = 0;
#endif
	if (home) {
		FILE* stream;
		freopen_s(&stream, "iron_man.txt", "r", stdin);
	}
	else {
		ios::sync_with_stdio(0); cin.tie(0);
	}



	int n, k;
	cin >> n >> k;

	vector<vector<pair<int, int>>> g(n);
	vector<int> down(n, 0);
	vector<int> up(n, 0);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		g[a].push_back({ b, c });
		g[b].push_back({ a, c });
	}




	function<void(int, int)>computeDown = [&](int a, int p) {
		vector<pair<int, int>> kids;
		down[a] = 0;
		for (auto& Edge : g[a]) {
			int b = Edge.first, cost = Edge.second;
			if (b == p) continue;
			kids.push_back(Edge);
			computeDown(b, a);
			down[a] = max(down[a], down[b] + cost);
		}
		g[a] = kids;
	};

	vector<int> revOrder;

	function<void(int)>computeUp = [&](int a) {
		for (int Step = 0; Step < 2; Step++) {
			int Max = 0;
			for (auto& Edge : g[a]) {
				int b = Edge.first, cost = Edge.second;
				up[b] = max(up[b], Max + cost);
				Max = max(Max, down[b] + cost);
			}
			reverse(g[a].begin(), g[a].end());
		}
		for (auto& Edge : g[a]) {
			int b = Edge.first, cost = Edge.second;
			up[b] = max(up[b], up[a] + cost);
			computeUp(b);
		}
		revOrder.push_back(a);
	};

	computeDown(0, -1);
	computeUp(0);


	const int INF = (int)1e9 + 7;

	function<bool(int)> isok = [&](int limit) {
		vector<int> minDown(n, INF);
		for (auto& a : revOrder) {
			if (down[a] <= limit) {
				minDown[a] = 1;
				continue;
			}
			int dim = (int)g[a].size();
			vector<int> okPref(dim, 1);
			vector<int> okSuf(dim, 1);
			for (int i = 0; i < dim; i++) {
				auto& Edge = g[a][i];
				int b = Edge.first, cost = Edge.second;
				okPref[i] = okSuf[i] = (cost + down[b] <= limit);
			}
			for (int i = 1; i < dim; i++) {
				okPref[i] &= okPref[i - 1];
			}
			for (int i = dim - 2; i >= 0; i--) {
				okSuf[i] &= okSuf[i + 1];
			}
			for (int i = 0; i < dim; i++) {
				auto& Edge = g[a][i];
				int b = Edge.first, cost = Edge.second;
				bool can_take = true;
				if (i - 1 >= 0) can_take &= okPref[i - 1];
				if (i + 1 < dim) can_take &= okSuf[i + 1];

				if (can_take) {
					minDown[a] = min(minDown[a], 1 + minDown[b]);
				}
			}
		}
		int solution = INF;
		for (auto& a : revOrder) {
			if (up[a] <= limit) {

				int dim = (int)g[a].size();
				vector<int> okPref(dim, 1);
				vector<int> okSuf(dim, 1);
				for (int i = 0; i < dim; i++) {
					auto& Edge = g[a][i];
					int b = Edge.first, cost = Edge.second;
					okPref[i] = okSuf[i] = (cost + down[b] <= limit);
				}
				for (int i = 1; i < dim; i++) {
					okPref[i] &= okPref[i - 1];
				}
				for (int i = dim - 2; i >= 0; i--) {
					okSuf[i] &= okSuf[i + 1];
				}
				vector<int> nextBad(dim, dim - 1);
				int lastBad = dim - 1;
				for (int i = dim - 1; i >= 0; i--) {
					auto& Edge1 = g[a][i];
					int b = Edge1.first, cost = Edge1.second;
					nextBad[i] = lastBad;
					if (cost + down[b] > limit) {
						lastBad = i;
					}
				}
				vector<bool> good(dim, 0);
				for (int i2 = 0; i2 < dim; i2++) {
					bool can_take = true;
					if (i2 + 1 < dim) can_take &= (okSuf[i2 + 1]);
					good[i2] = can_take;
				}
				solution = min(solution, minDown[a]);

				deque<int> d;

				for (int i1 = dim - 1; i1 >= 0; i1--) {
					if (i1 - 1 >= 0 && !okPref[i1 - 1]) {
						if (good[i1]) {
							while (!d.empty() && minDown[g[a][d.back()].first] >= minDown[g[a][i1].first]) d.pop_back();
							d.push_back(i1);
						}
						continue;
					}


					while (!d.empty() && d.front() > nextBad[i1]) d.pop_front();

					if (!d.empty()) solution = min(solution, 1 + minDown[g[a][i1].first] + minDown[g[a][d.front()].first]);

					if (good[i1]) {
						while (!d.empty() && minDown[g[a][d.back()].first] >= minDown[g[a][i1].first]) d.pop_back();
						d.push_back(i1);
					}
				}
			}
		}
		return solution <= k;
	};



	int low = 0, high = (int)1e9 + 7, solution = -1;
	while (low <= high) {
		int test = (low + high) / 2;
		if (isok(test)) {
			solution = test;
			high = test - 1;
		}
		else {
			low = test + 1;
		}
	}
	cout << solution << "\n";
}