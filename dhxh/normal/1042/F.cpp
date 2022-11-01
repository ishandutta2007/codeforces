#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1e6 + 5;

int n, m, t, k;

struct tree {
	int root;
	vector <int> e[maxn];
	int w[maxn];
	int ecnt[maxn];
	
	int dfs(int x, int f){
		int i, j;
		int y;
		vector <int> vec;
		int ret = 0;
		w[x] = 0;
		
		for(i=0;i<e[x].size();i++){
			y = e[x][i];
			if(y != f){
				ret += dfs(y, x);
				vec.push_back(w[y]);
			}
		}
		
		sort(vec.begin(), vec.end());
		
		for(i=vec.size()-1;i>0;i--){
			if(vec[i] + vec[i - 1] <= k){
				w[x] += vec[i];
				break;
			}else{
				ret++;
			}
		}
		
		if(vec.size() and i == 0){
			//if(vec[0] + w[x] <= k){
				w[x] += vec[0];
			//}else{
			//	ret++;
			//}
		}
		
		w[x]++;
		
		return ret;
	}
	
	int addedge(int x, int y){
		e[x].push_back(y);
		e[y].push_back(x);
		ecnt[x]++;
		ecnt[y]++;
		return 0;
	}
	
	int getans(){
		if(root != 0){
			return dfs(root, -1) + 1;
		}else{
			return 0;
		}
	}
	
	int init(){
		int i, j;
		root = 0;
		for(i=1;i<=n;i++){
			if(ecnt[i] != 1){
				root = i;
				break;
			}
		}
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
	k = read();
	
	for(i=1;i<n;i++){
		x = read();
		y = read();
		f.addedge(x, y);
	}
	
	f.init();
	
	printf("%d\n", f.getans());
	
	return 0;
}