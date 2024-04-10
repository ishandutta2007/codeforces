#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

long long T, A[1000009], C[1000009], D[1000009], maxn = 0;

bool calc(long long H, long long W, long long ex, long long ey) {
	if (ex <= 0 || ex > H) return false;
	if (ey <= 0 || ey > W) return false;
	for (int i = 0; i <= 1000000; i++) D[i] = 0;
	for (int i = 1; i <= H; i++) { for (int j = 1; j <= W; j++) D[abs(ex - i) + abs(ey - j)]++; }

	for (int i = 0; i <= 1000000; i++) { if (C[i] != D[i]) return false; }
	return true;
}

pair<int, int> check(long long H, long long W) {
	long long c = -1;
	for (int i = 1; i <= T; i++) { if (C[i] != 4LL * i) { c = i; break; } }

	long long ex = c;
	long long ey = W - (maxn - (H - c));
	
	bool I = calc(H, W, ex, ey);
	if (I == true) return make_pair(ex, ey);
	return make_pair(-1, -1);
}

int main() {
	scanf("%lld", &T);
	for (int i = 0; i < T; i++) { scanf("%lld", &A[i]); C[A[i]]++; maxn = max(maxn, A[i]); }

	vector<pair<long long, long long>>vec;
	for (int i = 1; i <= T; i++) {
		if (T%i != 0) continue;
		long long c1 = i, c2 = T / i;
		long long d = c1 + c2 - 2;
		if (d / 2 <= maxn && maxn <= d) vec.push_back(make_pair(c1, c2));
	}

	for (int i = 0; i < vec.size(); i++) {
		pair<int, int> B = check(vec[i].first, vec[i].second);
		if (B != make_pair(-1, -1)) {
			cout << vec[i].first << " " << vec[i].second << endl;
			cout << B.first << " " << B.second << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
	return 0;
}