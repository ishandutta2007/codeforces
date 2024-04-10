#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6+5, SUB = 5e3 + 1;
char s[MN];
void solve () {
	int n; scanf ("%d",&n);
	scanf ("%s",s+1);
	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt += s[i] == '*';
	int tot = cnt; cnt = 0; int pos = -1;
	for (int i = 1; i <= n; i++) {
		cnt += s[i] == '*';
		if (cnt == (tot + 1) / 2) {
			pos = i;
			break;
		}
	}
	int go = pos - (tot - 1) / 2; long long ret = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '*') {
			ret += abs(i-go);
			go++;
		}
	}
	printf ("%lld\n",ret);
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}