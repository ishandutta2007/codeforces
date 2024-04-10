#include <iostream>
#include <bitset>
using namespace std;

bitset<111> bs;
int main() {
	int n, m;
	cin >> n;
	for (int i = 0; i < 2; ++i) {
		cin >> m;
		int a;
		while (m--) cin >> a, bs[a] = true;
	}
	if (bs.count() == n) cout << "I become the guy.";
	else cout << "Oh, my keyboard!";
	return 0;
}