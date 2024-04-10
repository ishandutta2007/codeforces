#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define vi vector <int>

using namespace std;

const int pod = (1 << 18);
const int MEM = 30000000;

int l[MEM], r[MEM];
LL sum[MEM][2];
int id = 1;

int add(int x, int y, int c, int k, int u, int le = 0, int pr = pod - 1) {
	int ja = id++;
	l[ja] = l[u], r[ja] = r[u], sum[ja][0] = sum[u][0], sum[ja][1] = sum[u][1];
	if (x <= le && pr <= y) {
		sum[ja][k] += c;
		return ja;
	}
	int mi = (le + pr) / 2;
	if (x <= mi) l[ja] = add(x, y, c, k, l[ja], le, mi);
	if (mi < y) r[ja] = add(x, y, c, k, r[ja], mi + 1, pr);
	return ja;
}

void add(pair<LL, LL> &a, pair<LL, LL> b) {
	a.fi += b.fi;a.se += b.se;
}

pair<LL, LL> query(int x, int u, int le = 0, int pr = pod - 1) {
	if (!u) return {0LL, 0LL};
	pair <LL, LL> f = {sum[u][0], sum[u][1]};
	if (le == pr ) return f;
	int mi = (le + pr) / 2;
	if (x <= mi) add(f, query(x, l[u], le, mi));
	if (mi < x) add(f, query(x, r[u], mi + 1, pr));
	return f;
}
		

int n, a, b, c, d, e, f, q;

int root[pod];

int main() {	
	scanf ("%d", &n);
	
	root[0] = id++;
	rep(i, 1, n) {
		scanf ("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
		a++;
		root[i] = add(0, a - 1, c, 0, root[i - 1]);
		root[i] = add(a, b, e, 0, root[i]);
		root[i] = add(a, b, d, 1, root[i]);
		root[i] = add(b + 1, pod - 1, f, 0, root[i]);
	}
	
	scanf ("%d", &q);
	LL last = 0;
	while (q--) {
		scanf ("%d%d%d", &a, &b, &c);
		c = (c + last) % 1000000000;
		
		if (c > 200000) {
			last = (query(200001, root[b]).fi - query(200001, root[a - 1]).fi);
			printf ("%lld\n", last);
			continue;
		}
		
		pair <LL, LL> ri = query(c, root[b]);
		pair <LL, LL> le = query(c, root[a - 1]);
		last = ri.fi - le.fi + (ri.se - le.se) * c;
		printf ("%lld\n", last);
	}
	
	
	return 0;
}