#include <bits/stdc++.h>

const int MAXN = 1010;
int qry(int x, int y) {
	(std::cout << "? " << x << ' ' << y << '\n').flush();
	int res; std::cin >> res;
	return res;
}
std::queue<int> q;
int deg[MAXN];
std::vector<int> out[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int n; std::cin >> n;
	for (int i = 1, t1, t2; i < n; ++i) {
		std::cin >> t1 >> t2, out[t1].push_back(t2), out[t2].push_back(t1);
		++deg[t1], ++deg[t2];
	}
	for (int i = 1; i <= n; ++i) if (deg[i] == 1) q.push(i);
	while (q.size() > 1) {
		int l = q.front(); q.pop();
		int r = q.front(); q.pop();
		int t = qry(l, r);
		if (t == l) {
			std::cout << "! " << l << std::endl;
			return 0;
		}
		if (t == r) {
			std::cout << "! " << r << std::endl;
			return 0;
		}
		for (auto t : out[l])
			if (--deg[t] == 1) q.push(t);
		for (auto t : out[r])
			if (--deg[t] == 1) q.push(t);
	}
	int t = q.front(); q.pop();
	std::cout << "! " << t << std::endl;
	return 0;
}