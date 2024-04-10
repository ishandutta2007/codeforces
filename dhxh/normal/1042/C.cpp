#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

struct ex {
	int x;
	int n;
};

ex a[maxn];

vector <int> v;

bool cmp(ex x, ex y){
	return x.n < y.n;
}

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x = 0, y = 0, z;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i].x = i;
		a[i].n = read();
	}
	
	sort(a + 1, a + n + 1, cmp);
	
	for(i=1;i<=n;i++){
		if(a[i].n < 0){
			x = i;
			y = x;
		}
		if(a[i].n == 0){
			y = i;
		}
	}
	
	z = 1;
	
	if(x % 2){
		for(i=2;i<=x-1;i++){
			printf("1 %d %d\n", a[z].x, a[i].x);
			z = i;
		}
		
		if(x != 0){
			v.push_back(a[x].x);
		}
	}else{
		for(i=2;i<=x;i++){
			printf("1 %d %d\n", a[z].x, a[i].x);
			z = i;
		}
	}
	
	for(i=x+1;i<=y;i++){
		if(i == n and x <= 1){
			break;
		}
		v.push_back(a[i].x);
	}
	
	for(i=1;i<v.size();i++){
		printf("1 %d %d\n", v[i - 1], v[i]);
	}
	
	if(v.size()){
		printf("2 %d\n", v[v.size() - 1]);
	}
	
	if(y == 0){
		y++;
	}
	
	if(a[z].n <= 0 and z == 1){
		z = y + 1;
		y++;
	}
	
	for(i=y+1;i<=n;i++){
		printf("1 %d %d\n", a[z].x, a[i].x);
		z = i;
	}
	
	return 0;
}