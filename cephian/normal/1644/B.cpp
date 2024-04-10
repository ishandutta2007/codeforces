#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
	if(n == 3) {
		cout << "3 2 1\n1 3 2\n3 1 2\n";
	} else {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				int k = (i+j) % n;
				cout << n-k << ' ';
			}
			cout << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		solve(n);
	}
}