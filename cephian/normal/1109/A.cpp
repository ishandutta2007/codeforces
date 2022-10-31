#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;
int m[2][1<<20] = {};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	m[0][0] = 1;
	int pre = 0;
	long long tot = 0;
	for(int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		pre ^= a;
		tot += m[i%2][pre];
		m[i%2][pre] += 1;
	}
	cout << tot << "\n";
}