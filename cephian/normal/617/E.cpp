#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << "\n";
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int N = 1e5+5;
int a[N] = {};

int n, m, k;
int lft = 0, rgt = n;
const int S = 3e6+5;
ll cnt[S] = {};
ll ans = 0;

inline void add(int i) {
	ans += cnt[a[i] ^ k];
	++cnt[a[i]];
}

inline void rem(int i) {
	--cnt[a[i]];
	ans -= cnt[a[i] ^ k];
}

inline ll move(int l, int r) {
	while(rgt < r) add(++rgt);
	while(lft > l) add(--lft);
	while(rgt > r) rem(rgt--);
	while(lft < l) rem(lft++);
	return ans;
}

const int MAGIC = 300;

struct query {
	int l, r, id;
	bool operator<(const query& q) {
		if(l/MAGIC == q.l/MAGIC) return r < q.r;
		return l < q.l;
	}
};


int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] ^= a[i-1];
	}
	lft = 0, rgt = 0;
	cnt[0] = 1;
	ans = 0;

	vector<query> queries(m);
	for(int i = 0; i < m; ++i) {
		queries[i].id = i;
		cin >> queries[i].l >> queries[i].r;
	}
	sort(queries.begin(), queries.end());
	vector<ll> answers(m);
	for(auto q : queries) {
		answers[q.id] = move(q.l-1, q.r);
	}
	for(int i = 0; i < m; ++i) {
		cout << answers[i] << "\n";
	}
}