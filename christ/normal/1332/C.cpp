#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 5;
char s[MN];
void solve () {
	int n,k; scanf ("%d %d",&n,&k);
	scanf ("%s",s);
	vector<vector<int>> cnt(k,vector<int>(26));
	for (int i = 0; i < n; i++) {
		int towards = i % k;
		if (towards >= (k + 1)/2) towards = (k - 1 - towards);
		++cnt[towards][s[i]-'a'];
	}
	int ans = 0;
	for (int i = 0; i <= k/2; i++) {
		int tot = accumulate(cnt[i].begin(),cnt[i].end(),0);
		int mx = *max_element(cnt[i].begin(),cnt[i].end());
		ans += tot - mx;
	}
	printf ("%d\n",ans);
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