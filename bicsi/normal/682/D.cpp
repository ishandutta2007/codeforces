/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*******************Debugging defines*************************/

#define ok_dump() cerr<<"OK\n"
#define var_dump(x) cerr<<#x": "<<x<<'\n'
#define arr_dump(x, n) do{cerr<<#x"[]: ";\
     for(int _=0;_<n;++_) cerr<<x[_]<<" ";cerr<<'\n';}while(0)

/*************************************************************/

char stra[5000], strb[5000];
int DP[1005][1005][15][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, mk;
	cin >> n >> m >> mk;

	cin >> stra + 1 >> strb + 1;

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			for(int k = 1; k <= mk; ++k) {
				// Fac 0
				int val0 = 0;
				val0 = max(val0, DP[i - 1][j][k][0]);
				val0 = max(val0, DP[i - 1][j][k][1]);
				val0 = max(val0, DP[i][j - 1][k][0]);
				val0 = max(val0, DP[i][j - 1][k][1]);

				DP[i][j][k][0] = val0;

				//Fac 1
				if(stra[i] != strb[j]) {
					continue;
				}

				int val1 = 0;
				val1 = max(val1, DP[i - 1][j - 1][k][1]);
				val1 = max(val1, DP[i - 1][j - 1][k - 1][0]);
				val1 = max(val1, DP[i - 1][j - 1][k - 1][1]);

				DP[i][j][k][1] = val1 + 1;
			}
		}

	int ans = 0;
	for(int k = 0; k <= mk; ++k) {
		ans = max(ans, DP[n][m][k][0]);
		ans = max(ans, DP[n][m][k][1]);
	}

	cout << ans;
	
	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/