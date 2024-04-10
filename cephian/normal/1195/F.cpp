#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

const int N = 1e5+5;
int beg[N], ed[N];
int all[3*N];
int MAGIC = 400;
int ans[N];

map<pair<int,int>, int> save;
int add_vec(int a, int b, int c, int d) {
	int x = c - a;
	int y = d - b;
	int g = abs(__gcd(x, y));
	x /= g, y /= g;
	pair<int,int> p(x, y);
	if(save.count(p))
		return save[p];
	return save[p] = save.size();
}

int cur[3 * N] = {};
int sz = 0;

inline void add(int val) {
	if(cur[val]++ == 0)
		++sz;
}

inline void remove(int val) {
	if(--cur[val] == 0)
		--sz;
}

int L = 0, R = 0;
int ask(int l, int r) {
	while(R < r) add(all[R++]);
	while(l < L) add(all[--L]);
	while(r < R) remove(all[--R]);
	while(L < l) remove(all[L++]);
	return sz;
}

struct query {
	int l, r, i;

	bool operator<(const query& q) const {
		if(l/MAGIC == q.l/MAGIC)
			return r < q.r;
		return l < q.l;
	}
};

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	int ctr = 0;
	vector<query> Q;
	for(int i = 0; i < n; ++i) {
		int l;
		cin >> l;
		vector<int> x(l), y(l);
		beg[i] = ctr;
		for(int i = 0; i < l; ++i)
			cin >> x[i] >> y[i];
		for(int j = 0; j < l; ++j) {
			int k = (j+1) % l;
			all[ctr++] = add_vec(x[j], y[j], x[k], y[k]);
		}
		ed[i] = ctr-1;
	}
	int q;	
	cin >> q;
	for(int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		Q.push_back({beg[l], ed[r]+1, i});
	}
	sort(Q.begin(), Q.end());
	for(auto& qu : Q) {
		ans[qu.i] = ask(qu.l, qu.r);
	}
	for(int i = 0; i < q; ++i)
		cout << ans[i] << '\n';
}