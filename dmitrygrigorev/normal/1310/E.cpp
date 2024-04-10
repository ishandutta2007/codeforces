#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int ans = 0;
int n, k;

bool gen(vector<int> &v) {

	if (v.size()) {

		vector<int> a = v;

		for (int i = 0; i < k-1; ++i) {
			vector<int> b;
			int sum = 0;
			for (int j = 0; j < a.size() && sum <= n; ++j) {
				for (int k = 0; k < a[j] && sum <= n; ++k) {
					b.push_back(a.size() - j);
					sum += b.back();
				}
			}
			if (sum > n) return false;
			a = b;
			reverse(a.begin(), a.end());
		}


		ans++;

	}

	int start = 1;
	if (v.size()) start = v.back();

	for (int i = start; i <= n; ++i) {
		v.push_back(i);
		if (!gen(v)) {
			v.pop_back();
			break;
		}
		v.pop_back();
	}

	return true;

}

const int N = 2500;

int dp[N][N];


const int mod = 998244353;

void solve1() {

	dp[n][0] = 1;

	for (int nxt = n; nxt >= 1; nxt--) {
		for (int sum = 0; sum <= n; ++sum) {
			dp[nxt-1][sum] = (dp[nxt-1][sum] + dp[nxt][sum]) % mod;
			if (sum + nxt <= n) dp[nxt][sum+nxt] = (dp[nxt][sum+nxt] + dp[nxt][sum]) % mod;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = (ans + dp[0][i]) % mod;
	}

	cout << ans;
	exit(0);

}

int tdp[N][N];
int tdp2[N][N];

void solve2() {

	tdp[0][0] = 1;

	for (int nxt = n; nxt >= 1; nxt--) {
		for (int sum = 0; sum <= n; ++sum) {
			for (int was = 0; was * nxt <= n; ++was) {
				tdp2[sum][was] = 0;
			}
		}
		for (int sum = 0; sum <= n; ++sum) {
			for (int was = 0; was*nxt <= n; was++) {
				tdp2[sum][was] = (tdp2[sum][was] + tdp[sum][was]) % mod;
				if (sum + nxt*(was+1) <= n) tdp[sum + nxt*(was+1)][was+1] = (tdp[sum + nxt*(was+1)][was+1] + tdp[sum][was]) % mod;
			}
		}
		for (int sum = 0; sum <= n; ++sum) {
			for (int was = 0; was * nxt <= n; ++was) {
				tdp[sum][was] = tdp2[sum][was];
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
		ans = (ans + tdp[i][j]) % mod;
	}

	cout << ans;
	exit(0);

}

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	if (k==1) {
		solve1();
	}
	if (k==2) {
		solve2();
	}

	vector<int> v;
	gen(v);	

	cout << ans;

}