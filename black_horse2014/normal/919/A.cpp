#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	double cost = 1e9;
	while (n--) {
		int a, b; cin >> a >> b;
		cost = min(cost, 1.0 * a / b);
	}
	printf("%.10f\n", cost * m);
	return 0;
}