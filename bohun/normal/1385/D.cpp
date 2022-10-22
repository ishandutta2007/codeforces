#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;	

const int N = 2e5 + 100;

int n;
int a[N];
int pref[N][26];

char s[N];

int cnt(int l, int r, int c) {
	return pref[r][c] - pref[l - 1][c];
}

int solve(int l, int r, int c) {
	if (l == r) return !cnt(l, r, c);
	int m = (l + r) / 2;
	int L = solve(l, m, c + 1), R = solve(m + 1, r, c + 1), D = (r - l + 1) / 2;
	return min(L + D - cnt(m + 1, r, c), R + D - cnt(l, m, c));
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		scanf ("%s", s + 1);
		rep(i, 1, n) {
			rep(j, 0, 25) pref[i][j] = pref[i - 1][j];
			pref[i][s[i] - 'a']++;
		}
		printf ("%d\n", solve(1, n, 0));
	}
	return 0;
}