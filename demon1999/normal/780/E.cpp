#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define mp make_pair
#define fi first
#define se second
#define sz(a) (int)a.size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

const int ma = 128 * 1024;
const ll mod = ll(1e9) + 7;
const int N = 5 * 100 * 1000;

int n, m, k, use[N];
vector<int> e[N];
vector<int> num;

void dfs(int nu) {
	num.push_back(nu + 1);
	use[nu] = 1;
	for (int v : e[nu]) {
		if (!use[v]) {
			dfs(v);
			num.push_back(nu + 1);
		}
	}
	
}

int main() {
	//iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	scanf("%d%d%d", &n, &m, &k);
	forn (i, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(0);
	if (sz(num) > 1) num.pop_back();
	int p = (sz(num)) / k, j = 0;
	forn (ii, k) {
		int c = p;
		if ((sz(num) - j) % (k - ii)) c++;
		int k = 0;
		for (int i = j; i < j + c; i++) {
			if (i == j || (i && num[i] != num[i - 1]))k++;
		}
		printf("%d ", k);
		for (int i = j; i < j + c; i++) {
			if (i == j || (i && num[i] != num[i - 1]))printf("%d ", num[i]);
		}
		j += c;
		printf("\n");
	}

}