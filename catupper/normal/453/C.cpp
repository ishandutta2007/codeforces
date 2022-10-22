#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

vector<int> edge[108000];
vector<int> ans;
int cnt[108000];
bool come[108000];
int n, m, start = 1, a, b;

void dfs(int x){
	come[x] = true;
	cnt[x] ^= 1;
	ans.push_back(x);
	for(int i = 0;i < edge[x].size();i++){
		int to = edge[x][i];
		if(come[to])continue;
		dfs(to);
		ans.push_back(x);
		cnt[x] ^= 1;
		if(cnt[to] == 1){
			ans.push_back(to);
			cnt[to] ^= 1;
			ans.push_back(x);
			cnt[x] ^= 1;
		}
	}
	if(x == start && cnt[x] == 1){
		cnt[x] ^= 1;
		ans.pop_back();
	}
}


int main(){
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	for(int i = 1;i <= n;i++){
		cin >> cnt[i];
		if(cnt[i])start = i;
	}
	
	dfs(start);
	
	for(int i = 1;i <= n;i++){
		if(cnt[i] != 0){
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans.size() << endl;
	for(int i = 0;i < ans.size();i++){
		if(i)cout << " ";
		cout << ans[i];
	}
	return 0;
}