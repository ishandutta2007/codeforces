#include <bits/stdc++.h>
using namespace std;

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		if(k % 3 == 0) {
			n %= (k+1);
			if(n == k)
				n = 1;
		}
		if(n%3 == 0) cout << "Bob\n";
		else cout << "Alice\n";
	}
}