#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

struct ex {
	int y;
	int next;
};

ex e[2000005];
int eb[2000005];
int ec = 0;
int n;

int tt[2000005];
int sum = 0;
int root;

int et[5];
int etc = 0;

int addedge(int x, int y){
	ec++;
	
	e[ec].y = y;
	e[ec].next = eb[x];
	eb[x] = ec;
	
	return 0;
}

int dfs(int x){
	int y;
	int enow;
	
	enow = eb[x];
	
	while(enow){
		
		y = e[enow].y;
		dfs(y);
		
		if(tt[y] == sum){
			etc++;
			et[etc] = enow;
			tt[y] = 0;
		}
		
		tt[x] += tt[y]; 
		
		enow = e[enow].next;
	}
	
	return 0;
}

int main(){
	int i, j;
	int x, y, z;
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		scanf("%d", &x);
		scanf("%d", &tt[i]);
		sum += tt[i];
		addedge(x, i);
	}
	
	root = e[eb[0]].y;
	
	if(sum % 3){
		printf("-1\n");
		return 0;
	}
	
	sum /= 3;
	
	dfs(root);
	
	if(etc >= 2){
		printf("%d %d\n", e[et[1]].y, e[et[2]].y);
	}else{
		printf("-1\n");
	}
	
	return 0;
}