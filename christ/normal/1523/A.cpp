#include <bits/stdc++.h>
using namespace std;
const int MN = 5e5 + 5;
void solve () {
	int n,m; scanf ("%d %d",&n,&m);
	vector<bool> a(n+2);
	for (int i = 1; i <= n; i++) {
		char ch; scanf (" %c",&ch);
		a[i] = ch - '0';
	}
	for (int i = 0; i < m; i++) {
		vector<bool> new_a(n+2);
		for (int i = 1; i <= n; i++) {
			new_a[i] = (a[i] || (a[i-1] ^ a[i+1]));
		}
		if (new_a == a) break;
		a = new_a;
	}
	for (int i = 1; i <= n; i++) printf ("%c",a[i]+'0');
	printf ("\n");
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}