#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long>A, B, C; long long x, y, l, r;

int main() {
	cin >> x >> y >> l >> r;
	long long c = 1; while ((1LL << 61) / x >= c) { A.push_back(c); c *= x; }A.push_back(c);
	long long d = 1; while ((1LL << 61) / y >= d) { B.push_back(d); d *= y; }B.push_back(d);
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B.size(); j++) {
			if (l <= A[i] + B[j] && A[i] + B[j] <= r)C.push_back(A[i] + B[j]);
		}
	}
	C.push_back(l - 1); C.push_back(r + 1);
	sort(C.begin(), C.end()); C.erase(unique(C.begin(), C.end()), C.end());
	long long maxn = 0;
	for (int i = 0; i < (int)C.size() - 1; i++)maxn = max(maxn, C[i + 1] - C[i] - 1);
	cout << maxn << endl;
	return 0;
}