#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
int n, m, c;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int P1 = 2 * n + i * 2;
		int P2 = 0 * n + i * 2;
		int P3 = 2 * n + i * 2 + 1;
		int P4 = 0 * n + i * 2 + 1;
		if (P1 < m) { if (c >= 1)cout << " "; cout << P1 + 1; c++; }
		if (P2 < m) { if (c >= 1)cout << " "; cout << P2 + 1; c++; }
		if (P3 < m) { if (c >= 1)cout << " "; cout << P3 + 1; c++; }
		if (P4 < m) { if (c >= 1)cout << " "; cout << P4 + 1; c++; }
	}
	cout << endl;
	return 0;
}