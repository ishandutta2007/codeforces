#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
const int MN = 5e5 + 5;
void solve () {
	int n; scanf ("%d",&n);
	vector<int> a(n);
	vector<vector<vector<int>>> togo(n+2);
	vector<int> last = {0};
	for (int i = 0; i < n; i++) {
		scanf ("%d",&a[i]);
		vector<int> take;
		if (i == 0) take = {1};
		else {
			do {
				take = togo[a[i]].back(); togo[a[i]].pop_back();
				take.back()++;
			} while (take <= last);
		}
		printf ("%d",take[0]);
		for (int i = 1; i < (int)take.size(); i++) printf (".%d",take[i]);
		printf ("\n");
		togo[a[i]+1].push_back(take);
		take.push_back(0);
		togo[1].push_back(take);
		last = take;
	}
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}