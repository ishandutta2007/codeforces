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
#pragma warning (disable: 4996)

long long N, M, K, A[1 << 18];
vector<pair<long long, int>>vec; vector<int>v2;

int main() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) { scanf("%lld", &A[i]); vec.push_back(make_pair(A[i], i)); }
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());

	long long sum = 0;
	for (int i = 0; i < K*M; i++) { v2.push_back(vec[i].second); sum += vec[i].first; }
	sort(v2.begin(), v2.end());

	cout << sum << endl;
	for (int i = M - 1; i < v2.size() - 1; i += M) {
		if (i != M - 1) printf(" "); printf("%d", v2[i]);
	}
	cout << endl;
	return 0;
}