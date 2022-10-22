#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5 + 5;
void solve () {
	int n,k; scanf ("%d %d",&n,&k);
	vector<array<int,2>> a(n);
	for (int i = 0; i < n; i++) {
		scanf ("%d",&a[i][0]);
		a[i][1] = i;
	}
	sort(a.begin(),a.end());
	vector<int> pos(n);
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (a[i][1] != a[i-1][1] + 1) {
			
			++cnt;
		}
	}
	printf (k >= cnt ? "YES" : "NO");
	printf ("\n");
}
int main() {
	int t; scanf ("%d",&t);
	while (t--) solve();
    return 0;
}