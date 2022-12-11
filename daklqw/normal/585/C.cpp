#include <bits/stdc++.h>

typedef long long LL;
typedef std::string str;
LL gcd(LL a, LL b) {
	return b ? gcd(b, a % b) : a;
}
str get(int t = -1) {
	static int lst;
	if (t != -1) lst = t;
	lst ^= 1;
	return lst == 1 ? "A" : "B";
}
str solve(LL x, LL y) {
	if (x == 1 || y == 1) {
		if (x == y) return "";
		if (x == 1) return std::to_string(y - 1) + get(1);
		else return std::to_string(x - 1) + get(0);
	}
	if (x < y) {
		str res = std::to_string(y / x) + get(1);
		return res + solve(x, y % x);
	} else {
		str res = std::to_string(x / y) + get(0);
		return res + solve(x % y, y);
	}
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	LL x, y;
	std::cin >> x >> y;
	if (gcd(x, y) > 1) {
		std::cout << "Impossible" << std::endl;
		return 0;
	}
	std::cout << solve(x, y) << std::endl;
	return 0;
}