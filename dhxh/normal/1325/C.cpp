#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

int ecnt[maxn];
vector <int> e[maxn];
pair <int, int> edge[maxn];
int color[maxn];

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
		scanf("%d%d", &x, &y);
		e[x].push_back(i);
		e[y].push_back(i);
		edge[i] = {x, y};
	}
	
	memset(color, -1, sizeof(color));
	x = -1;
	for(i=1;i<=n;i++){
		if(e[i].size() >= 3) x = i;
	}
	
	if(x == -1){
		for(i=0;i<n-1;i++){
			printf("%d\n", i);
		}
		return 0;
	}
	
	color[e[x][0]] = 0;
	color[e[x][1]] = 1;
	color[e[x][2]] = 2;
	int c = 2;
	
	for(i=1;i<n;i++){
		if(color[i] == -1){
			color[i] = ++c;
		}
		printf("%d\n", color[i]);
	}
	
	return 0;
}