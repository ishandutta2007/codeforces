#include <bits/stdc++.h>
#define ll long long
#define ld long double
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

const int N = 2e5 + 101;

int n, k, T;
char s[N];
int cnt[26];

bool good(int x) {
	int g = __gcd(k, x);
	int c = x / g;
	int z = 0;
	rep(i, 0, 25)
		z += cnt[i] / c;
	return z >= g;
}

void solve() {
	scanf ("%d%d", &n, &k);
	scanf ("%s", s + 1);
	n = strlen(s + 1);
	rep(i, 0, 25) cnt[i] = 0;
	rep(i, 1, n) cnt[s[i] - 'a']++;
	per(i, 1, n) {
		if (good(i)) {
			printf ("%d\n", i);
			return;
		}
	}
}

int main() {
	scanf ("%d", &T);
	while (T--) solve();	
	return 0;
}