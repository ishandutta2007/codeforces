#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 5;
char s[MN];
void solve () {
	scanf ("%s",s);
	int n = strlen(s);
	vector<int> pre(n); pre[0] = s[0] == '1';
	for (int i = 1; i < n; i++) pre[i] = pre[i-1] + (s[i] == '1');
	int ret = min(pre[n-1],n-pre[n-1]);
	for (int i = 0; i < n; i++) {
		ret = min(ret,pre[i] + (n - 1 - i - pre[n-1] + pre[i]));
		ret = min(ret,(i + 1 - pre[i]) + pre[n-1] - pre[i]);
	}
	printf ("%d\n",ret);
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}
//aba aba
//012 345

//ab a ba
//01 2 34