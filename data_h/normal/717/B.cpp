#include <bits/stdc++.h>
using namespace std;
const long long CON = 3e4;
long long n, c0, c1;
struct node {
	long long a, b, c;
	node(long long a = 0, long long b = 0) : a(a), b(b) {c = a * c0 + b * c1;}
};
bool operator < (const node &a, const node &b) {
	if (a.c != b.c) return a.c < b.c;
	if (a.a != b.a) return a.a < b.a;
	return a.b < b.b;
}
int main() {
	cin >> n >> c0 >> c1;
	if (c0 > c1) swap(c0, c1);
	if (c0 == 0) {
		cout << (n - 1) * c1 << endl;
		return 0;
	}
	long long ans = 0;
	if (c0 * CON <= c1) {
		long long len = c0 / c1 + 1;
		ans += (len - 1) * len / 2 + (len - 1) * (c0 + c1);
		n -= len + 1;
		for (long long a = 1; n; ++ a) {
			long long take = min(n, a);
			n -= take;
			ans += take * (a * c0 + c1 + c0 + c1);
		}
	}
	else {
		map<node, long long> que;
		-- n;
		++ que[node(0, 0)];
		while (n) {
			auto x = *que.begin();
			que.erase(que.begin());
			long long take = min(x.second, n);
			ans += take * (x.first.c + c0 + c1);
			que[node(x.first.a + 1, x.first.b)] += take;
			que[node(x.first.a, x.first.b + 1)] += take;
			n -= take;
		}
	}
	cout << ans << endl;
}