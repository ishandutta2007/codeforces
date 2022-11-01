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

int n, m, q;

struct ex {
	int x;
	int y;
};

ex p[maxn];

int fa[maxn * 2];

vector <int> cx[maxn];
vector <int> cy[maxn];

int ans = 0;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int find(int x){
	if(fa[x] != x){
		fa[x] = find(fa[x]);
	}
	return fa[x];
}

int join(int x, int y){
	int ra = find(x);
	int rb = find(y);
	
	if(ra != rb){
		fa[ra] = rb;
	}
	
	return 0;
}

int main(){
	int i, j;
	int x, y;
	int tx = 0, ty = 0;
	bool isf = false;
	
	n = read();
	m = read();
	q = read();
	
	for(i=1;i<=n+m;i++){
		fa[i] = i;
	}
	
	for(i=1;i<=q;i++){
		p[i].x = x = read();
		p[i].y = y = read();
		cx[x].push_back(y + n);
		cy[y].push_back(x);
		join(x, y + n);
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<cx[i].size();j++){
			join(cx[i][j], cx[i][j - 1]);
		}
	}
	
	for(i=1;i<=m;i++){
		for(j=1;j<cy[i].size();j++){
			join(cy[i][j], cy[i][j - 1]);
		}
	}
	
	for(i=1;i<=n+m;i++){
		if(fa[i] == i){
			ans++;
		}
	}
	
	printf("%d\n", ans - 1);
	
	return 0;
}