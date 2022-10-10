#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int ans = 0;
	while (n) {
		--n;
		++ans;
		if (ans % m == 0) ++n;
	}
	cout << ans;
	return 0;
}