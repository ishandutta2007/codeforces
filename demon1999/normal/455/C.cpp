
#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

const ll p = 239, mod = 1e9 + 7;
int n, m, pr[3 * 100001], h[3 * 100000], szz[3 * 100000], hh[3 * 100000], use[3 * 100000];

vector<int> e[3 * 100000];
int get_parent(int nu) {
	if (nu != pr[nu])
		pr[nu] = get_parent(pr[nu]);
	re pr[nu];
}

void merge1(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);
	if (a == b) re;
	if (szz[a] < szz[b]) swap(a, b);
	pr[b] = a;
	szz[a] += szz[b];
	h[a] = max(h[a], max(h[b], 1 + (h[b] + 1) / 2 + (h[a] + 1) / 2));
}

void dfs(int nu, int p) {
	pr[nu] = p;
	szz[p]++;
	use[nu] = 1;
	for (int v : e[nu]) {
		if (!use[v]) {
			dfs(v, p);
			hh[nu] = max(hh[nu], hh[v] + 1);
		}
	}
	//cout << nu << " " << hh[nu] << "\n";
}

void dfs1(int nu, int pr, int nh, int i) {
	int ma1 = nh, ma2 = 0;
	//cout << nu << " " << ma1 << " " << ma2 << "\n";
	for (int v : e[nu]) {
		if (v != pr) {
			if (ma1 < hh[v] + 1) {
				ma2 = ma1;
				ma1 = hh[v] + 1;
				continue;
			} else {
				ma2 = max(ma2, hh[v] + 1);
			}

		}
	}
	//cout << nu << " " << ma1 << " " << ma2 << "\n";
	h[i] = max(h[i], ma1 + ma2);
	for (int v : e[nu]) {
		if (v != pr) {
			if (ma1 == hh[v] + 1)
				dfs1(v, nu, ma2 + 1, i);
			else
				dfs1(v, nu, ma1 + 1, i);
		}
	}
}

int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	//scanf("%d%d%d%d", &n, &m, &q, &k);
	int q;
	scanf("%d%d%d", &n, &m, &q);
	//cin >> n >> m >> q;
	forn (i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		//cin >> a >> b;
		a--;
		b--;
		e[a].push_back(b);
		e[b].push_back(a);
		merge1(a, b);
	}
	forn (i, n) {
		if (!use[i]) {
			dfs(i, i);
			dfs1(i, i, 0, i);
		}
	}
	forn (i, q) {
		int tp, a;
		scanf("%d%d", &tp, &a);
		//cin >> tp >> a;
		a--;
		if (tp == 1) {
			printf("%d\n", h[get_parent(a)]);
			//cout << h[get_parent(a)] << "\n";
		} else {
			int b;
			scanf("%d", &b);
			//cin >> b;
			b--;
			merge1(a, b);
		}
	}
}