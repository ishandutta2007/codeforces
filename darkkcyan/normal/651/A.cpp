#include <bits/stdc++.h>
using namespace std;

#define long long long
#define ii pair<int, int>

int main() {
	int a, b; cin >> a >> b;
	int ans = 0;
	
	if (a == 1 and b == 1) return cout << 0, 0;
	while (a > 0 and b > 0) {
		a -= 2; b -= 2;
		if (a < b) a += 3;
		else b += 3;
		++ans;
	}
	
	cout << ans;
	return 0;
}