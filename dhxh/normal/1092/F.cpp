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

long long a[maxn];

struct tree {
	int root;
	vector <int> e[maxn];
	long long w[maxn];
	long long f[maxn];
	long long ans;
	
	int addedge(int x, int y){
		e[x].push_back(y);
		e[y].push_back(x);
		return 0;
	}
	
	int dfsa(int x, int fa){
		int i, j;
		int y;
		w[x] = a[x];
		
		for(i=0;i<e[x].size();i++){
			y = e[x][i];
			if(y != fa){
				dfsa(y, x);
				w[x] += w[y];
			}
		}
		
		return 0;
	}
	
	int dfsb(int x, int fa){
		int i, j;
		int y;
		
		f[x] = 0;
		
		for(i=0;i<e[x].size();i++){
			y = e[x][i];
			if(y != fa){
				dfsb(y, x);
				f[x] += f[y] + w[y];
			}
		}
		
		return 0;
	}
	
	int dfsc(int x, int fa, long long df, long long dw){
		int i, j;
		int y;
		long long fsum = 0, wsum = 0;
		
		ans = max(ans, f[x] + df);
		
		for(i=0;i<e[x].size();i++){
			y = e[x][i];
			if(y != fa){
				fsum += f[y] + w[y];
				wsum += w[y];
			}
		}
		
		for(i=0;i<e[x].size();i++){
			y = e[x][i];
			if(y != fa){
				dfsc(y, x, df + fsum - f[y] - w[y] + dw + wsum - w[y] + a[x], dw + wsum - w[y] + a[x]);
			}
		}
		
		return 0;
	}
	
	long long getans(){
		ans = 0;
		dfsa(1, -1);
		dfsb(1, -1);
		dfsc(1, -1, 0, 0);
		
		return ans;
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
	
	for(i=1;i<=n;i++){
		a[i] = read();
	}
	
	for(i=1;i<n;i++){
		x = read();
		y = read();
		f.addedge(x, y);
	}
	
	printf("%lld\n", f.getans());
	
	return 0;
}