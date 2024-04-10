#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
const int MN = 1e3 + 5;
void solve () {
	int n; scanf ("%d",&n);
	vector<int> a(n);
	for(int&i:a) scanf ("%d",&i);
	int c = -1;
	for (int i = 1; i < n; i++) if (a[i] >= a[i-1]) {
		if (c == -1) c = a[i] - a[i-1];
		else if (c != a[i] - a[i-1]) {
			printf ("-1\n");
			return;
		}
	}
	if (c == -1) { //decreasing
		set<int> killme;
		for (int i = 1; i < n; i++) killme.insert(a[i]-a[i-1]); 
		if ((int)killme.size() <= 1) printf ("0\n");
		else printf ("-1\n");
		return;
	}
	int m = -1;
	for (int i = 1; i < n; i++) if (a[i] < a[i-1]) {
		int diff = a[i] - a[i-1];
		if (m == -1) m = c - diff;
		else if (m != c - diff) {
			printf ("-1\n");
			return;
		}
	}
	if (m == -1) printf ("0\n");
	else if (m <= *max_element(a.begin(),a.end()) || c < 0 || c >= m) printf ("-1\n");
	else printf ("%d %d\n",m,c);
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}