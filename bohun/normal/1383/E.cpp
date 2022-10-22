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
#define ld long double

using namespace std;	

const int N = 1e6 + 101;
const int MOD = 1e9 + 7;

int add(int a, int b) {
	return (a + b) % MOD;
}

int n, pref[N], dp[N], kiedy[N];
char s[N];	
vector <int> S;

int range(int l, int r) {
	return (pref[r] - (l ? pref[l - 1] : 0) + MOD) % MOD;
}

int main() {
	scanf ("%s", s + 1);
	n = strlen(s + 1);
	int z = 0;
	rep(i, 1, n) {
		if (s[i] == '0') z++;
		if (s[i] == '1') {
			if (z) S.pb(z);
			S.pb(0);
			z = 0;
		}
	}
	
	if (S.empty()) {
		printf ("%d\n", n);
		return 0;
	}
	
	int last = -1;
	
	rep(i, 0, n)
		kiedy[i] = -1;
		
	int ans = 0;
	
	rep(i, 0, ss(S) - 1) {
		int u = S[i];
		if (!u) {
			if (last == -1)
				dp[i] = add(1, (i > 0 ? dp[i - 1] : 0));
			else {
				if (!S[i - 1])
					dp[i] = dp[i - 1];
				else
					dp[i] = add(dp[i - 1], dp[i - 2]);
			}
			last = i;
		}
		else {
			if (!i)	
				dp[i] = u;
			else 
				rep(j, 1, u)
					dp[i] = add(dp[i], range(kiedy[j] + 1, i - 1));
			rep(j, 1, u)
				kiedy[j] = i;
		}
		if (!u || i + 1 == ss(S)) ans = add(ans, dp[i]);
		//printf ("%d %d\n", i, dp[i]);
		pref[i] = add(pref[i - 1], (!u ? dp[i] : 0));
	}
	if (z) ans = 1LL * ans * (z + 1) % MOD;
	printf("%d\n", ans);
	
	return 0;
}