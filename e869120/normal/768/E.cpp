#include<iostream>
#include<vector>
using namespace std;
int x[1000001], n, cnt;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		int U = 0;
		for (int j = 1; j <= 1000; j++) {
			U += j;
			if (x[i] < U) { cnt ^= (j - 1); break; }
		}
	}
	if (cnt == 0)cout << "YES" << endl; else cout << "NO" << endl;
	return 0;
}