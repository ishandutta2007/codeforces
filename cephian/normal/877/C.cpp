#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	cout << n/2*2 + n-n/2 << "\n";
	for(int i = 2; i <= n; i += 2) cout << i << " ";
	for(int i = 1; i <= n; i += 2) cout << i << " ";
	for(int i = 2; i <= n; i += 2) cout << i << " ";
	cout << "\n";
}