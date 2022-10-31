#include <iostream>
using namespace std;

#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define allof(s) (s).begin(), (s).end()

template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }

int n;
int a[5008];
int csum[5008];
int dp[5008][5008]; // dp[end][len] = merge that or fewer

const int OO = 8888;

int maxPrevLen(int end, int len) {
	int lo = 0; // ok
	int hi = end - len + 1; // bad

	while (hi - lo > 1) {
		int mid = (lo + hi) / 2;
		if (csum[end] - csum[end-len] >= csum[end-len] - csum[end-len-mid]) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	// cerr << end << "," << len << "->" << lo << "\n";
	return lo;
}

int main() {
	csum[0] = 0;
	cin >> n;
	fori (i, 0, n) {
		cin >> a[i];
		csum[i+1] = csum[i] + a[i];
	}

	fori (end, 1, n+1) {
		fori (len, 1, end+1) {
			int ans = OO;
			if (len > 1) {
				ans = dp[end][len - 1];
			}

			if (end == len) {
				minify(ans, len - 1);
			}

			int prev = maxPrevLen(end, len);
			if (prev != 0) {
				minify(ans, dp[end-len][prev] + len - 1);
			}
			dp[end][len] = ans;
		}
	}

	cout << dp[n][n] << "\n";
}