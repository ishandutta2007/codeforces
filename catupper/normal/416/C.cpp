#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long Int;
typedef pair<int, int> P;
typedef pair<P, int> T;
Int dp[1080][1080];
P r[1080];
T req[1080];
int n, k;
vector<P> ans;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> req[i].first.first >> req[i].first.second;
		req[i].second = i;
	}
	cin >> k;
	for(int i = 1;i <= k;i++){
		cin >> r[i].first;
		r[i].second = i;
	}
	sort(req + 1, req + n + 1, greater<T>());
	sort(r + 1, r + k + 1, greater<P>());
	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= n;j++){//i== table , j<=group
			dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			if(req[j].first.first > r[i].first)continue;
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + req[j].first.second);
		}
	}
	int table = 0;
	for(int i = 0;i <= k;i++){
		if(dp[table][n] < dp[i][n]){
			table = i;
		}
	}
	int p = n;
	for(int i = table;i >= 1;i--){
		while(p && dp[i][p] == dp[i][p - 1])p--;
		if(p == 0)break;
		ans.push_back(P(req[p--].second, r[i].second));
		
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << " " << dp[table][n] << endl;
	for(int i = 0;i < ans.size();i++){
		cout << ans[i].first << " "<< ans[i].second << endl;
	}
	return 0;
}