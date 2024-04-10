#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << to_string(x) << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, K = 2155, N = 1e5 + 7;

struct Query {
	int l, r, t, k;
};

int a[N], ans[N], is_q[N];
array<int, 3> mod[N];
int L, R, T;
int cnt[N], cnt2[N], nxt[N], pre[N];

void add(int val) {
	cnt2[cnt[val]]--;
	cnt[val]++;
	cnt2[cnt[val]]++;
	if(cnt[val] == 1) { // new
		if(nxt[0] == 0) nxt[0] = 1, nxt[1] = 0, pre[1] = 0;
		else if(nxt[0] > 1) {
			int u = nxt[0];
			nxt[0] = 1, pre[1] = 0;
			nxt[1] = u, pre[u] = 1;
		}
	} else { // move (x -> x + 1)
		int x = cnt[val] - 1;
		if(cnt2[x]) {
			if(nxt[x] != x + 1) {
				int n = nxt[x];
				nxt[x] = x + 1, pre[x + 1] = x;
				nxt[x + 1] = n, pre[n] = x + 1;
			}
		} else {
			if(nxt[x] == x + 1) {
				int p = pre[x];
				nxt[p] = x + 1, pre[x + 1] = p;
			} else {
				int p = pre[x], n = nxt[x];			
				nxt[p] = x + 1, pre[x + 1] = p;
				nxt[x + 1] = n, pre[n] = x + 1;
			}
		}
	}
}

void del(int val) {
	cnt2[cnt[val]]--;
	cnt[val]--;
	cnt2[cnt[val]]++;
	if(cnt[val] == 0) { // remove
		if(cnt2[1] == 0) {
			int n = nxt[1];
			nxt[0] = n, pre[n] = 0;
		}
	} else { // move (x -> x - 1)
		int x = cnt[val] + 1;
		if(cnt2[x]) {
			if(pre[x] != x - 1) {
				int p = pre[x];
				nxt[p] = x - 1, pre[x - 1] = p;
				nxt[x - 1] = x, pre[x] = x - 1;
			}
		} else {
			if(pre[x] == x - 1) {
				int n = nxt[x];
				nxt[x - 1] = n, pre[n] = x - 1;
			} else {
				int p = pre[x], n = nxt[x];
				nxt[p] = x - 1, pre[x - 1] = p;
				nxt[x - 1] = n, pre[n] = x - 1;
			}
		}
	}
}

int qry(int k) {
	V<pi> aux;
	int sum = 0, ans = INF;
	int i = 0;
	while(nxt[i]) {
		i = nxt[i];
		aux.EB(i, cnt2[i]), sum += cnt2[i];
	}
	if(sum < k) return -1;
	sum = 0;
	for(int i = 0, j = 0; i < aux.size(); i++) {
		if(i) sum -= aux[i - 1].S;
		while(j < aux.size() && sum < k) sum += aux[j++].S;
		assert(j > i);
		if(sum >= k)
			ans = min(ans, aux[j - 1].F - aux[i].F);
	}
	return ans;
}

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];

	V<Query> qq;
	for(int i = 0; i < m; i++) {
		int op;
		cin >> op;
		if(op == 1) {
			is_q[i] = 1;
			int l, r, k;
			cin >> l >> r >> k;
			l--, r--;
			qq.PB({l, r, i, k});
		} else {
			int p, x;
			cin >> p >> x;
			p--;
			mod[i] = {p, a[p], x};
			a[p] = x;
		}
	}

	sort(ALL(qq), [](Query x, Query y) {
		return MP(x.l / K, MP(x.r / K, x.t)) < MP(y.l / K, MP(y.r / K, y.t));
	});

	add(a[0]);
	T = m - 1, L = 0, R = 0;

	for(auto q:qq) {
		int l = q.l, r = q.r, t = q.t, k = q.k;
		while(L > l) add(a[--L]);
		while(R < r) add(a[++R]);
		while(L < l) del(a[L++]);
		while(R > r) del(a[R--]);
		while(T < t) {
			++T;
			if(!is_q[T]) {
				int pos = mod[T][0], from = mod[T][1], to = mod[T][2];
				assert(a[pos] == from);
				a[pos] = to;
				if(L <= pos && pos <= R) {
					del(from);
					add(to);
				}
			}
		}
		while(T > t) {
			if(!is_q[T]) {
				int pos = mod[T][0], from = mod[T][2], to = mod[T][1];
				assert(a[pos] == from);
				a[pos] = to;
				if(L <= pos && pos <= R) {
					del(from);
					add(to);
				}
			}
			T--;
		}
		ans[t] = qry(k);
	}

	for(int i = 0; i < m; i++) {
		if(is_q[i]) {
			cout << ans[i] << '\n';
		}
	}


}