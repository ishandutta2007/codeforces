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

vector <int> e[maxn];

bool f[maxn];
int g[maxn];
bool vis[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
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
	
	queue <int> q;
	for(i=1;i<=n;i++){
		if(e[i].size() == 1) f[i] = true, q.push(i), g[i] = 1, vis[i] = true;
		else x = i;
	}
	
	int cnt = 0;
	for(x=1;x<=n;x++){
		if(!f[x]){
			int c = 0;
			for(auto y : e[x]){
				if(f[y]) c++;
			}
			if(c > 1) cnt += c - 1;
			if(c >= 1) g[i] = true;
		}
	}
	
	bool flag = false;
	
	while(q.size()){
		int x = q.front();
		q.pop();
		for(auto y : e[x]){
			if(!vis[y]){
				g[y] = !g[x];
				q.push(y);
				vis[y] = true;
			}else{
				if(g[x] == g[y]){
					flag = true;
				}
			}
		}
	}
	
	if(!flag){
		printf("1 ");
	}else{
		printf("3 ");
	}
	
	printf("%d\n", n - 1 - cnt);
	
	return 0;
}