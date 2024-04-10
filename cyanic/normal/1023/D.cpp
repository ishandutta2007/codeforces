#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;

const int maxn = 200005;
int T[maxn<<2], a[maxn], l[maxn], r[maxn], n, q, flag;
set<int> s; set<int>::iterator it;
vector<int> p[maxn];

#define mid (l + r >> 1)
#define lc (o << 1)
#define rc (o << 1 | 1)
int query(int o, int l, int r, int x, int y) {
	if (l == x && y == r) return T[o];
	if (y <= mid) return query(lc, l, mid, x, y);
	if (mid < x) return query(rc, mid + 1, r, x, y);
	return max(query(lc, l, mid, x, mid), 
			   query(rc, mid+1, r, mid+1, y));
}

void update(int o, int l, int r, int x, int y) {
	if (l == r) { T[o] = y; return; }
	if (x <= mid) update(lc, l, mid, x, y);
	else update(rc, mid + 1, r, x, y);
	T[o] = max(T[lc], T[rc]);
}

int main() {
	scanf("%d%d", &n, &q);
	rep (i, 1, n) {
		scanf("%d", &a[i]);
		p[a[i]].push_back(i);
	}
	if (p[0].empty() && p[q].empty())
		return puts("NO"), 0;
	if (p[q].empty()) {
		rep (i, 1, n)
			if (!a[i]) {
				a[i] = q;
				p[q].push_back(i);
				break;
			}
	}
	p[0].clear();
	rep (i, 1, q) {
		if (p[i].empty()) continue;
		l[i] = p[i].front();
		r[i] = p[i].back();
		if (query(1, 1, n, l[i], r[i]))
			return puts("NO"), 0;
		for (auto x : p[i])
			update(1, 1, n, x, i);
	}
	rep (i, 1, n)
		if (!a[i]) s.insert(i);
	l[1] = 1; r[1] = n;
	per (i, q, 1) {
		it = s.lower_bound(l[i]);
		while (it != s.end() && *it <= r[i]) {
			a[*it] = i; s.erase(it++);
		}
	}
	puts("YES");
	rep (i, 1, n)
		printf("%d ", a[i]);
	return 0;
}