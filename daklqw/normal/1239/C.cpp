#include <bits/stdc++.h>

const int MAXN = 100010;
typedef long long LL;
std::priority_queue<int, std::vector<int>, std::greater<int> > q;
int n;
LL ansl[MAXN], T;
std::vector<std::pair<int, int> > V;
int que[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> T;
	for (int i = 1, t; i <= n; ++i)
		std::cin >> t, V.emplace_back(t, i);
	std::sort(V.begin(), V.end());
	LL now = -1;
	int cur = 0, b = 1, e = 0;
	for (int Q = 1; Q <= n; ) {
		if (b <= e) {
			int t = que[b];
			ansl[t] += now += T;
			while (cur < n && now >= V[cur].first) {
				q.push(V[cur++].second);
				while (q.top() < que[e])
					que[++e] = q.top(), q.pop();
			}
			if (++b > e && !q.empty())
				que[b = e = 1] = q.top(), q.pop();
			++Q;
		} else {
			now = V[cur].first;
			que[b = e = 1] = V[cur++].second;
		}
	}
	for (int i = 1; i <= n; ++i)
		std::cout << ansl[i] << ' ';
	return 0;
}