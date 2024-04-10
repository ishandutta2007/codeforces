#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int f = max(a + 1, n - b);
	cout << ((n - f) + 1);
	return 0;
}