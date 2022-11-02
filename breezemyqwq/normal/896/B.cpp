#include <bits/stdc++.h>

using namespace std;

int p[1005];

int main() {
	int n, m, c;
	cin >> n >> m >> c;
	for(int i = 1; i <= m; i++) {
		int k;
		cin >> k;
		if((k << 1) <= c) {
			for(int j = 1; j <= n; j++) 
				if(p[j] > k || !p[j]) {
					p[j] = k;
					cout << j << endl;
					break; 
				}
		}
		else {
			for(int j = n; j; j--)
				if(p[j] < k || !p[j]) {
					p[j] = k;
					cout << j << endl;
					break; 
				}
		}
		fflush(stdout);
	}
	return 0;
}