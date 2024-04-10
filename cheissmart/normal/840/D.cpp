#include<bits/stdc++.h>
#define IO_OP ios::sync_with_stdio(0), cin.tie(0)
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 3e5 + 7;

int n, a[N];
array<pi, 4> t[N * 4];

int cnt[N];

array<pi, 4> add(array<pi, 4> lhs, array<pi, 4> rhs) {
	array<pi, 4> res;
	for(int i = 0; i < 4; i++) res[i] = {0, 0};
	int tt[10] = {}, sz = 0;
	for(int i = 0; i < 4; i++) if(lhs[i].S) {
		if(cnt[lhs[i].F] == 0) tt[sz++] = lhs[i].F;
		cnt[lhs[i].F] += lhs[i].S;
	}
	for(int i = 0; i < 4; i++) if(rhs[i].S) {
		if(cnt[rhs[i].F] == 0) tt[sz++] = rhs[i].F;
		cnt[rhs[i].F] += rhs[i].S;
	}
	sort(tt, tt + sz, [&] (int i, int j) {
		return cnt[i] > cnt[j];
	});
	while(sz >= 5) {
		for(int i = sz - 5; i < sz; i++)
			cnt[tt[i]] -= cnt[tt[sz - 1]];
		while(sz && cnt[tt[sz - 1]] == 0) sz--;
	}
	for(int i = 0; i < sz; i++) res[i] = {tt[i], cnt[tt[i]]}, cnt[tt[i]] = 0;
	return res;
}

void build(int v = 1, int tl = 0, int tr = n) {
	if(tr - tl == 1) {
		t[v][0] = {a[tl], 1};
		return;
	}
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm, tr);
	t[v] = add(t[v * 2], t[v * 2 + 1]);
}

array<pi, 4> qry(int l, int r, int v = 1, int tl = 0, int tr = n) {
	if(l <= tl && tr <= r)
		return t[v];
	int tm = (tl + tr) / 2;
	if(r <= tm) return qry(l, r, v * 2, tl, tm);
	else if(l >= tm) return qry(l, r, v * 2 + 1, tm, tr);
	else return add(qry(l, r, v * 2, tl, tm), qry(l, r, v * 2 + 1, tm, tr));
}

vi pos[N];

signed main()
{
	IO_OP;

	int q;
	cin >> n >> q;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		pos[a[i]].PB(i);
	}
		
	build();
	
	while(q--) {
		int l, r, k;
		cin >> l >> r >> k;
		l--;
		auto t = qry(l, r);
		int ans = INF;
		for(int i = 0; i < 4; i++) {
			int x = t[i].F;
			int cnt = lower_bound(ALL(pos[x]), r) - lower_bound(ALL(pos[x]), l);
			if(cnt * k > r - l)	
				ans = min(ans, x);
		}		
		if(ans == INF) ans = -1;
		cout << ans << '\n';
	}	
	
}