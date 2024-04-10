#include<iostream>
#include<algorithm>
using namespace std;
int n, t, k, d;
int main() {
	cin >> n >> t >> k >> d;
	int P1 = ((n + k - 1) / k)*t;
	int P2 = 1e9;
	for (int i = 0; i <= n; i++) {
		int V1 = (i + k - 1) / k; V1 *= t;
		int V2 = ((n - i) + k - 1) / k; V2 *= t; V2 += d;
		P2 = min(P2, max(V1, V2));
	}
	if (P1 > P2)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}