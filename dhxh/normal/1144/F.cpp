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

int n, m;

vector <int> e[maxn];

vector <pair <int, int> > edge;

queue <int> q;

int color[maxn];

int main(){
	int i, j;
	int x, y;
	
	scanf("%d%d", &n, &m);
	
	for(i=1;i<=m;i++){
		scanf("%d%d", &x, &y);
		edge.push_back(make_pair(x, y));
		e[x].push_back(y);
		e[y].push_back(x);
	}
	
	color[1] = 1;
	
	for(auto i : e[1]){
		color[i] = 2;
		q.push(i);
	}
	
	while(!q.empty()){
		x = q.front();
		q.pop();
		int c = 0;
		
		for(auto y : e[x]){
			c |= color[y];
		}
		
		if(c != 0 and (c ^ 3) != color[x]){
			printf("NO\n");
			return 0;
		}
		
		c = color[x] ^ 3;
		
		for(auto y : e[x]){
			if(!color[y]){
				q.push(y);
			}
			color[y] = c;
		}
	}
	
	printf("YES\n");
	
	for(pair <int, int> tmp : edge){
		printf("%d", color[tmp.first] == 1);
	}
	printf("\n");
	
	return 0;
}