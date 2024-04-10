#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m;

int a[100005];

struct ex {
	int x;
	int y;
};

ex f[100005];
int cnt = 0;

int v[100005];

int t, k;

int l, r;

int geta(int x, int y){
	return a[(x - 1) * m + y];
}

bool cmp(ex x, ex y){
	return x.x < y.x;
}

int init(){
	int i, j;
	
	for(i=1;i<=m;i++){
		l = 1;
		for(j=2;j<=n;j++){
			if(geta(j, i) < geta(j - 1, i)){
				cnt++;
				f[cnt].x = l;
				f[cnt].y = j - 1;
				l = j;
			}
		}
		cnt++;
		f[cnt].x = l;
		f[cnt].y = n;
	}
	
	//sort(f + 1, f + cnt + 1, cmp);
	
	for(i=1;i<=cnt;i++){
		v[f[i].x] = max(v[f[i].x], f[i].y);
	}
	
	for(i=1;i<=n;i++){
		v[i] = max(v[i], v[i - 1]);
	}
	
	return 0;
}

bool query(int x, int y){
	if(v[x] >= y){
		return true;
	}else{
		return false;
	}
}

int main(){
	int i, j;
	
	scanf("%d", &n);
	scanf("%d", &m);
	
	t = n * m;
	
	for(i=1;i<=t;i++){
		scanf("%d", &a[i]);
	}
	
	init();
	
	scanf("%d", &k);
	
	for(i=1;i<=k;i++){
		scanf("%d", &l);
		scanf("%d", &r);
		if(l == r){
			printf("Yes\n");
		}else if(query(l, r)){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	
	return 0;
}