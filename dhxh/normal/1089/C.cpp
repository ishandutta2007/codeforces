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

const int maxn = 505;
int inf = 0x3f3f3f3f;

int n, m, t;

vector <int> e[maxn];

bool vis[maxn];

queue <int> visq;

int df[maxn][maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int addedge(int x, int y){
	e[x].push_back(y);
	e[y].push_back(x);
	
	return 0;
}

struct tree {
	int root;
	int dis[maxn];
	int maxx;
	int st;
	queue <int> q;
	queue <int> qb;
	vector <int> edge[maxn];
	int ecnt[maxn];
	
	int adde(int x, int y){
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	
	bool bfsa(){
		int x, y;
		int i, j;
		int cnt = 0;
		
		memset(dis, -1, sizeof(dis));
		for(i=1;i<=n;i++){
			edge[i].clear();
			ecnt[i] = 0;
		}
		
		x = root;
		q.push(x);
		
		dis[x] = 0;
		
		while(!q.empty()){
			x = q.front();
			q.pop();
			cnt++;
			
			for(i=0;i<e[x].size();i++){
				y = e[x][i];
				if(dis[y] == -1 and !vis[y]){
					dis[y] = dis[x] + 1;
					q.push(y);
					adde(x, y);
				}
			}
		}
		
		return 0;
	}
	
	bool bfs(){
		int x, y;
		int i, j;
		int cnt = 0;
		
		x = root;
		q.push(x);
		
		dis[x] = 0;
		
		while(!q.empty()){
			x = q.front();
			q.pop();
			cnt++;
			qb.push(x);
			
			for(i=0;i<e[x].size();i++){
				y = e[x][i];
				if(dis[y] == -1 and !vis[y] and df[st][y] > df[root][y]){
					dis[y] = dis[x] + 1;
					q.push(y);
					adde(x, y);
				}
			}
		}
		
		for(i=1;i<=n;i++){
			vis[i] = true;
		}
		
		while(!qb.empty()){
			x = qb.front();
			qb.pop();
			vis[x] = false;
		}
		
		return cnt != 1;
	}
	
	int getp(){
		int i, j;
		int x = root, y;
		
		for(i=1;i<=n;i++){
			ecnt[i] = edge[i].size();
			if(ecnt[i] == 1){
				q.push(i);
			}
		}
		
		while(!q.empty()){
			x = q.front();
			q.pop();
			for(i=0;i<edge[x].size();i++){
				y = edge[x][i];
				ecnt[y]--;
				if(ecnt[y] == 1){
					q.push(y);
				}
			}
		}
		
		return x;
	}
	
	int init(int x){
		int i, j;
		
		root = x;
		
		memset(dis, -1, sizeof(dis));
		for(i=1;i<=n;i++){
			edge[i].clear();
			ecnt[i] = 0;
		}
		
		return bfs();
	}
};

tree f;

int solve(){
	int i, j;
	int st = 1;
	string opt;
	int x, y;
	int p;
	
	memset(vis, 0, sizeof(vis));
	
	f.root = 1;
	f.bfsa();
	
	st = f.getp();
	
	f.st = st;
	vis[st] = true;
	visq.push(st);
	cout << st << endl;
	cin >> opt;
	
	if(opt[0] == 'F'){
		return 0;
	}else{
		cin >> p;
	}
	
	while(f.init(p)){
		int tmp = f.getp();
		vis[tmp] = true;
		visq.push(tmp);
		cout << tmp << endl;
		cin >> opt;
		if(opt[0] == 'F'){
			return 0;
		}else{
			cin >> p;
		}
		f.st = tmp;
	}
	
	cout << f.root << endl;
	cin >> opt;
	
	return 0;
}

int main(){
	int i, j;
	int k;
	int x, y;
	
	cin >> n >> m;
	
	memset(df, 0x3f, sizeof(df));
	
	for(i=1;i<=n;i++){
		df[i][i] = i;
	}
	
	for(i=1;i<=m;i++){
		cin >> k;
		cin >> x;
		for(j=2;j<=k;j++){
			cin >> y;
			addedge(x, y);
			df[x][y] = df[y][x] = 1;
			x = y;
		}
	}
	
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				df[i][j] = min(df[i][j], df[i][k] + df[k][j]);
			}
		}
	}
	
	for(i=1;i<=n;i++){
		solve();
	}
	
	return 0;
}