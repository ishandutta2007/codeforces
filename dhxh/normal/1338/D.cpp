#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

int f[maxn][2];
vector <int> e[maxn];

int ans = 1; 

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int dfs(int x, int fr){
	f[x][1] = 1;
	int c = e[x].size();
	priority_queue <int> q, qb;
	
	for(auto y : e[x]){
		if(y == fr) continue;
		dfs(y, x);
		f[x][0] = max(f[x][0], c - 2 + (fr == -1) + max(f[y][0], f[y][1]));
		f[x][1] = max(f[x][1], f[y][0] + 1);
		q.push(max(f[y][0], f[y][1]));
		qb.push(f[y][0]);
	}
	
	if(q.size() == 1){
		ans = max(ans, q.top() + c - 1);
	}else if(q.size() >= 2){
		int a = q.top();
		q.pop();
		int b = q.top();
		ans = max(ans, a + b + c - 2);
	}
	
	if(qb.size() == 1){
		ans = max(ans, qb.top() + 1);
	}else if(qb.size() >= 2){
		int a = qb.top();
		qb.pop();
		int b = qb.top();
		ans = max(ans, a + b + 1);
	}
	
	ans = max(ans, max(f[x][0], f[x][1]));
	
	return 0;
}

int main(){
	int i, j;
	int x, y;
	
	n = read();
	
	for(i=1;i<n;i++){
		x = read();
		y = read();
		e[x].push_back(y);
		e[y].push_back(x);
	}
	
	dfs(1, -1);
	
	printf("%d\n", ans);
	
	return 0;
}