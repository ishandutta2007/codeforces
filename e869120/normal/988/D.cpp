#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

long long n, x[200019];

bool exists(long long v) {
	int pos1 = lower_bound(x, x + n, v) - x;
	if (x[pos1] == v && pos1 < n) return true;
	return false;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%lld", &x[i]);
	sort(x, x + n);

	vector<long long>vec;
	int T = 3;
	for (int j = 0; j <= 30; j++) {
		for (int k = 0; k < n; k++) {
			vector<long long>C;
			for (int l = 0; l < T; l++) {
				long long F = x[k] + (1LL << j)*l;
				if (exists(F) == true) C.push_back(F);
				else break;
			}
			if (C.size() > vec.size()) {
				vec = C;
			}
		}
	}
	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++) { if (i)cout << " "; cout << vec[i]; } cout << endl;
	return 0;
}