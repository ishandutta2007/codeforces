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

long long w[maxn];

vector <int> e[maxn];
vector <long long> c[maxn];

long long f[maxn];
long long minx[maxn];

long long ans = 0;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int addedge(int x, int y, long long cc){
	e[x].push_back(y);
	e[y].push_back(x);
	c[x].push_back(cc);
	c[y].push_back(cc);
	
	return 0;
}

int dfs(int x, int fa){
	int y;
	int i, j;
	priority_queue <long long> q;
	
	q.push(0);
	
	for(i=0;i<e[x].size();i++){
		y = e[x][i];
		if(y != fa){
			dfs(y, x);
			
			if(f[y] - c[x][i] + w[x] >= 0){
				ans = max(ans, f[y] - c[x][i] + w[x]);
				
				q.push(-(f[y] - c[x][i]));
				if(q.size() > 2){
					q.pop();
				}
			}
		}
	}
	
	if(q.size() == 2){
		long long tmp = -q.top();
		q.pop();
		
		ans = max(ans, w[x] - q.top() + tmp);
	}
	
	f[x] = (-q.top()) + w[x];
	
	ans = max(ans, f[x]);
	
	return 0;
}

int main(){
	int i, j;
	int x, y, cc;
	
	n = read();
	
	for(i=1;i<=n;i++){
		w[i] = read();
	}
	
	for(i=1;i<n;i++){
		x = read();
		y = read();
		cc = read();
		addedge(x, y, cc);
	}
	
	dfs(1, -1);
	
	printf("%lld\n", ans);
	
	return 0;
}