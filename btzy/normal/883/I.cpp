#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n, k;
int v[N];
int dp[N];
int suffix[N];

bool valid(int maxCost) {
	dp[n] = 1;
	suffix[n] = 1;
	suffix[n + 1] = 0;
	for(int i = n - 1; i >= 0; i--) {
		dp[i] = 0;
		int lo = i, hi = n - 1;
		while(lo < hi) {
			int mid = (lo + hi)/2;
			if(v[mid + 1] > v[i] + maxCost) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}
		if(lo >= i + k - 1) {
			int tmp = suffix[i + k] - suffix[lo + 2];
			if(tmp > 0)	dp[i] = 1;
		}
		suffix[i] = dp[i] + suffix[i + 1];	
	}
	return dp[0];
}

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++)	scanf("%d", &v[i]);
	sort(v, v + n);

	int l = 0, r = 1e9;
	while(l < r) {
		int mid = (l + r)/2;
		if(valid(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	cout<<l<<endl;
	return 0;
}