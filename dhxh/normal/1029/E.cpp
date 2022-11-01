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

int ans = 0;

struct tree {
	int root;
	vector <int> e[maxn];
	int dep[maxn];
	bool vis[maxn];
	int ans;
	
	int addedge(int x, int y){
		e[x].push_back(y);
		e[y].push_back(x);
		return 0;
	}
	
	int dfs(int x, int f){
		int i, j;
		int y;
		int ret = -1;
		bool isa = 0;
		
		for(i=0;i<e[x].size();i++){
			y = e[x][i];
			if(y != f){
				dep[y] = dep[x] + 1;
				ret = max(ret, dfs(y, x));
				isa = isa | vis[y];
			}
		}
		
		if(ret == -1){
			ret = 1;
		}
		
		if(ret == 1){
			if(dep[x] > 2 and !isa){
				ret++;
			}
		}else if(ret == 2){
			ans++;
			vis[x] = true;
			ret = 1;
		}
		
		return ret;
	}
	
	int getans(){
		dep[1] = 0;
		dfs(1, -1);
		
		return ans;
	}
	
	int init(){
		root = 1;
		ans = 0;
		dep[root] = 0;
		
		return 0;
	}
};

tree f;

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
		x = read();
		y = read();
		f.addedge(x, y);
	}
	
	f.init();
	
	printf("%d\n", f.getans());
	
	return 0;
}