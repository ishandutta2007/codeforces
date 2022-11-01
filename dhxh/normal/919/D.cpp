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

const int maxn = 3e5 + 5;

int n, m, t;

char a[maxn];

vector <int> e[maxn];
int ecnt[maxn];

bool flag = false;
bool vis[maxn];
bool inq[maxn];

int f[maxn][30];

queue <int> q;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int addedge(int x, int y){
	e[x].push_back(y);
	ecnt[y]++;
	
	return 0;
}

int dfs(int x){
	int y;
	
	vis[x] = true;
	inq[x] = true;
	
	for(auto y : e[x]){
		if(inq[y]){
			flag = true;
		}
		
		if(!vis[y]){
			dfs(y);
		}
	}
	
	inq[x] = false;
	return 0;
}

int main(){
	int i, j;
	int x, y;
	int ans = 0;
	
	n = read();
	m = read();
	
	scanf("%s", &a[1]);
	
	for(i=1;i<=m;i++){
		x = read();
		y = read();
		addedge(x, y);
	}
	
	for(i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	
	if(flag){
		printf("-1\n");
		return 0;
	}
	
	for(i=1;i<=n;i++){
		if(ecnt[i] == 0){
			q.push(i);
			f[i][a[i] - 'a'] = 1;
		}
	}
	
	while(!q.empty()){
		x = q.front();
		q.pop();
		
		for(auto y : e[x]){
			for(i=0;i<26;i++){
				f[y][i] = max(f[y][i], f[x][i]);
			}
			f[y][a[y] - 'a'] = max(f[y][a[y] - 'a'], f[x][a[y] - 'a'] + 1);
			ecnt[y]--;
			if(ecnt[y] == 0){
				q.push(y);
			}
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=0;j<26;j++){
			ans = max(ans, f[i][j]);
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}