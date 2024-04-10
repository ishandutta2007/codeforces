#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct pt {
	ll x, y;
	pt (ll x = 0, ll y = 0) : x(x), y(y) {}
	bool operator < (const pt &p) const {
		return make_pair(x, y) < make_pair(p.x, p.y);
	}
};

ll sqr(ll x) {
	return x * x;
}

ll dis(pt p1, pt p2) {
	return sqr(p1.x - p2.x) + sqr(p1.y - p2.y);
}

ll vect(pt p, pt p1, pt p2) {
	return (p1.x - p.x) * (p2.y - p.y) - (p2.x - p.x) * (p1.y - p.y);
}

void convex(vector<pt> &ps) {
	if (ps.size() <= 1) return;
	sort(ps.begin(), ps.end());
	int n = ps.size(), k = 0;
	vector<pt> ch(n + n);
	for (int i = 0; i < n; ch[k++] = ps[i++])
		while (k >= 2 && vect(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
	for (int i = n - 2, t = k+1; i >= 0; ch[k++] = ps[i--])
		while (k >= t && vect(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
	ch.resize(k - 1);
	ps = ch;
}

const int N = 4000000;
char s[N], t[N];
vector<pt> S, T;

void append(ll v, char *c, int &cn) {
	cn += strlen(ltoa(v, c+cn, 36));
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		S.emplace_back(x, y);
	}
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		T.emplace_back(x, y);
	}
	convex(S), convex(T);
	int ls = 0, lt = 0;
	for (int i = 0; i < S.size(); i++) {
		append(dis(S[i], S[(i+1)%S.size()]), s, ls);
		append(dis(S[i], S[(i+2)%S.size()]), s, ls);
	}
	for (int i = 0; i < ls; i++) s[ls+i] = s[i];
	s[ls+ls] = 0;
	for (int i = 0; i < T.size(); i++) {
		append(dis(T[i], T[(i+1)%T.size()]), t, lt);
		append(dis(T[i], T[(i+2)%T.size()]), t, lt);
	}
	if (strstr(s, t)) puts("YES");
	else puts("NO");
}