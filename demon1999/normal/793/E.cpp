#include <bits/stdc++.h>  
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
#define prev previ
#define tm tmmm
#define div divv
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const ll mod = ll(1e9) + 7;
const int ma = 1024 * 1024 * 2;

int n, a[4], pr[100000], kk[100000], bd[100000], sum[4];
vector<int> e[100000], weights[4], nwe;

void dfs(int i) {
	if (sz(e[i]) == 0) {
		kk[i] = 1;
	}
	for (int v : e[i]) {
		dfs(v);
		kk[i] += kk[v];
	}
}

bool can_do(int i, int j, int sum) {
	if (sum < 0) re false;
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for (int v : weights[i]) {
		for (int j = n; j >= 0; j--) {
			if (j >= v && dp[j - v])
				dp[j] = 1;
		}
	}
	for (int v : weights[j]) {
		for (int j = n; j >= 0; j--) {
			if (j >= v && dp[j - v])
				dp[j] = 1;
		}
	}
	for (int v : nwe) {
		for (int j = n; j >= 0; j--) {
			if (j >= v && dp[j - v])
				dp[j] = 1;
		}
	}
	if (dp[sum]) re true;
	re false;
}
int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	cin >> n;
	forn (i, 4) {
		cin >> a[i]; a[i]--;
	}
	for (int i = 1; i < n; i++) {
		int p;
		cin >> p;
		p--;
		e[p].push_back(i);
		pr[i] = p;
	}
	dfs(0);
	forn (i, 4) {
		int we = a[i];
		sum[i] = 1;
		while (pr[we] != 0) {
			for (int q : e[pr[we]])
				if (q != we) {
					sum[i] += kk[q];
					weights[i].push_back(kk[q]);
				}
			we = pr[we];
		}
		bd[we] = 1;
	}
	for (int q : e[0])
		if (bd[q] == 0) {
			nwe.push_back(kk[q]);
		}
	int cnt = kk[0];
	if (cnt % 2 == 0 && can_do(0, 1, (cnt - 2) / 2 - sum[2]) && can_do(2, 3, (cnt - 2) / 2 - sum[0])) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	re 0;
}