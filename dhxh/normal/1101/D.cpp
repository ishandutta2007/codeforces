#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

int a[maxn];

vector <int> e[maxn];

map <int, int> s[maxn];

int ans = 1;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int addedge(int x, int y){
	e[x].push_back(y);
	e[y].push_back(x);
	
	return 0;
}

int dfs(int x, int fa){
	int y;
	int i, j;
	vector <int> vec;
	
	int tmp = a[x];
	
	for(i=2;i<=sqrt(a[x]);i++){
		if(tmp % i == 0){
			vec.push_back(i);
			while(tmp % i == 0){
				tmp /= i;
			}
		}
	}
	
	if(tmp > 1){
		vec.push_back(tmp);
	}
	
	for(auto y : e[x]){
		if(y != fa){
			dfs(y, x);
		}
	}
	
	for(auto i : vec){
		s[x][i] = 1;
		for(auto y : e[x]){
			ans = max(ans, s[x][i] + s[y][i]);
			s[x][i] = max(s[x][i], s[y][i] + 1);
		}
	}
	
	return 0;
}

int main(){
	int i, j;
	int x, y;
	bool flag = false;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		if(a[i] != 1){
			flag = true;
		}
	}
	
	if(!flag){
		printf("0\n");
		return 0;
	}
	
	for(i=1;i<n;i++){
		x = read();
		y = read();
		addedge(x, y);
	}
	
	dfs(1, -1);
	
	printf("%d\n", ans);
	
	return 0;
}