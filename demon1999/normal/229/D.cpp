//#include "grader.h"
#include <bits/stdc++.h>


using namespace std;

#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)


typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
//const int ma = 128 * 1024, mal = 8;
const ll mod = ll(1e9) + 7, bub = 1000;
int n, m, ans, a[5000], dp[5000], sum[5001];
vector<ll> h;

int get_sum(int r, int l) {
	re sum[r] - sum[l];
}
int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	cin >> n;
	forn (i, n) {
		cin >> a[i];
		sum[i + 1] += a[i];
		sum[i + 1] += sum[i];
		for (int j = i; j > 0; j--) {
			//cout << get_sum(j, dp[j - 1]) << " " << get_sum(i + 1, j) << endl;
			if (get_sum(j, dp[j - 1]) <= get_sum(i + 1, j)) {
				dp[i] = j;
				break;
			}
		}
		//cout << dp[i] << " ";
	}
	//cout << endl;
	int ans =0;
	int nu = n - 1;
	while (nu >= 0) {
		ans += nu - dp[nu];
		nu = dp[nu] - 1;
	}
	cout << ans;
}