#include <bits/stdc++.h>

using namespace std;

int sq[3][3];

int main() {
		
	int n, a, b, c, d;

	cin >> n >> a >> b >> c >> d;
	vector<int> V;
	V.push_back(a + b);
	V.push_back(a + c);
	V.push_back(c + d);
	V.push_back(b + d);

	sort(V.begin(), V.end());

	if(V.back() - V[0] < n) cout << 1LL * n * (n - V.back() + V[0]);
	else cout << 0;

	return 0;
}