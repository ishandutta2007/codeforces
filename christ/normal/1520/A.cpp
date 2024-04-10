#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5, SUB = 5e3 + 1;
char s[55];
void solve () {
	int n; scanf ("%d",&n);
	scanf ("%s",s);
	set<char> have;
	for (int i = 0; i < n; i++) if (i == 0 || s[i] != s[i-1]) {
		if (have.count(s[i])) return (void) printf ("NO\n");
		have.insert(s[i]);
	}
	printf ("YES\n");
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}