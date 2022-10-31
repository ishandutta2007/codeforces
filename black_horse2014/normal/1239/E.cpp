#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int a[N * 2];
bool dp[N][50000 * N];
int prv[N][50000 * N];
int tick[111];
int main(){
//	freopen("input.txt", "r", stdin);
	ios_base :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n * 2; i++) cin >> a[i];
	sort(a, a + n * 2);
	dp[0][0] = 1;
	for(int i = 2; i < n * 2; i++)
		for(int k = min(n - 1, i - 1); k >= 1; k--)
			for(int j = 50000 * k; j >= a[i]; j--){
				if(!dp[k][j] && dp[k - 1][j - a[i]]){
					dp[k][j] = 1;
					prv[k][j] = i;
				}
			}
	int sum = 0;
	for(int i = 2; i < n * 2; i++) sum += a[i];
	int i;
	for(i = (sum + 1) / 2; ; i++)
		if(dp[n - 1][i])
			break;
	vector<int> ans;
	int k = n - 1;
	while(k >= 1){
		ans.push_back(prv[k][i]);
		i -= a[prv[k][i]];
		k--;
	}
	reverse(ans.begin(), ans.end());
	cout << a[0];
	for(int v : ans)
		cout << ' ' << a[v], tick[v] = 1;
	cout << "\n";
	for(i = 2 * n - 1; i >= 2; i--)
		if(!tick[i])
			cout << a[i] << ' ';
	cout << a[1] << "\n";
	return 0;
}
/*
4
10 9 8 7
1 4 5 6
*/