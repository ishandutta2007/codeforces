#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 5;
const int maxm = 20;
int n, m;
int a[maxn];
int b[maxm];
vi block[6];
unsigned f[11][11][11][11][11][maxm];
int ans[maxn][maxm];

bool go(int i, int k) {
	if (i == m) {
		FOR(j, 0, n) if (a[j] != 0) return false;
		return true;
	}
	FOR(j, 0, n) if (a[j] > (m - i) / 2 + 1) return false;
	unsigned &tmp = f[a[0]][a[1]][a[2]][a[3]][a[4]][i];
	if (tmp & 1u << k) return false;
	tmp |= 1 << k;
	FOR(j, 0, sz(block[b[i]])) {
		int u = block[b[i]][j];
		bool flag = true;
		FOR(l, 0, n) {
			if (u & 1 << l) {
				if (~k & 1 << l) a[l]--;
				ans[l][i] = 1;
			}
			else ans[l][i] = 0;
			if (a[l] < 0) flag = false;
		}
		if (flag && go(i + 1, u)) return true;
		FOR(l, 0, n) if ((u & 1 << l) && (~k & 1 << l)) a[l]++;
	}
	return false;
}

void solve() {
	ms(a, 0); ms(b, 0); ms(f, 0); ms(ans, 0);
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) scanf("%d", a + i);
	FOR(i, 0, m) scanf("%d", b + i);
	FOR(i, 0, 1 << n) {
		int cnt = 0;
		FOR(j, 0, n) if (((i >> j) & 3) == 1) cnt++;
		block[cnt].push_back(i);
	}
	if (go(0, 0)) FOR(i, 0, n) {FOR(j, 0, m) ans[i][j] ? printf("*") : printf("."); printf("\n");}
}

int main() {
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}