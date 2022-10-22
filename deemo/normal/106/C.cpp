#include<iostream>
#include<algorithm>

using namespace std;

const int MX = 1e3 + 10;
const int MAXM = 10 + 2;

int n, m, c0, d0;
int a[MAXM], b[MAXM], c[MAXM], d[MAXM], dp[MX];

int main(){
	cin >> n >> m >> c0 >> d0;
	for (int i = 0; i < m; i++){
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		int k = a[i]/ b[i];
		for (int j = n; j >= 0; j--){
			int cc = 1;
			for (int w = j - c[i]; w >= 0 && w >= j - k * c[i]; w -= c[i], cc++)
				dp[j] = max(dp[j], dp[w] + d[i] * cc);
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++)
		ans = max(ans, dp[i] + ((n - i)/ c0) * d0);
	cout << ans << "\n";
	return	0;
}