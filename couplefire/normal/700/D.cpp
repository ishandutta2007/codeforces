#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int MAGIC = 305;

int n, q, a[N];
int F[N], F2[N], cnt[N];
long long res[N];
vector<int> vec;

struct Query {
	int l; int r; int id;
	bool operator < (const Query &rhs) const {
		return l / MAGIC < rhs.l / MAGIC || (l / MAGIC == rhs.l / MAGIC && r < rhs.r);
	}
} Q[N];

void upd(int x, int v) {
	F[cnt[a[x]]]--;
	cnt[a[x]] += v;
	F[cnt[a[x]]]++;
	if (F[cnt[a[x]]] == 1) vec.push_back(cnt[a[x]]);
}

int top(queue<int> &q1, queue<int> &q2) {
	int x;
	if (!q1.size()) x = q2.front(), q2.pop();
	else if (!q2.size()) x = q1.front(), q1.pop();
	else {
		if (q1.front() > q2.front()) x = q2.front(), q2.pop();
		else x = q1.front(), q1.pop();
	}
	return x;
}

long long solve() {
	queue<int> q1, q2;
	vector<int> vec2;
	for (auto i : vec) {
		if (F2[i] || !F[i]) continue;
		vec2.push_back(i), F2[i] = F[i];
	}
	vec = vec2;
	sort(vec.begin(), vec.end());
	for (auto i : vec) q1.push(i);

	long long res = 0;
	while(q1.size() + q2.size()) {
		int x = top(q1, q2);

		if (F2[x] % 2 == 0) {
			res += 1LL * F2[x] * x; 
			if (!F2[x + x]) q2.push(x + x); 
			F2[x + x] += F2[x] / 2, F2[x] = 0;
		} else {
			if (F2[x] > 1) {
				res += (F2[x] - 1) * x;
				if (!F2[x + x]) q2.push(x + x);
				F2[x + x] += F2[x] / 2;
			}
			F2[x] = 0;
			if (!(q1.size() + q2.size())) break;

			int y1 = (q1.size() > 0) ? q1.front() : 1e9;
			int y2 = (q2.size() > 0) ? q2.front() : 1e9;
			int y = min(y1, y2);

			F2[y]--;
			if (!F2[y]) {
				if (q1.size() && y == q1.front()) q1.pop();
				if (q2.size() && y == q2.front()) q2.pop();
			}
			if (!F2[x + y]) q2.push(x + y);
			F2[x + y]++; res += x + y;
		}
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	cin >> q;
	for (int i = 1; i <= q; ++i) {
		cin >> Q[i].l >> Q[i].r; Q[i].id = i;
	}
	sort(Q + 1, Q + q + 1);

	int L = 1, R = 0;
	for (int i = 1; i <= q; ++i) {
		while(R < Q[i].r) upd(++R, +1);
		while(L > Q[i].l) upd(--L, +1);
		while(R > Q[i].r) upd(R--, -1);
		while(L < Q[i].l) upd(L++, -1);
		res[Q[i].id] = solve();
	}
	

	for (int i = 1; i <= q; ++i) printf("%lld\n", res[i]);
}