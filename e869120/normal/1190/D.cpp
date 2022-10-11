#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#pragma warning (disable: 4996)

class BIT {
public:
	vector<long long> bit; int size_ = 1;

	void init(int sz) {
		size_ = sz + 2;
		bit.resize(size_ + 2, 0);
	}
	void add(int pos, long long x) {
		pos++;
		while (pos <= size_) {
			bit[pos] += x;
			pos += (pos&-pos);
		}
	}
	long long sum(int pos) {
		long long s = 0; pos++;
		while (pos >= 1) {
			s += bit[pos];
			pos -= (pos&-pos);
		}
		return s;
	}
};

long long N, x[1 << 18], y[1 << 18], t[1 << 18], ans;
vector<long long>X, Y, G[1 << 18];
BIT Z; bool used[1 << 18];

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%lld%lld", &x[i], &y[i]);
		X.push_back(x[i]);
		Y.push_back(y[i]);
	}
	sort(X.begin(), X.end()); X.erase(unique(X.begin(), X.end()), X.end());
	sort(Y.begin(), Y.end()); Y.erase(unique(Y.begin(), Y.end()), Y.end());
	for (int i = 1; i <= N; i++) {
		x[i] = lower_bound(X.begin(), X.end(), x[i]) - X.begin();
		y[i] = lower_bound(Y.begin(), Y.end(), y[i]) - Y.begin();
		G[y[i]].push_back(x[i]);
	}
	Z.init(X.size() + 2);
	for (int i = Y.size() - 1; i >= 0; i--) {
		sort(G[i].begin(), G[i].end());
		for (int j = 0; j < G[i].size(); j++) {
			if (used[G[i][j]] == false) { used[G[i][j]] = true; Z.add(G[i][j], 1); }
		}
		int cl = 0;
		for (int j = 0; j < G[i].size(); j++) {
			long long a1 = Z.sum(G[i][j]) - Z.sum(cl - 1);
			long long a2 = Z.sum(X.size()) - Z.sum(G[i][j] - 1);
			ans += a1 * a2;
			cl = G[i][j] + 1;
		}
	}
	cout << ans << endl;
	return 0;
}