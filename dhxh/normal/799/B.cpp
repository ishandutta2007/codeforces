#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 200005;

int n, m;

struct clo {
	int p;
	int a;
	int b;
	int n;
	
	bool operator < (const clo &x) const {  
		return p > x.p;  
	}
};

bool v[maxn];

clo t[maxn];

priority_queue <clo> q[5];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int c;
	
	n = read();
	
	for(i=1;i<=n;i++){
		t[i].n = i;
		t[i].p = read();
	}
	
	for(i=1;i<=n;i++){
		t[i].a = read();
	}
	
	for(i=1;i<=n;i++){
		t[i].b = read();
	}
	
	for(i=1;i<=n;i++){
		q[t[i].a].push(t[i]);
		q[t[i].b].push(t[i]);
	}
	
	m = read();
	
	for(i=1;i<=m;i++){
		c = read();
		
		while(!q[c].empty() and v[q[c].top().n]){
			q[c].pop();
		}
		
		if(!q[c].empty()){
			printf("%d ", q[c].top().p);
			v[q[c].top().n] = true;
			q[c].pop();
		}else{
			printf("-1 ");
		}
	}
	
	printf("\n");
	
	return 0;
}