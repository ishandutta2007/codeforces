#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pib = pair<int,bool>;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#ifdef fread_unlocked
#define fread fread_unlocked
#define fwrite fwrite_unlocked
#endif
#define mp make_pair
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e5+5, MK = 6e4 + 5, MOD = 1e9+7, BASE = 31, MASK = (1 << 10) - 1, SQRT = 315;
int t[MN], a[MN];ll psa[MN][2], ans[MN], cur, val[MN];int needL[MN], needR[MN], cntL[MN], cntR[MN]; vector<ll> xs;
int getx (ll x) {return lower_bound(all(xs),x) - xs.begin();}
struct Q {
	int l,r,ind,bl;
	bool operator< (const Q &o) const {
		return bl == o.bl ? (bl&1 ? r < o.r : r > o.r) : bl < o.bl;
	}
};
void addR (int x) {
	++cntL[val[x-1]]; ++cntR[val[x]];
	cur += cntL[needR[x]];
}
void addL (int x) {
	++cntL[val[x-1]]; ++cntR[val[x]];
	cur += cntR[needL[x]];
}
void delR (int x) {
	cur -= cntL[needR[x]];
	--cntL[val[x-1]]; --cntR[val[x]];
}
void delL (int x) {
	cur -= cntR[needL[x]];
	--cntL[val[x-1]]; --cntR[val[x]];
}
int main () {
	int n,k;
	scanf ("%d %d",&n,&k);
	for (int i = 1; i <= n; i++) scanf ("%d",&t[i]), --t[i];
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&a[i]);
		psa[i][t[i]] = psa[i-1][t[i]] + a[i];
		psa[i][t[i]^1] = psa[i-1][t[i]^1];
		val[i] = psa[i][0] - psa[i][1]; xs.push_back(val[i]);
	}
	xs.push_back(0);
	sort(all(xs)); xs.erase(unique(all(xs)),xs.end());
	for (int i = n; i >= 1; i--) {
		needR[i] = getx(val[i] - k);
		if (xs[needR[i]] != val[i] - k) needR[i] = MN - 1;
		needL[i] = getx(val[i-1] + k);
		if (xs[needL[i]] != val[i-1] + k) needL[i] = MN - 1;
		val[i] = getx(val[i]);
	}
	val[0] = getx(val[0]);
	int qq;
	scanf ("%d",&qq);
	vector<Q> queries(qq);
	for (int i = 0; i < qq; i++) scanf ("%d %d",&queries[i].l,&queries[i].r), queries[i].bl = queries[i].l / SQRT, queries[i].ind = i;
	sort(all(queries));
	int curl = 1, curr = 0;
	for (Q &q : queries) {
		while (curr < q.r) addR(++curr);
		while (curl > q.l) addL(--curl);
		while (curr > q.r) delR(curr--);
		while (curl < q.l) delL(curl++);
		ans[q.ind] = cur;
	}
	for (int i = 0; i < qq; i++) printf ("%lld\n",ans[i]);
	return 0;
}