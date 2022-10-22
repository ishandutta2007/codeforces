#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5 + 5;
void solve () {
	int n; scanf ("%d",&n);
	vector<int> a(n);
	int cntneg = 0, cntpos = 0;
	for (int i = 0; i < n; i++) {
		scanf ("%d",&a[i]);
	}
	sort(a.begin(),a.end());
	long long sum = accumulate(a.begin(),a.end(),0LL), cur = 0;
	double ret = -1e18;
	for (int i = 0; i+1 < n; i++) {
		cur += a[i]; sum -= a[i];
		ret = max(ret,(double)cur / (i + 1) + (double)sum / (n - i - 1));
	}
	printf ("%.12f\n",ret);
}
int main() {
	int t; scanf ("%d",&t);
	while (t--) solve();
    return 0;
}