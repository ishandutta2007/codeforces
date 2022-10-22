#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
 
using ll = long long;
using ld = long double;
using namespace std;

const int N = 2005;
const int M = 1e6 + 1500;

int n, m;
int a[N], b[N], c[N], d[N], ord[N];
multiset <int> S;
vector <int> add[M], del[M];


int main() {
	scanf ("%d%d", &n, &m);
	rep(i, 1, n)
		scanf ("%d%d", a + i, b + i);
	rep(i, 1, m) 
		scanf ("%d%d", c + i, d + i), ord[i] = i;
	sort(ord + 1, ord + m + 1, [&](int p, int q) {
		if (c[p] != c[q]) return c[p] < c[q];
		return d[p] < d[q];
	});
	vector <int> q;
	rep(i, 0, m - 1) {
		int id = ord[i + 1];
		while (sz(q) && d[q.back()] <= d[id])
			q.pop_back();
		q.pb(id);
	}
	rep(i, 1, n) {
		//~ cat(i);
		int last = -1;
		for (auto x : q) {
			if (c[x] < a[i]) continue;
			int A = last + 1;
			int B = c[x] - a[i];
			if (d[x] - b[i] + 1 > 0) {
				add[A].pb(max(0, d[x] - b[i] + 1));
				del[B + 1].pb(max(0, d[x] - b[i] + 1));
			}
			//~ cout << A << " " << B << " " << d[x] << " " << b[i] << endl;
			last = B;
		}
	}
	int best = 1e9;
	rep(i, 0, M - 2) {
		for (auto x : add[i])
			S.insert(x);
		for (auto x : del[i])
			S.erase(S.find(x));
		best = min(best, i + (S.empty() ? 0 : *(--S.end())));
	}
	printf ("%d\n", best);		
	
	return 0;
}