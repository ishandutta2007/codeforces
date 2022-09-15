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

const int maxn = 200010;
const int maxc = 26;
int n, k;
char s[maxn];
char t[maxn];
char S[maxn];
char T[maxn];
int b[maxn];
int a[maxn][maxc];
vi ans;

void preprocess() {
	int i = 0, j = -1; b[0] = -1;
	while (i < k) {
		while (j >= 0 && T[i] != T[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}

void KMP(int u, int v) {
	preprocess();
	int i = 0, j = 0;
	while (i < n) {
		while (j >= 0 && S[i] != T[j]) j = b[j];
		i++; j++;
		if (j == k) {
			a[i - k][u] = v;
			a[i - k][v] = u;
			j = b[j];
		}
	}
}

void solve() {
	ms(a, -1);
	scanf("%d%d", &n, &k);
	scanf("%s%s", s, t);
	FOR(i, 0, maxc) FOR(j, i, maxc) {
		FOR(u, 0, n) if (s[u] == i + 'a' || s[u] == j + 'a') S[u] = s[u]; else S[u] = '0';
		FOR(u, 0, k) if (t[u] == i + 'a') T[u] = j + 'a'; else if (t[u] == j + 'a') T[u] = i + 'a'; else T[u] = '0';
		KMP(i, j);
	}
	FOR(i, 0, n - k + 1) {
		bool ok = true;
		FOR(j, 0, maxc) if (a[i][j] == -1) {ok = false; break;}
		if (ok) ans.push_back(i + 1);
	}
	printf("%d\n", sz(ans));
	FOR(i, 0, sz(ans)) printf("%d ", ans[i]);
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