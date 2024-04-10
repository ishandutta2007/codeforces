#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, p;
	cin >> n >> p;
	int ans = -1;
	for (int k = 1; k < 100000; k++){
		long long x = (long long)n - (long long)p * k;
		if (x >= k && k >= __builtin_popcountll(x)) {
			ans = k;
			break;
		}
 	}
 	cout << ans << "\n";
}