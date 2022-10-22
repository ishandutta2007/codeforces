#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> edge[1080], bedge[1080];
int dp[1080], res;
vector<int> nums;
int cnt[1080][1080];
bool come[1080];
int n, k;
int num[1080][1080];
void dfs(int x){
	if(come[x])return;
	come[x] = true;
	for(int i = 0;i < bedge[x].size();i++){
		int to = bedge[x][i];
		dfs(to);
	}
	nums.push_back(x);
}

int main(){
	cin >> n >> k;
	for(int i = 0;i < k;i++){
		for(int j = 0;j < n;j++){
			cin >> num[i][j];
		}
		for(int j = 0;j < n;j++){
			for(int l = j + 1;l < n;l++){
				cnt[num[i][j]][num[i][l]]++;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		edge[0].push_back(i);
		for(int j = 1;j <= n;j++){
			if(cnt[i][j] == k){
				edge[i].push_back(j);
				bedge[j].push_back(i);
			}
		}
	}
	for(int i = 0;i <= n;i++){
		dfs(i);
	}
	
	for(int ii = 0;ii <= n;ii++){
		int i = nums[ii];
		for(int j = 0;j < edge[i].size();j++){
			int to = edge[i][j];
			dp[to] = max(dp[to], dp[i] + 1);
		}
		res = max(res, dp[i]);
	}
	cout << res << endl;
	return 0;
	
}