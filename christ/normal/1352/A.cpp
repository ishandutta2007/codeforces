#include <bits/stdc++.h>
using namespace std;
void solve () {
	int n;
	scanf ("%d",&n);
	int pw = 1; vector<int> ans;
	while (n) {
		int dig = n % 10;
		if (dig != 0) ans.push_back(dig * pw);
		pw *= 10;
		n /= 10;
	}
	printf ("%d\n",(int)ans.size());
	for (int i : ans) printf ("%d ",i);
	printf ("\n");
}
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
	return 0;
}