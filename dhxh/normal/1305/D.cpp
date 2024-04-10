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

const int maxn = 1000 + 5;

int n, m, t;

vector <int> e[maxn];

bool vis[maxn];
int color[maxn];
int ecnt[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int lca(int x, int y){
	cout << "? " << x << " " << y << endl;
	cin >> x;
	return x;
}

int bfs(int x, int l){
	queue <int> q;
	q.push(x);
	
	while(q.size()){
		x = q.front();
		q.pop();
		if(x == l) continue;
		vis[x] = true;
		
		for(auto y : e[x]){
			if(vis[y] or y == l) continue;
			vis[y] = true;
			q.push(y);
		}
	}
	
	return 0;
}

int dfs(int x, int fa, int c){
	color[x] = c;
	for(auto y : e[x]){
		if(vis[y] or y == fa) continue;
		ecnt[x]++;
		dfs(y, x, c);
	}
	return 0;
}

int main(){
	int i, j;
	int x, y, l;
	
	cin >> n;
	
	for(i=1;i<n;i++){
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	
	l = 1;
	
	bool flag = true;
	while(flag){
		int c = 0;
		memset(color, 0, sizeof(color));
		memset(ecnt, 0, sizeof(ecnt));
		for(auto y : e[l]){
			if(vis[y]) continue;
			c++;
			dfs(y, l, c);
		}
		
		
		for(i=1;i<=n;i++){
			if(color[i] == 1 and ecnt[i] == 0){
				x = i;
				break;
			}
		}
		
		if(c >= 2){
			for(i=1;i<=n;i++){
				if(color[i] == 2 and ecnt[i] == 0){
					y = i;
					break;
				}
			}
		}else{
			y = l;
		}
		
		l = lca(x, y);
		bfs(x, l), bfs(y, l);
		
		int cnt = 0;
		for(i=1;i<=n;i++){
			if(!vis[i]) cnt++;
		}
		flag = (cnt > 1);
	}
	
	for(i=1;i<=n;i++){
		if(!vis[i]){
			cout << "! " << i << endl;
			return 0;
		}
	}
	
	return 0;
}