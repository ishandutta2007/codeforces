#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
 
 
using namespace std;	

const int nax = 1e6 + 111;
const int pod = (1 << 20);
const long long INF = 1e18;

ll add[2 * pod];
pair <ll, int> t[2 * pod];

void push(int u) {
	if(!add[u])
		return;
	add[2 * u] += add[u];
	add[2 * u + 1] += add[u];
	t[2 * u].fi += add[u];
	t[2 * u + 1].fi += add[u];
	add[u] = 0;
}

void dod(int x, int y, int c, int u = 1, int l = 0, int r = pod - 1) {
	if(x <= l && r <= y) {
		t[u].fi += c;
		add[u] += c;
		return;
	}
	int m = (l + r) / 2;
	push(u);
	if(x <= m)
		dod(x, y, c, 2 * u, l, m);
	if(m < y)
		dod(x, y, c, 2 * u + 1, m + 1, r);
	t[u] = max(t[2 * u], t[2 * u + 1]);
}

pair<ll, int> query(int x, int y, int u = 1, int l = 0, int r = pod - 1) {
	if(x <= l && r <= y)
		return t[u];
	int m = (l + r) / 2;
	push(u);
	pair<ll, int> best = mp(-INF, 0);
	if(x <= m)
		best = max(best, query(x, y, 2 * u, l, m));
	if(m < y)
		best = max(best, query(x, y, 2 * u + 1, m + 1, r));
	return best;
}

int n;
int x[nax], y[nax], xx[nax], yy[nax], cost[nax];
vector <int> val;

int daj(int x) {
	return (int) (lower_bound(val.begin(), val.end(), x) - val.begin());
}

vector <int> gora, dol;

int main() {	
	scanf("%d", &n);
	FOR(i, 1, n) {
		scanf("%d%d%d", &x[i], &y[i], &cost[i]);
		x[i] += 1;
		y[i] += 1;
		val.pb(x[i]);
		val.pb(y[i]);
	}
	val.pb(0);
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	FOR(i, 1, n) {
		xx[i] = daj(x[i]);
		yy[i] = daj(y[i]);
		if(xx[i] >= yy[i])
			dol.pb(i);
		else
			gora.pb(i);
	}
	sort(gora.begin(), gora.end(), [](int a, int b) {
		return yy[a] < yy[b];
	});
	sort(dol.begin(), dol.end(), [](int a, int b) {
		return xx[a] < xx[b];
	});
	
	FOR(i, 0, pod - 1)
		t[i + pod].se = i;
	for(int i = pod - 1; 1 <= i; --i)
		t[i] = max(t[2 * i], t[2 * i + 1]);
	
	ll opt = 0;
	int l = -1, r = -1;
	int gg = 0, dd = 0;
	FOR(i, 0, ss(val) - 1) {
		dod(i, i, val[i]);
		ll koszt = -val[i] + query(0, i).fi;
		if(koszt >= opt) {
			opt = koszt;
			r = i;
			l = query(0, i).se;
		}
		if(i == ss(val) - 1)
			break;
		int Next = i + 1;
		while(dd < ss(dol) && xx[dol[dd]] <= Next) {
			dod(0, yy[dol[dd]], cost[dol[dd]]);
			dd += 1;
		}
		while(gg < ss(gora) && yy[gora[gg]] <= Next) {
			dod(0, xx[gora[gg]], cost[gora[gg]]);
			gg += 1;
		}
	}
	if(opt == 0) {
		l = 1000000002;
		r = 1000000002;
	}
	else {
		l = val[l] - 1;
		r = val[r] - 1;
	}
	printf("%lld\n", opt);
	printf("%d %d %d %d", l, l, r, r);
	
	
	
	return 0;
}