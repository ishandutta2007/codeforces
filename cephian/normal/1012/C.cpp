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

const int N = 5005;
int a[N] = {0};
ll dp[N][N] = {};
const ll INF = 1e16;

int main() {	
	fio;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int j = 1; j < N; ++j)
		dp[0][j] = INF;
	for(int j = 1; j <= (n+1)/2; ++j) {
		ll runmin = 1e16;
		if(j == 1) runmin = 0;
		for(int i = 0; i < n; ++i) {
			if(i == 0) {
				if(j == 1)
					dp[i][j] = max(0, a[1]-a[0]+1);
				else
					dp[i][j] = INF;
			} else {
				dp[i][j] = runmin;
				if(i != 0)
					dp[i][j] += max(0, a[i-1]-a[i]+1);
				if(i >= 2 && j > 1) {
					ll des = max(0,a[i-1]-max(0,a[i-1]-a[i-2]+1)-a[i]+1);
					dp[i][j] = min(dp[i][j], dp[i-2][j-1] + des);
					runmin = min(runmin, dp[i-2][j-1]);
				}
				dp[i][j] += max(0, a[i+1]-a[i]+1);
			}
			if(dp[i][j] > INF)
				dp[i][j] = INF;
		}
	}
	for(int j = 1; j <= (n+1)/2; ++j) {
		ll best = INF;
		for(int i = 0; i < n; ++i) {
			best = min(best, dp[i][j]);
		}
		cout << best << " ";
	}
	cout << "\n";
}