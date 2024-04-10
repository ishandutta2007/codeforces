#include <bits/stdc++.h>

typedef long long LL;
typedef std::pair<int, LL> vec;
const int MAXN = 100010;
std::vector<vec> v;
vec st[MAXN]; int top;
int n;
vec operator - (vec a, vec b) {
	a.first -= b.first, a.second -= b.second;
	return a;
}
LL cross(vec a, vec b) {
	return a.first * b.second - a.second * b.first;
}
bool cmp(vec a, vec b) {
	return a.first == b.first ? a.second > b.second : a.first < b.first;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1, x, y; i <= n; ++i) {
		std::cin >> x >> y;
		v.emplace_back(x, y - (LL) x * x);
	}
	std::sort(v.begin(), v.end(), cmp);
	for (auto t : v) {
		if (top && t.first == st[top].first && t.second < st[top].second) continue;
		while (top > 1 && cross(st[top] - st[top - 1], t - st[top]) >= 0) --top;
		st[++top] = t;
	}
	std::cout << top - 1 << std::endl;
	return 0;
}