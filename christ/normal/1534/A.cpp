#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 5;
char grid[105][105];
void solve () {
	int n,m; scanf ("%d %d",&n,&m);
	for (int i = 1; i <= n; i++) {
		scanf ("%s",grid[i]+1);
	}
	bool ok = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char want = (i + j) % 2 ? 'R' : 'W';
			if (grid[i][j] != '.' && grid[i][j] != want) {
				ok = false;
			}
		}
	}
	if (ok) {
		printf ("YES\n");
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				printf ("%c",(i+j)%2?'R':'W');
			}
			printf ("\n");
		} 
		return;
	}
	ok = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char want = (i + j) % 2 ? 'W' : 'R';
			if (grid[i][j] != '.' && grid[i][j] != want) {
				ok = false;
			}
		}
	}
	if (ok) {
		printf ("YES\n");
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				printf ("%c",(i+j)%2?'W' : 'R');
			}
			printf ("\n");
		} 
		return;
	}
	printf ("NO\n");
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