#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using ll = long long;

using namespace std;

ll out[100][100];

int n, q;

bool in(int r, int c) {
	return 1 <= r && r <= n && 1 <= c && c <= n;
}

int main() {
	
	for (int i = 2; i <= 51; ++i) {
		ll P = (1LL << (i - 2));
		int row = 1;
		for (int j = i; 1 <= j; --j) {
			out[row][j] = ((row & 1) ? P : 0);
			row++;
		}
	}
		
	
	int T;
	//scanf ("%d", &T);
	T = 1;
	while (T--) {
		scanf ("%d", &n);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				printf ("%lld ", out[i][j]);
				fflush(stdout);
			}
			printf ("\n");
			fflush(stdout);
		}
		fflush(stdout);
		scanf ("%d", &q);
		while (q--) {
			ll sum;
			scanf ("%lld", &sum);
			int row = 1, col = 1;
			for (int i = 1; i <= 2 * n - 1; ++i) {
				printf ("%d %d\n", row, col);
				fflush(stdout);
				if (!in(row + 1, col)) {
					col++;
					continue;
				}
				if (!in(row, col + 1)) {
					row++;
					continue;
				}
				
					
				if (out[row + 1][col]) {
					if ((sum & out[row + 1][col])) 
						row++;
					else col++;
				}
				else {
					if ((sum & out[row][col + 1]))
						col++;
					else row++;
				}
			}
		}		
	}																			
	return 0;
}