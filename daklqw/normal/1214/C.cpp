#include <bits/stdc++.h>

const int MAXN = 200010;
char buf[MAXN];
int n;
void bye() {
	std::cout << "No" << std::endl;
	exit(0);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> buf + 1;
	int cx = 0;
	for (int i = 1; i <= n; ++i) cx += buf[i] == '(' ? 1 : -1;
	if (cx != 0) bye();
	int st = 0, hav = 0;
	for (int i = 1; i <= n; ++i) {
		st += buf[i] == '(' ? 1 : -1;
		if (st < 0) {
			if (hav) bye();
			hav = true;
			st = 0;
		}
	}
	std::cout << "Yes" << std::endl;
	return 0;
}