#include <bits/stdc++.h>

int P, Q, K;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int T; std::cin >> T;
	while (T --> 0) {
		std::cin >> P >> Q >> K;
		if (K == 1) { std::cout << "REBEL\n"; continue; }
		int G = gcd(P, Q);
		P /= G, Q /= G;
		if (P > Q) std::swap(P, Q);
		std::cout << ((Q - 2) / P + 1 >= K ? "REBEL\n" : "OBEY\n");
	}
	return 0;
}