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

const int maxn = 100010;
int n, m;
int a[maxn];
int b[maxn];

void solve() {
	scanf("%d%d", &n, &m);
	int c; scanf("%d", &c);
	FOR(i, 0, c) {
		int x, y; scanf("%d%d", &x, &y);
		a[i] = x + y;
		b[i] = x - y;
	}
	sort(a, a + c);
	sort(b, b + c);
	int h; scanf("%d", &h);
	int dmax = INT_MAX, imax;
	FOR(i, 0, h) {
		int x, y; scanf("%d%d", &x, &y);
		int u = x + y;
		int v = x - y;
		int tmp = max(max(abs(a[0] - u), abs(a[c - 1] - u)), max(abs(b[0] - v), abs(b[c - 1] - v)));
		if (dmax > tmp) {dmax = tmp; imax = i + 1;}
	}
	printf("%d\n%d", dmax, imax);
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