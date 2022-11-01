#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t, k;

vector <int> e[maxn];
bool vis[maxn];
vector <int> ans;
vector<int> vec[maxn];

int addedge(int x, int y){
	e[x].push_back(y);
	e[y].push_back(x);
	return 0;
}

int dfs(int x){
	int y;
	ans.push_back(x);
	vis[x] = true;
	
	for(int i=0;i<e[x].size();i++){
		y = e[x][i];
		
		if(!vis[y] and (ans.size() == 1 or ((ans[ans.size() - 1] == vec[y][0] and ans[ans.size() - 2] == vec[y][1]) or (ans[ans.size() - 1] == vec[y][1] and ans[ans.size() - 2] == vec[y][0])))){
			dfs(y);
		}
	}
	
	if(ans.size() != n){
		ans.pop_back();
		vis[x] = false;
	}
	
	return 0;
}

int main(){
	int i, j;
	int x, y;
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		scanf("%d%d", &x, &y);
		addedge(x, y);
		vec[x].push_back(i);
		vec[y].push_back(i);
	}
	
	dfs(1);
	
	for(i=0;i<n;i++){
		printf("%d ", ans[i]);
	}
	
	printf("\n");
	
	return 0;
}