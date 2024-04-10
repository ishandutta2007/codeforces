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
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 1e6 + 100;
const int MOD = 998244353;
const int P = 31;

int T, n;
char s[N];

int h1[N];
int h2[N];
int pot[N];

int daj1(int l, int r) {
	return (h1[r] - (LL) h1[l - 1] * pot[r - l + 1] % MOD + MOD) % MOD;
}

int daj2(int l, int r) {
	return (h2[l] - (LL) h2[r + 1] * pot[r - l + 1] % MOD + MOD) % MOD;
} 

void solve() {
	scanf ("%s", s + 1);
	n = strlen(s + 1);
	pot[0] = 1;
	rep(i, 1, n) pot[i] = (LL) pot[i - 1] * P % MOD;
	rep(i, 1, n) h1[i] = ((LL) h1[i - 1] * P % MOD + (s[i] - 'a' + 1)) % MOD;
	h2[n + 1] = 0;
	per(i, 1, n) h2[i] = ((LL) h2[i + 1] * P % MOD + (s[i] - 'a' + 1)) % MOD;
	int k = 0;
	while (k + 1 <= n - k && s[k + 1] == s[n - k]) k++;
	if (k >= n - k) {
		rep(i, 1, n) printf ("%c", s[i]);
		printf ("\n");
		return;
	}
	pair<int, int> best = {0, -1};
	rep(i, k + 1, n - k) {
		if (daj1(k + 1, i) == daj2(k + 1, i)) best = max(best, {i - k, 0});
		//cat(k + 1);
		//cat(i);
		//cat(daj1(k + 1, i));
		//cat(daj2(k + 1, i));
	}
	rep(i, k + 1, n - k) {
		if (daj1(i, n - k) == daj2(i, n - k)) best = max(best, {n - k - i  + 1, 1});
	}
	rep(i, 1, k) printf ("%c", s[i]);
	if (best.se == 0) rep(i, k + 1, k + best.fi) printf ("%c", s[i]);
	if (best.se == 1) rep(i, n - k - best.fi + 1, n - k) printf ("%c", s[i]);
	rep(i, n - k + 1, n) printf ("%c", s[i]);
	printf ("\n");
}

int main() {
	scanf ("%d", &T);
	while (T--) solve();
				
	
    return 0;
}