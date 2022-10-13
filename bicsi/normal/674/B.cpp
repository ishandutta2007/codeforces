#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k, a, b, c, d;
	cin >> n >> k >> a >> b >> c >> d;

	if(n == 4 || k <= n) {
		cout << -1;
		return 0;
	}

	vector<int> V;
	for(int i = 1; i <= n; ++i)
		if(i != a && i != b && i != c && i != d) {
			V.push_back(i);
		}

	cout << a << " " << d << " ";
	for(auto x : V) cout << x << " ";
	cout << c << " " << b << '\n';

	cout << c << " " << b << " ";
	reverse(V.begin(), V.end());
	for(auto x : V) cout << x << " ";
	cout << a << " " << d;
	return 0;
}