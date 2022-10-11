#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int x[200], n, q, a, b, c;
int main() {
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		cin >> a >> b >> c;
		for (int j = 1; j <= n; j++) { if (x[j] <= a)x[j] = 0; }
		int cnt = 0, sum = 0; for (int j = 1; j <= n; j++) { if (x[j] == 0)cnt++; }
		if (cnt < b)cout << "-1" << endl;
		else { cnt = b; for (int j = 1; j <= n; j++) { if (cnt == 0)break; if (x[j] == 0) { sum += j; cnt--; x[j] = a + c; } }cout << sum << endl; }
	}
	return 0;
}