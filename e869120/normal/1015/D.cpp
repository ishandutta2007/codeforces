#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, K, D; vector<long long>vec;

int main() {
	cin >> N >> K >> D;
	if (!(K <= D && D <= (N - 1)*K)) {
		cout << "NO" << endl;
		return 0;
	}
	for (int i = K - 1; i >= 0; i--) {
		long long M = i;
		long long MM = min(N - 1, D - M);
		vec.push_back(MM); D -= MM;
	}
	long long cx = 1; cout << "YES" << endl;
	for (int i = 0; i < vec.size(); i++) {
		if (i) cout << " ";
		if (i % 2 == 0) cx += vec[i]; else cx -= vec[i];
		cout << cx;
	}
	cout << endl;
	return 0;
}