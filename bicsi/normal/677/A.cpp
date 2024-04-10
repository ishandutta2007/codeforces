// Create your own template by modifying this file!
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, h;
	cin >> n >> h;

	int ret = 0;
	for(int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		ret += 1 + (val > h);
	}
	cout << ret << '\n';

	return 0;
}