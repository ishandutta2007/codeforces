#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5, SUB = 5e3 + 1;
void solve () {
	int n; scanf ("%d",&n);
	if (n == 2) {
		printf ("-1\n");
	} else {
		for (int md = 1; md <= n; md++) {
			vector<int> go;
			for (int i = md; i <= n * n; i += n) {
				go.push_back(i);
			}
			if (md % 2 == 0) rotate(go.begin(),go.begin()+1,go.end());
			for (int i : go) printf ("%d ",i);
			printf ("\n");
		}
	}
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}