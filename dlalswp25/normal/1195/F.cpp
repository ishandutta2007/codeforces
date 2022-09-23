#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int A[101010];
int S[101010];

ll X[303030];

const ll Z = 2000000001;

int id;
int N, Q;
vector<pll> v;
vector<ll> tmp;

int rt[303030];

struct NODE {
	int l, r;
	int x;
}T[20 * 303030];

int lst[303030];
int nxt[303030];

ll gcd(ll x, ll y) {
	if(x < 0 || y < 0) return gcd(abs(x), abs(y));
	return y ? gcd(y, x % y) : x;
}

int make_tree(int bef, int s, int e, int p) {
	if(e < s || p < s || e < p) return bef;

	int now = ++id;
	if(s == e) {
		T[now].x = T[bef].x + 1;
		return now;
	}

	int m = s + e >> 1;
	T[now].l = make_tree(T[bef].l, s, m, p);
	T[now].r = make_tree(T[bef].r, m + 1, e, p);
	T[now].x = T[T[now].l].x + T[T[now].r].x;

	return now;
}

int get(int now, int s, int e, int p, int q) {
	if(e < s || q < p || q < s || e < p) return 0;
	if(p <= s && e <= q) return T[now].x;
	int m = s + e >> 1;
	return get(T[now].l, s, m, p, q) + get(T[now].r, m + 1, e, p, q);
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int K; scanf("%d", &K);
		A[i] = K;
		v.clear();
		for(int j = 0; j < K; j++) {
			ll x, y; scanf("%lld%lld", &x, &y);
			v.push_back({x, y});
		}

		v.push_back(*v.begin());
		for(int j = 1; j < v.size(); j++) {
			ll dx = v[j].first - v[j - 1].first;
			ll dy = v[j].second - v[j - 1].second;
			ll g = gcd(dx, dy);
			dx /= g; dy /= g;
			X[++id] = dx * Z + dy;
		}
	}

	for(int i = 1; i <= id; i++) {
		tmp.push_back(X[i]);
	}
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	int n = tmp.size();

	for(int i = 1; i <= id; i++) X[i] = lower_bound(tmp.begin(), tmp.end(), X[i]) - tmp.begin() + 1;

	for(int i = 1; i <= n; i++) lst[i] = id + 1;

	for(int i = id; i >= 1; i--) {
		nxt[i] = lst[X[i]];
		lst[X[i]] = i;
	}

	for(int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];
	N = id;

	id = 0;

	for(int i = 1; i <= N; i++) rt[i] = make_tree(rt[i - 1], 1, N + 1, nxt[i]);

	scanf("%d", &Q);
	while(Q--) {
		int l, r; scanf("%d%d", &l, &r);
		l = S[l - 1] + 1;
		r = S[r];

		printf("%d\n", get(rt[r], 1, N + 1, r + 1, N + 1) - get(rt[l - 1], 1, N + 1, r + 1, N + 1));
	}

	return 0;
}