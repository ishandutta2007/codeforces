#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, X[100009], Y[100009];
vector<pair<long long, long long>>vec, L;
map<long long, long long>Map;

int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld%lld", &X[i], &Y[i]); Y[i] -= 1LL * X[i] * X[i];
		Map[X[i]] = max(Map[X[i]], (1LL << 60) + Y[i]);
	}
	for (int i = 0; i < N; i++) {
		if (Map[X[i]] - (1LL << 60) == Y[i]) vec.push_back(make_pair(X[i], Y[i]));
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		L.push_back(vec[i]);

		while (L.size() >= 3) {
			long long ax = L[L.size() - 2].first - L[L.size() - 3].first;
			long long ay = L[L.size() - 2].second - L[L.size() - 3].second;
			long long bx = L[L.size() - 1].first - L[L.size() - 2].first;
			long long by = L[L.size() - 1].second - L[L.size() - 2].second;
			if (bx * ay <= by * ax) {
				L.pop_back();
				L.pop_back();
				L.push_back(vec[i]);
			}
			else break;
		}
	}
	cout << L.size() - 1 << endl;
	return 0;
}