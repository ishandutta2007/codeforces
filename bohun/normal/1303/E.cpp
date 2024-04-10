#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define make_pair
#define ss(x) (int) x.size();
#define fi first
#define se second

using namespace std;

const int nax = 411;

int T;

char s[nax];
char t[nax];

int dp[nax][nax];

int main() {
	scanf ("%d", &T);
	while (T--) {
		scanf ("%s", s + 1);
		scanf ("%s", t + 1);
		
		int S = strlen(s + 1);
		int T = strlen(t + 1);
		
		t[T + 1] = '#';
		
		bool ok = 0;
		for (int len = 1; len <= T; ++len) {
			for (int j = 0; j <= S; ++j)
				for (int k = 0; k <= len; ++k)
					dp[j][k] = -1;
			dp[0][0] = 0;
			for (int j = 0; j < S; ++j)
				for (int k = 0; k <= len; ++k)
					if (dp[j][k] != -1) {
						if (k + 1 <= len && s[j + 1] == t[k + 1])
							dp[j + 1][k + 1] = max(dp[j + 1][k + 1], dp[j][k]);
						if (len + dp[j][k] + 1 <= T && s[j + 1] == t[len + dp[j][k] + 1])
							dp[j + 1][k] = max(dp[j + 1][k], dp[j][k] + 1);
						dp[j + 1][k] = max(dp[j + 1][k], dp[j][k]);
					}
			if (dp[S][len] == T - len) {
				ok = 1;
				break;
			}
		}
		
		if (ok) printf ("YES\n");
		else printf ("NO\n");
	}
	return 0;
}