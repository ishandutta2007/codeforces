//this code was written by demon
#include <bits/stdc++.h>
//include "grader.h"

#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define se second
#define fi first
#define gi get_int()
#define mp(a, b) make_pair(a, b)
#define sz(a) (int)a.size()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int get_int() {
    int k;
    scanf("%d", &k);
    re k;
}

void my_assert(bool cc) {
    if (!cc) while(true);
}

int n, m, k;
bitset<501> dp1[501][501], dp[501], dp2[501];
int ok[1001];

vector<int> a;
int main() {
	//iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("kk.in", "r", stdin);
	//freopen(".out", "w", stdout);
	n = gi; k = gi;
	a.resize(n);
	forn (i, n) {
		a[i] = gi;
	}
	dp1[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			forn (nu, k + 1)
				dp1[i][j][nu] = dp1[i - 1][j][nu];
			if (j >= a[i - 1])
				forn (nu, k + 1) {
					if (dp1[i - 1][j - a[i - 1]][nu])
						dp1[i][j][nu] = 1;
					if (nu + a[i - 1] <= k && dp1[i - 1][j - a[i - 1]][nu])
						dp1[i][j][nu + a[i - 1]] = 1;
				}
		}
	}
	vector<int> ans;
	forn (i, k + 1) {
		if (dp1[n][k][i]) ans.push_back(i);
	}
	printf("%d\n", sz(ans));
	forn (i, sz(ans))
		printf("%d ", ans[i]);
    re 0;
}