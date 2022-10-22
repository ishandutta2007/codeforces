#include <bits/stdc++.h>
#define LL long long
#define LD double
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

using namespace std;

const int N = 1e5 + 100;

int n, m, d;
int a, b;
int c[N];
bool dp[1 << 20];
int cnt[100];

void boom(int mask) {
	mask ^= ((1 << m) - 1);
	dp[mask] = 1;
}

int main() {	
	scanf ("%d%d%d", &n, &m, &d);
	rep(i, 0, m - 1) {
		scanf ("%d", &a);
		while (a--) {
			scanf ("%d", &b);
			c[b] = i;
		}
	}
	int x = 0;
	rep(i, 1, d) {
		cnt[c[i]]++;
		x |= (1 << c[i]);
	}
	boom(x);
	rep(i, d + 1, n) {
		cnt[c[i - d]]--;
		if (!cnt[c[i - d]]) x ^= (1 << (c[i - d]));
		cnt[c[i]]++;
		if (cnt[c[i]] == 1) x ^= (1 << c[i]);
		boom(x);
	}
	per(mask, 1, (1 << m) - 1) {
		rep(j, 0, m - 1)
			if (((mask >> j) & 1) == 0)
				dp[mask] |= dp[mask ^ (1 << j)];
	}
	int best = m;
	rep(mask, 1, (1 << m) - 1) {
		if (!dp[mask]) best = min(best, __builtin_popcount(mask));
	}
	printf ("%d\n", best);
		
		
	return 0;
}