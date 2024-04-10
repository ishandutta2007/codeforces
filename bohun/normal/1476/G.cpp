#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
 
using ll = long long;
using namespace std;

const int N = 1e5 + 100;
const int B = pow(N, 2.0 / 3);

int n, m, L = 1, R, T, a[N], val[N][2], pos[N], cnt[N], ff[N], res[N], LL[N], RR[N];

struct gao {
	int l, r, k, id;
};
vector<gao> g;

inline void merge(const int a, const int b) {
	if (a >= b) return;
	RR[a] = b;
	LL[b] = a;
}

void add(int x) {
	int A = LL[cnt[x]], B = RR[cnt[x]];
	ff[cnt[x]]--;
	if (!ff[cnt[x]]) {
		merge(A, cnt[x] + 1);
		if (cnt[x] + 1 < B)
			merge(cnt[x] + 1, B);
	}
	else {
		merge(cnt[x], cnt[x] + 1);
		if (cnt[x] + 1 < B)
			merge(cnt[x] + 1, B);
	}
	ff[++cnt[x]]++;
}

void del(int x) {
	int A = LL[cnt[x]], B = RR[cnt[x]];
	ff[cnt[x]]--;
	if (!ff[cnt[x]]) {
		merge(cnt[x] - 1, B);
		if (A < cnt[x] - 1)
			merge(A, cnt[x] - 1);
	}
	else {
		merge(cnt[x] - 1, cnt[x]);
		if (A < cnt[x] - 1)
			merge(A, cnt[x] - 1);
	}
	ff[--cnt[x]]++;
}

void change(int time, int k) {
	if (!pos[time]) return;
	if (L <= pos[time] && pos[time] <= R) {
		del(a[pos[time]]);
		a[pos[time]] = val[time][k];
		add(a[pos[time]]);
	}
	else 
		a[pos[time]] = val[time][k];
}

int main() {
	ff[0] = 1 << 30;
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", a + i);
	rep(i, 1, m) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int l, r, k;
			scanf("%d%d%d", &l, &r, &k);
			g.pb({l, r, k, i});
		}
		if (t == 2) {
			int p, x;
			scanf("%d%d", &p, &x);
			pos[i] = p;
			val[i][0] = a[p];
			val[i][1] = x;
			a[p] = x;
		}
	}
	sort(all(g), [&](gao p, gao q) {
		int pL = p.l / B, pR = p.r / B;
		int qL = q.l / B, qR = q.r / B;
		if (pL != qL) return pL < qL;
		if (pR != qR) return pR < qR;
		return p.id < q.id;
	});
	T = m;
	for (auto [l, r, k, id] : g) {
		while (R < r) add(a[++R]);
		while (l < L) add(a[--L]);
		while (R > r) del(a[R--]);
		while (l > L) del(a[L++]);
		while (T < id) change(++T, 1);
		while (T > id) change(T--, 0);
		
		vector<int> go;
		int x = 0;
		do {
			x = RR[x];
			if (x) go.pb(x);
			assert(sz(go) <= n);
		} while (x);
		
		int ans = 1 << 30, j = 0, sum = 0;
		for (auto x : go) {
			while (j < sz(go) && sum < k) 
				sum += ff[go[j++]];
			if (sum < k) break;
			ans = min(ans, go[j - 1] - x);
			sum -= ff[x];
		}
		if (ans == (1 << 30)) ans = -1;
		res[id] = ans;
	}	
	rep(i, 1, m)
		if (!pos[i])
			printf("%d\n", res[i]);
	return 0;
}

//~ 12 1
//~ 2 1 1 2 1 1 3 2 1 1 3 3
//~ 1 2 10 3