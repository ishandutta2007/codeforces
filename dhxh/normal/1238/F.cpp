#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5;

int f[maxn][3];
vector <int> e[maxn];

int n, t;

int dfs(int x, int fa){
	int y;
	
	f[x][0] = f[x][1] = f[x][2] = 1;
	
	priority_queue <int> q;
	
	for(auto y : e[x]){
		if(y == fa)continue;
		dfs(y, x);
		f[x][2] = max(f[x][2], f[y][2]);
		f[x][2] = max(f[x][2], f[y][1] + 1);
		q.push(-f[y][0]);
		if(q.size() > 2)q.pop();
	}
	
	vector <int> vec;
	while(q.size()){
		vec.push_back(-q.top());
		q.pop();
	}
	
	reverse(vec.begin(), vec.end());
	
	if(vec.size() >= 1){
		int z = ((int)e[x].size() - (fa != -1)) - 1;
		f[x][0] =  max(f[x][0], vec[0] + z + 1);
	}
	
	if(vec.size() >= 2){
		int z = ((int)e[x].size() - (fa != -1)) - 2;
		f[x][1] =  max(f[x][1], vec[0] + vec[1] + z + 1);
	}
	
	f[x][1] = max(f[x][1], f[x][0]);
	f[x][2] = max(f[x][2], f[x][1]);
	
	return 0;
}

int main(){
	int i, j;
	int x, y;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		for(i=1;i<=n;i++){
			e[i].clear();
			f[i][0] = f[i][1] = f[i][2] = 0;
		}
		
		for(i=1;i<n;i++){
			scanf("%d%d", &x, &y);
			e[x].push_back(y);
			e[y].push_back(x);
		}
		
		dfs(1, -1);
		
		printf("%d\n", f[1][2]);
	}
	
	return 0;
}