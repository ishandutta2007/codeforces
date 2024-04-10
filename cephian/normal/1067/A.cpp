#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const ll M = 998244353;
const int N = 1e5+5;
int dp[N][2][201] = {};
int dps[N][2][201] = {};
int a[N] = {};

int main() {	
	fio;
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for(int d = 1; d <= 200; ++d) {
		if(a[1] == -1) {
			dp[1][0][d] = 0;
			dp[1][1][d] = 1;
		} else {
			dp[1][0][d] = 0;
			dp[1][1][d] = a[1] == d;
		}
		dps[1][0][d] = (dps[1][0][d-1] + dp[1][0][d]) % M;
		dps[1][1][d] = (dps[1][1][d-1] + dp[1][1][d]) % M;
	}

	for(int i = 2; i <= n; ++i) {
		for(int d = 1; d <= 200; ++d) {
			//l = still need one
			dp[i][1][d] = (dps[i-1][0][d-1] + dps[i-1][1][d-1]) % M;

			dp[i][0][d] = (dps[i-1][0][200] - dps[i-1][0][d-1] + M + dp[i-1][1][d]) % M;

			if(a[i] != -1 && a[i] != d) {
				dp[i][1][d] = 0;
				dp[i][0][d] = 0;
			}

			dps[i][0][d] = (dp[i][0][d] + dps[i][0][d-1]) % M;
			dps[i][1][d] = (dp[i][1][d] + dps[i][1][d-1]) % M;
		}
	}
	//for(int i = 1; i <= 3; ++i) {
	//	for(int j = 0; j < 2; ++j) {
	//		for(int k = 1; k <= 4; ++k) {
	//			printf("dp[%d][%d][%d] = %lld\n", i, j, k, dp[i][j][k]);
	//			//printf("dps[%d][%d][%d] = %lld\n", i, j, k, dps[i][j][k]);
	//		}
	//	}
	//}
	//cout << endl << endl;;
	cout << dps[n][0][200] << "\n";


}