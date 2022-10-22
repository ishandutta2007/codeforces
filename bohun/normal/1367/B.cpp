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

int n;
int a[N];

void solve() {
	scanf ("%d", &n);
	int cnt[2];
	cnt[0] = cnt[1] = 0;
	int bad = 0;
	rep(i, 0, n - 1) {
		scanf ("%d", a + i);
		a[i] %= 2;
		cnt[a[i]]++;
		if (a[i] != i % 2) bad++;
	}
	if (cnt[0] != (n + 1) / 2) {
		printf ("-1\n");
		return;
	}
	printf ("%d\n", bad / 2);
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) solve();	
	return 0;
}