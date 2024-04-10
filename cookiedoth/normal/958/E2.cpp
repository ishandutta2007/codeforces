/*
   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="
*/

#include <bits/stdc++.h>
#define ll long long
#define null NULL
#define double long double

using namespace std;

const ll MOD = 1e9 + 7;

int n, k;
vector<int> a, b;

pair<double, int> calc_dp(double lambda) {
	//cout << "lambda = " << lambda << endl;
	vector<double> dp(n + 1);
	vector<int> cnt(n + 1);
	for (int i = 2; i <= n; ++i) {
		double val = (double)b[i - 2] - lambda;
		if (dp[i - 2] + val < dp[i - 1]) {
			dp[i] = dp[i - 2] + val;
			cnt[i] = cnt[i - 2] + 1;
		}
		else {
			dp[i] = dp[i - 1];
			cnt[i] = cnt[i - 1];
		}
	}
	/*cout << "cnt" << endl;
	for (int i = 0; i <= n; ++i) {
		cout << cnt[i] << " ";
	}
	cout << endl;
	cout << "dp" << endl;
	for (int i = 0; i <= n; ++i) {
		cout << dp[i] << " ";
	}
	cout << endl;*/
	return {dp[n], cnt[n]};
}

int solve() {
	double l = 0, r = 1e16;
	for (int i = 0; i < 75; ++i) {
		double mid = (l + r) / 2;
		pair<double, int> res = calc_dp(mid);
		if (res.second > k)
			r = mid;
		else
			l = mid;
	}
	pair<double, int> res = calc_dp(l);
	double t = res.first + l * (double)k;
	//cout << "t = " << t << endl;
	return (int)(t + 0.5);
}

int main() {
    //cout.setf(ios_base::fixed);
    //cout.precision(8);
	cin >> k >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 1; i < n; ++i) {
		b.push_back(a[i] - a[i - 1]);
	}
	int res = solve();
	cout << res << endl;
}