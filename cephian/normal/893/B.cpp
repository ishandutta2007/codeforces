#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,gt = 1;
	cin >> n;
	for(int k = 1; ; ++k) {
		int r = ((1<<k)-1)*(1<<(k-1));
		if(n%r == 0) gt = r;
		if(r > n) break;
	}
	cout << gt << "\n";
}