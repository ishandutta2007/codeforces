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

const int maxn = 2e5 + 5;

int n, m, t;

vector <int> e[maxn];
vector <int> eb[maxn];
int c[maxn];

int s[maxn];

int st;

int f[maxn][2];

queue <int> q;

bool vis[maxn];
bool ind[maxn];

bool dfs(int x){
	int y;
	int i;
	vis[x] = true;
	ind[x] = true;
	
	for(i=0;i<e[x].size();i++){
		y = e[x][i];
		
		if(ind[y]){
			return true;
		}
		
		if(!vis[y]){
			if(dfs(y)){
				return true;
			}
		}
	}
	
	ind[x] = false;
	return false;
}

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y;
	bool flag = false;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		c[i] = read();
		x = i;
		for(j=1;j<=c[i];j++){
			y = read();
			e[x].push_back(y);
			eb[y].push_back(x);
		}
	}
	
	st = read();
	
	memset(s, -1, sizeof(s));
	
	for(i=1;i<=n;i++){
		if(e[i].size() == 0){
			flag = true;
			s[i] = 0;
			f[i][0] = 0;
			q.push(i);
		}
	}
	
	while(!q.empty()){
		x = q.front();
		q.pop();
		
		for(i=0;i<eb[x].size();i++){
			y = eb[x][i];
			if(s[y] != 2){
				if((s[x] != 2 and s[y] != !s[x]) or s[x] == 2){
					if(s[y] == -1 and s[x] != 2){
						s[y] = !s[x];
						f[y][!s[x]] = x;
					}else{
						if(s[x] == 2){
							f[y][0] = f[y][1] = x;
						}else{
							f[y][!s[x]] = x;
						}
						s[y] = 2;
					}
					q.push(y);
				}
			}
		}
	}
	
	if((s[st] == 0 and dfs(st)) or s[st] == -1){
		printf("Draw\n");
		return 0;
	}
	
	if(s[st] == 0){
		printf("Lose\n");
		return 0;
	}
	
	printf("Win\n");
	
	int d = 1;
	
	for(i=st;i;i=f[i][d],d=!d){
		printf("%d ", i);
	}
	printf("\n");
	
	
	return 0;
}