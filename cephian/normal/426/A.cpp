#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, sum=0, mx = 0, s;
	cin >> n >> s;
	while(n--) {
		int t;
		cin >> t;
		sum += t;
		mx = max(mx,t);
	}
	if(sum-mx <= s) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}