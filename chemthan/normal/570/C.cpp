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

const int maxn = 300010;
int n, m;
char s[maxn];

void solve() {
	ms(s, 0);
	scanf("%d%d%s", &n, &m, s + 1);
	int ans = 0, tmp = 0;
	FOR(i, 1, n + 2) if (s[i] == '.') {if (!tmp) tmp = i;} else if (tmp) {ans += i - tmp - 1; tmp = 0;}
	while (m--) {
		int x; char c[10]; scanf("%d%s", &x, c);
		if (s[x] != c[0] && c[0] == '.') {
			if (s[x - 1] == '.') ans++;
			if (s[x + 1] == '.') ans++;
		}
		if (s[x] != c[0] && s[x] == '.') {
			if (s[x - 1] == '.') ans--;
			if (s[x + 1] == '.') ans--;
		}
		s[x] = c[0];
		printf("%d\n", ans);
	}
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