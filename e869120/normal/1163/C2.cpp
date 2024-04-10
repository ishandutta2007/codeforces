#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#pragma warning (disable: 4996)

long long N, X[1009], Y[1009];
vector<pair<int, int>> vec;
map<tuple<long long, long long, long long>, int>Map;
map<pair<long long, long long>, long long>Map2;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			long long A = X[j] - X[i];
			long long B = Y[j] - Y[i];
			if (A == 0) { A = 0; B = 1; }
			else if (B == 0) { A = 1; B = 0; }
			else if (A < 0) { A *= -1; B *= -1; }

			long long G = gcd(abs(A), abs(B));
			A /= G; B /= G;

			long long C = -B * X[i] + A * Y[i];
			if (Map[make_tuple(A, B, C)] == 1) continue;
			Map[make_tuple(A, B, C)] = 1;
			Map2[make_pair(A, B)]++;
			vec.push_back(make_pair(i, j));
		}
	}

	long long C = vec.size(); C = C * (C - 1LL) / 2LL;
	for (int i = 0; i < vec.size(); i++) {
		int p1 = vec[i].first, p2 = vec[i].second;
		long long A = X[p2] - X[p1];
		long long B = Y[p2] - Y[p1];
		if (A == 0) { A = 0; B = 1; }
		else if (B == 0) { A = 1; B = 0; }
		else if (A < 0) { A *= -1; B *= -1; }

		long long G = gcd(abs(A), abs(B));
		A /= G; B /= G;

		long long F = Map2[make_pair(A, B)]; Map2[make_pair(A, B)] = 0;
		C -= F * (F - 1LL) / 2LL;
	}
	cout << C << endl;
	return 0;
}