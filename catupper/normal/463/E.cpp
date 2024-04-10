#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> divs[2160000];
vector<int> cnt[2160000];
vector<int> edge[108000];

int n, q, a, b, op, v, w, x;
int ans[108000];
int val[108000];
int depth[108000];
void dfs(int x, int last = -1){
	ans[x] = -1;
	for(int i = 0;i < divs[val[x]].size();i++){
		int v = divs[val[x]][i];
		if(!cnt[v].empty()){
			int tmp = *cnt[v].rbegin();
			if(ans[x] == -1)ans[x] = tmp;
			else if(depth[ans[x]] < depth[tmp]) ans[x] = tmp;
		}
	}
	for(int i = 0;i < divs[val[x]].size();i++){
		int v = divs[val[x]][i];
		cnt[v].push_back(x);
	}
	for(int i = 0;i < edge[x].size();i++){
		int to = edge[x][i];
		if(to == last)continue;
		depth[to] = depth[x] + 1;
		dfs(to, x);
	}              
	for(int i = 0;i < divs[val[x]].size();i++){
		int v = divs[val[x]][i];
		cnt[v].pop_back();
	}
}


int main(){

	for(int i = 2;i <= 2160000;i++){
		if(!divs[i].empty())continue;
		for(int j = i;j <= 2160000;j += i){
			divs[j].push_back(i);
		}
	}
	cin >> n >> q;
	for(int i = 1;i <= n;i++)cin >> val[i];
	for(int i = 1;i < n;i++){
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	dfs(1);
	for(int i = 0;i < q;i++){
		cin >> op;
		if(op == 1){
			cin >> v;
			cout << ans[v] << endl;
		}
		else{
			cin >> v >> w;
			val[v] = w;
			dfs(1);
		}
	}
	return 0;
}