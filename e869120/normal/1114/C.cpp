#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <map>
#include <tuple>
using namespace std;

long long N, B, C; vector<pair<long long, long long>>vec;

long long solve(long long P) {
	long long M = N, S = 0;
	while (M >= 1) {
		M /= P;
		S += M;
	}
	return S;
}

int main() {
	cin >> N >> B; C = B;

	// divisor of S
	for (long long i = 2; i*i <= C; i++) {
		if (C%i == 0) {
			int cnt = 0;
			while (C%i == 0) { cnt++; C /= i; }
			vec.push_back(make_pair(i, cnt));
		}
	}
	if (C >= 2) vec.push_back(make_pair(C, 1));

	long long minx = (1LL << 60);
	for (int i = 0; i < vec.size(); i++) {
		long long R = solve(vec[i].first); R /= vec[i].second;
		minx = min(minx, R);
	}
	cout << minx << endl;
	return 0;
}