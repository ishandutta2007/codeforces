#include <bits/stdc++.h>
int main() {
	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
		std::valarray<int> a(n);
		for (int &x : a) {
			std::cin >> x;
		}
		std::cout << (a[0] == a.min() ? "Yes" : "No") << "\n";
	}
	return 0;
}