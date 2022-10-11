#include <iostream>
#include <algorithm>
using namespace std;

int A, B, C, maxn;

int main() {
	cin >> A >> B >> C;
	for (int i = 0; i <= 100; i++) {
		int L1 = i, L2 = i + 1, L3 = i + 2;
		if (L1 <= A && L2 <= B && L3 <= C) maxn = max(maxn, L1 + L2 + L3);
	}
	cout << maxn << endl;
	return 0;
}