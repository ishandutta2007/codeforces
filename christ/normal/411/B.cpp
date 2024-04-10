#include <bits/stdc++.h>
using namespace std;
int main () {
	int n,m,k;
	scanf ("%d %d %d",&n,&m,&k);
	vector<vector<int>> what(n+1,vector<int>(m+1));
	vector<int> when(n+1); vector<int> lockedMemory(k+1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf ("%d",&what[i][j]);
		}
	}
	for (int t = 1; t <= m; t++) {
		for (int i = 1; i <= n; i++) if (!when[i]) {
			int wantToGo = what[i][t];
			if (wantToGo == 0) continue;
			if (lockedMemory[wantToGo]) {
				when[i] = t;
				if (lockedMemory[wantToGo] < 0) when[-lockedMemory[wantToGo]] = t;
				lockedMemory[wantToGo] = 1;
				continue;
			}
			lockedMemory[wantToGo] = -i;
		}
		for (int i = 1; i <= k; i++) if (lockedMemory[i]<0) lockedMemory[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		printf ("%d\n",when[i]);
	}
	return 0;
}