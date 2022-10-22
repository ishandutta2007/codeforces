#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;	

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> a(n);
	for (auto &x : a)
		scanf("%d", &x);
	int L = a[0] + 1, R = a[0] + 1;
	for (int i = 1; i < n - 1; ++i) {
		int L2 = a[i] + 1;
		int R2 = a[i] + k;
		L = max(L - k + 1, L2);
		R = min(R + k - 1, R2);
		if (L > R) return printf("No\n"), void(0);
	}
	printf(a[n - 1] + 1 > R + k - 1 || a[n - 1] + k < L ? "No\n" : "Yes\n");
}
		

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}