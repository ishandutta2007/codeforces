#include <iostream>
#include <string>
#include <tuple>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long dep[1 << 21];
pair<long long, long long> dp[1 << 21][4];

long long beauty(string V) {
	dep[0] = 0;
	for (int i = 1; i <= V.size(); i++) {
		if (V[i - 1] == '(') dep[i] = dep[i - 1] + 1;
		if (V[i - 1] == ')') dep[i] = dep[i - 1] - 1;
	}

	if (dep[V.size()] != 0) return 0;

	long long minv = (1 << 30);
	for (int i = 0; i <= V.size(); i++) minv = min(minv, dep[i]);

	long long cnt = 0;
	for (int i = 0; i < V.size(); i++) { if (dep[i] == minv) cnt++; }
	return cnt;
}

long long score(long long a1, long long a2) {
	if (a1 == a2) return 1;
	if (a1 < a2) return -(1LL << 33);
	return 0;
}

tuple<long long, long long, long long> solve(string V, long long goal) {
	for (int i = 0; i < (1 << 21); i++) {
		for (int j = 0; j < 4; j++) dp[i][j] = make_pair(-(1LL << 30), -1);
	}

	dp[0][0] = make_pair(0, -1);
	for (int i = 0; i < V.size(); i++) {
		if (V[i] == '(') {
			// 0 
			if (dp[i + 1][0].first < dp[i][0].first + score(dep[i + 1], goal)) {
				dp[i + 1][0].first = dp[i][0].first + score(dep[i + 1], goal);
				dp[i + 1][0].second = 0;
			}

			// 1 
			if (dp[i + 1][1].first < dp[i][0].first + score(dep[i + 1] - 2, goal)) {
				dp[i + 1][1].first = dp[i][0].first + score(dep[i + 1] - 2, goal);
				dp[i + 1][1].second = 0;
			}
			if (dp[i + 1][1].first < dp[i][1].first + score(dep[i + 1] - 2, goal)) {
				dp[i + 1][1].first = dp[i][1].first + score(dep[i + 1] - 2, goal);
				dp[i + 1][1].second = 1;
			}

			// 2 
			if (dp[i + 1][2].first < dp[i][2].first + score(dep[i + 1] + 2, goal)) {
				dp[i + 1][2].first = dp[i][2].first + score(dep[i + 1] + 2, goal);
				dp[i + 1][2].second = 2;
			}

			// 3 
			if (dp[i + 1][3].first < dp[i][2].first + score(dep[i + 1], goal)) {
				dp[i + 1][3].first = dp[i][2].first + score(dep[i + 1], goal);
				dp[i + 1][3].second = 2;
			}
			if (dp[i + 1][3].first < dp[i][3].first + score(dep[i + 1], goal)) {
				dp[i + 1][3].first = dp[i][3].first + score(dep[i + 1], goal);
				dp[i + 1][3].second = 3;
			}
		}
		if (V[i] == ')') {
			// 0 
			if (dp[i + 1][0].first < dp[i][0].first + score(dep[i + 1], goal)) {
				dp[i + 1][0].first = dp[i][0].first + score(dep[i + 1], goal);
				dp[i + 1][0].second = 0;
			}

			// 1 
			if (dp[i + 1][1].first < dp[i][1].first + score(dep[i + 1] - 2, goal)) {
				dp[i + 1][1].first = dp[i][1].first + score(dep[i + 1] - 2, goal);
				dp[i + 1][1].second = 1;
			}

			// 2 
			if (dp[i + 1][2].first < dp[i][0].first + score(dep[i + 1] + 2, goal)) {
				dp[i + 1][2].first = dp[i][0].first + score(dep[i + 1] + 2, goal);
				dp[i + 1][2].second = 0;
			}
			if (dp[i + 1][2].first < dp[i][2].first + score(dep[i + 1] + 2, goal)) {
				dp[i + 1][2].first = dp[i][2].first + score(dep[i + 1] + 2, goal);
				dp[i + 1][2].second = 2;
			}

			// 3 
			if (dp[i + 1][3].first < dp[i][1].first + score(dep[i + 1], goal)) {
				dp[i + 1][3].first = dp[i][1].first + score(dep[i + 1], goal);
				dp[i + 1][3].second = 1;
			}
			if (dp[i + 1][3].first < dp[i][3].first + score(dep[i + 1], goal)) {
				dp[i + 1][3].first = dp[i][3].first + score(dep[i + 1], goal);
				dp[i + 1][3].second = 3;
			}
		}
	}

	tuple<long long, long long, long long> E = make_tuple(dp[V.size()][3].first, -1, -1);

	long long cx = 3;
	for (int i = V.size(); i >= 1; i--) {
		long long e = dp[i][cx].second;
		if (cx == 3 && e != 3) get<2>(E) = i;
		if (cx != 0 && e == 0) get<1>(E) = i;
		cx = e;
	}
	return E;
}

int main() {
	int N; string S; cin >> N >> S;

	// 
	if (beauty(S) == 0) {
		cout << "0" << endl;
		cout << "1 1" << endl;
		return 0;
	}

	long long r = 0;
	for (int i = 0; i <= S.size(); i++) r = min(r, dep[i]);

	tuple<long long, long long, long long> v1 = solve(S, r - 2);
	tuple<long long, long long, long long> v2 = solve(S, r - 1);
	tuple<long long, long long, long long> v3 = solve(S, r + 0);
	tuple<long long, long long, long long> v4 = solve(S, r + 1);
	tuple<long long, long long, long long> v5 = solve(S, r + 2);
	tuple<long long, long long, long long> v6 = make_tuple(beauty(S), 1, 1);

	tuple<long long, long long, long long> A = make_tuple(-1, -1, -1);
	A = max({ v1, v2, v3, v4, v5, v6 });

	cout << get<0>(A) << endl;
	cout << get<1>(A) << " " << get<2>(A) << endl;
	return 0;
}