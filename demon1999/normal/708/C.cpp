#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define re return
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)

typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int szz = 1000 * 1000;
string s;

int n, size1[szz], mx[szz], ok[szz];

vector<int> edge[szz];

void dfs(int nu, int pr) {
	size1[nu] = 1;
	for (int v : edge[nu]) {
		if (pr != v) {
			dfs(v, nu);
			size1[nu] += size1[v];
			mx[nu] = max(mx[nu], mx[v]);
		}
	}
	if (size1[nu] <= n / 2)
		mx[nu] = max(mx[nu], size1[nu]);
}

void dfs1(int nu, int pr, int szb, int mq) {
	int ma = szb - mq;
	int ma1 = mq, ma2 = 0;
	for (int v : edge[nu]) {
		if (v != pr) {
			ma = max(ma, size1[v] - mx[v]);
			if (ma1 < mx[v]) {
				ma2 = ma1;
				ma1 = mx[v];
				continue;
			}
			else
				ma2 = max(ma2, mx[v]);
		}
	}
	if (ma <= n / 2)
		ok[nu] = 1;
	for (int v : edge[nu]) {
		if (v != pr) {
			int nsz = szb + size1[nu] - size1[v], ma3 = ma2;
			if (ma1 != mx[v]) ma3 = ma1;
			if (nsz <= n / 2) ma3 = max(ma3, nsz);
			dfs1(v, nu, nsz, ma3);
		}
	}
}

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n;
	forn (i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(0, -1);
	dfs1(0, -1, 0, 0);
	forn (i, n)
		cout << ok[i] << " ";
	re 0;
}