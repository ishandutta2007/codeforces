#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, X, Y, A, B, ret; vector<int>x[200009]; bool used[200009];

int dfs(int pos) {
	used[pos] = true;
	int cnt = 0;
	for (int i = 0; i < x[pos].size(); i++) {
		if (used[x[pos][i]] == true) continue;
		cnt += dfs(x[pos][i]);
	}
	if (cnt >= 2 || pos == 1) {
		ret += max(1, cnt - 1);
		return 0;
	}
	if (cnt == 0) return 1;
	if (cnt == 1) return 1;
}

int main() {
	cin >> N >> X >> Y;
	for (int i = 1; i <= N - 1; i++) {
		cin >> A >> B;
		x[A].push_back(B);
		x[B].push_back(A);
	}
	if (X == Y) cout << (N - 1) * X << endl;
	else if (X > Y) {
		long long sum = (N - 1) * Y;
		for (int i = 1; i <= N; i++) {
			if (x[i].size() == N - 1) { sum += (X - Y); break; }
		}
		cout << sum << endl;
	}
	else {
		long long sum = (N - 1) * X;
		dfs(1); ret--;
		sum += (Y - X)*ret;
		cout << sum << endl;
	}
	return 0;
}