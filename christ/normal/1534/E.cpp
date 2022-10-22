#include <bits/stdc++.h>
using namespace std;
const int MN = 505;
bool dp[MN][MN];
int main () {
	int n,k; scanf ("%d %d",&n,&k);
	dp[0][0] = 1;
	for (int numMoves = 1; numMoves <= 500; numMoves++) {
		for (int oldBits = 0; oldBits <= n; oldBits++) {
			for (int overLap = 0; overLap <= oldBits && overLap <= k; overLap++) if (oldBits + k - overLap <= n) {
				dp[numMoves][oldBits + k - 2 * overLap] |= dp[numMoves-1][oldBits];
			}
		}
	}
	for (int i = 1; i <= 500; i++) if (dp[i][n]) {
		int curMoves = i, curBits = n;
		vector<int> go;
		while (curMoves > 0) {
			for (int oldBits = 0; oldBits <= n; oldBits++) {
				for (int overLap = 0; overLap <= oldBits && overLap <= k; overLap++) if (oldBits + k - overLap <= n) {
					if (oldBits + k - 2 * overLap == curBits && dp[curMoves-1][oldBits]) {
						curMoves--;
						curBits = oldBits;
						go.push_back(overLap);
						goto succ;
					} 
				}
			}
			assert(false);
			succ:;
		}
		reverse(go.begin(),go.end());
		vector<int> curMask(n+1); int ret = 0;
		for (int want : go) {
			vector<int> togo; int want0 = k - want;
			for (int i = 1; i <= n; i++) {
				if (curMask[i] == 1 && want) {
					want--; curMask[i] = 0; togo.push_back(i);
				} else if (curMask[i] == 0 && want0) {
					want0--; curMask[i] = 1; togo.push_back(i);
				}
			}
			printf ("?");
			for (int i : togo) printf (" %d",i);
			printf ("\n");fflush(stdout);
			int got; scanf ("%d",&got); ret ^= got;
		}
		printf ("! %d\n",ret);
		fflush(stdout);
		return 0;
	}
	printf ("-1\n");
	return 0;
}
//aba aba
//012 345

//ab a ba
//01 2 34