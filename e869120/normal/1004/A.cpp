#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

long long N, D, A[100009];

long long check(long long pos) {
	long long minx = (1LL << 60);
	for (int i = 0; i < N; i++) minx = min(minx, abs(A[i] - pos));
	return minx;
}

int main() {
	vector<long long>vec;
	cin >> N >> D;
	for (int i = 0; i < N; i++) { cin >> A[i]; vec.push_back(A[i] - D); vec.push_back(A[i] + D); }
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	long long sum = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (check(vec[i]) == D) sum++;
	}
	cout << sum << endl;
	return 0;
}