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

vector <string> v = {
	{"1110111"},
	{"0010010"},
	{"1011101"},
	{"1011011"},
	{"0111010"},
	{"1101011"},
	{"1101111"},
	{"1010010"},
	{"1111111"},
	{"1111011"}
};

const int nax = 2200;
	
char w[nax][nax];

int qw(int a, int b) {
	int res = 0;
	rep(i, 0, 6) {
		if (w[a][i] == '1' && v[b][i] == '0') return 1e9;
		if (w[a][i] == '0' && v[b][i] == '1') res++;
	}
	return res;
}

int n, k;

int dp[nax][nax];

int main() {
	scanf ("%d%d", &n, &k);
	rep(i, 1, n) {
		scanf ("%s", w[i]);
	}
	dp[n + 1][0] = 1;
	per(i, 1, n) {
		rep(j, 0, k) {
			rep(c, 0, 9) {
				int s = qw(i, c) + j;
				if (s <= k)
					dp[i][s] |= dp[i + 1][j];
			}
		}
	}
	vector <int> ans;
	rep(i, 1, n) {
		per(c, 0, 9) {
			int nk = k - qw(i, c);
			if (nk >= 0 && dp[i + 1][nk] == true) {
				ans.pb(c);
				k = nk;
				break;
			}
		}
		if (ss(ans) != i) {
			printf ("-1\n");
			return 0;
		}
	}
	for (auto it : ans) printf ("%d", it);
	
	
	
	return 0;
}