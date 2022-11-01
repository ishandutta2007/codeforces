#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int n;

struct ex {
	int y;
	int next;
};

ex e[500005];

int eb[200005];
int ecnt[200005] = {0};
int ec = 0;

int color[200005];
int ans = 0;

int v[200005];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int addedge(int x, int y){
	ec++;
	e[ec].y = y;
	e[ec].next = eb[x];
	eb[x] = ec;
	ecnt[x]++;
	
	return 0;
}

int bfs(){
	int x, y;
	int enow;
	int i, j;
	color[1] = 1;
	queue <int> q;
	queue <int> qa;
	queue <int> qb;
	
	q.push(1);
	
	while(!q.empty()){
		x = q.front();
		
		v[color[x]] = true;
		qb.push(color[x]);
		
		enow = eb[x];
		
		while(enow){
			if(color[e[enow].y]){
				v[color[e[enow].y]] = true;
				qb.push(color[e[enow].y]);
			}else{
				qa.push(e[enow].y);
				q.push(e[enow].y);
			}
			enow = e[enow].next;
		}
		
		i = 1;
		
		while(!qa.empty()){
			y = qa.front();
			while(v[i]){
				i++;
			}
			color[y] = i;
			i++;
			qa.pop();
		}
		
		while(!qb.empty()){
			v[qb.front()] = false;
			qb.pop();
		}
		
		q.pop();
	}
	
	return 0;
}

int main(){
	int i, j;
	int x, y;
	
	n = read();
	
	for(i=1;i<=n-1;i++){
		x = read();
		y = read();
		addedge(x, y);
		addedge(y, x);
	}
	
	for(i=1;i<=n;i++){
		ans = max(ans, ecnt[i]);
	}
	
	ans++;
	
	bfs();
	
	printf("%d\n", ans);
	
	for(i=1;i<=n;i++){
		printf("%d ", color[i]);
	}
	
	printf("\n");
	
	return 0;
}