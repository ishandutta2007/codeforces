#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5, SUB = 5e3 + 1;
void solve () {
	int n; scanf ("%d",&n);
	vector<int> a(n); map<int,int> cnt;
	long long ret = 0;
	for (int i = 0; i < n; i++) {
		scanf ("%d",&a[i]);
		ret += cnt[a[i] - i]++;
	}
	printf ("%lld\n",ret);
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}