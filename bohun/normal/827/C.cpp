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
#define ull unsigned long long

using namespace std;

const int N = 1e5 + 100;

int id(char c) {
	if (c == 'A') return 0;
	if (c == 'T') return 1;
	if (c == 'G') return 2;
	return 3;
}

struct fen {
	int f[N];
	void init() {
		rep(i, 0, N - 1) f[i] = 0;
	}
	void add(int x, int c) {
		for (int i = x; i < N; i += i & -i)
			f[i] += c;
	}
	int query(int x) {
		int res = 0;
		for (int i = x; 0 < i; i -= i & -i)
			res += f[i];
		return res;
	}
}t[11][11][4];
	
char s[N], e[N];
int n, a, b, c, q;
char z;

int main() {
	scanf ("%s", s + 1);
	n = strlen(s + 1);
	rep(g, 1, 10) rep(i, 1, 10) rep(j, 0, 3) t[g][i][j].init();
	rep(i, 1, n) 
		rep(g, 1, 10)
			t[g][i % g][id(s[i])].add(i, 1);
	scanf ("%d", &q);
	while (q--) {
		scanf ("%d%d", &a, &b);
		if (a == 1) {
			scanf (" %c", &z);
			rep(j, 1, 10) {
				t[j][b % j][id(s[b])].add(b, -1);
				t[j][b % j][id(z)].add(b, 1);
			}
			s[b] = z;
		}
		else {
			scanf ("%d", &c);
			scanf ("%s", e + 1);
			int len = strlen(e + 1);
			int ans = 0;
			rep(i, 1, len) {
				ans += t[len][(i - 1 + b) % len][id(e[i])].query(c) - t[len][(i - 1 + b) % len][id(e[i])].query(b - 1);
			}
			printf ("%d\n", ans);
		}
	}
	
	
	return 0;
}