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
	int x, y, w;
} e[maxn];

int fa[maxn];

vector <ex> a;
vector <ex> b;

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

int init(){
	int i, j;
	
	for(i=1;i<=n;i++){
		fa[i] = i;
	}
	
	return 0;
}

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

bool cmp(ex x, ex y){
	return x.w < y.w;
}

int main(){
	int i, j;
	int ans = 0;
	
	n = read();
	m = read();
	
	for(i=1;i<=m;i++){
		e[i].x = read();
		e[i].y = read();
		e[i].w = read();
	}
	
	sort(e + 1, e + m + 1, cmp);
	
	init();
	
	for(i=1;i<=m;i+=a.size()){
		a.clear();
		b.clear();
		for(j=i;j<=m;j++){
			if(e[j].w == e[i].w){
				a.push_back(e[j]);
			}else{
				break;
			}
		}
		
		for(ex t : a){
			if(find(t.x) != find(t.y)){
				b.push_back(t);
			}
		}
		
		for(ex t : b){
			if(find(t.x) != find(t.y)){
				join(t.x, t.y);
			}else{
				ans++;
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}