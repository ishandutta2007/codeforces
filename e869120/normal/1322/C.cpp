#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long mod = 998244353;

int T, N, M;
long long C[1 << 19];
vector<int> X[1 << 19];

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d%d", &N, &M);
		for (int j = 1; j <= N; j++) X[j].clear();
		for (int j = 1; j <= N; j++) scanf("%lld", &C[j]);
		for (int j = 1; j <= M; j++) {
			int a, b; scanf("%d%d", &a, &b);
			X[b].push_back(a);
		}
		for (int j = 1; j <= N; j++) sort(X[j].begin(), X[j].end());

		vector<pair<long long, int>> vec;
		for (int j = 1; j <= N; j++) {
			if (X[j].size() == 0) continue;
			long long cr = 2909;
			for (int k = 0; k < X[j].size(); k++) {
				cr *= mod;
				cr += (1LL * X[j][k]);
			}
			vec.push_back(make_pair(cr, j));
		}
		sort(vec.begin(), vec.end());

		long long rem = 0, sum = 0;
		for (int j = 0; j < vec.size(); j++) {
			sum += C[vec[j].second];
			if (j == vec.size() - 1 || vec[j].first != vec[j + 1].first) {
				rem = gcd(rem, sum);
				sum = 0;
			}
		}
		printf("%lld\n", rem);
	}
	return 0;
}