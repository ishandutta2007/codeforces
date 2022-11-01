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
const int mak = 8, ma = 1024 * 128 * 2;
ll n;
int seg[2 * ma];
int dp[100001], dp1[100001];

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
//	freopen("a.in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		vector<int> pq;
		for (int j = 2; (j * (j + 1)) / 2 <= i; j++) {
			int kk = (j * (j + 1)) / 2;
			if ((i - kk) % j == 0) {
				int ii = (i - kk) / j;
				pq.push_back(dp1[ii + j] ^ dp1[ii]);
			}
		}
		sort(pq.begin(), pq.end());
		dp[i] = -1;
		int pr = 0;
		forn (i, sz(pq)) {
			if (pq[i] > pr) {
				dp[i] = pr;
				break;
			}
			pr = pq[i] + 1;
		}
		if (dp[i] == -1) dp[i] = pr;
		dp1[i] = (dp1[i - 1] ^ dp[i]);
	}
	if (dp[n] == 0) {
		cout << "-1";
		re 0;
	}
	int i = n;
	for (int j = 2; (j * (j + 1)) / 2 <= i; j++) {
		int kk = (j * (j + 1)) / 2;
		if ((i - kk) % j == 0) {
			int ii = (i - kk) / j;
			if ((dp1[ii + j] ^ dp1[ii]) == 0) {
				cout << j << "\n";
				re 0;
			}
		}
	}
	re 0;
}