#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, w;

long long bea[1005];
long long b[1005];
int wei[1005];
int we[1005];
int fa[1005];

long long f[1005];
long long tmpa[1005];

vector <int> g[1005];

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
		fa[rb] = ra;
		bea[ra] += bea[rb];
		wei[ra] += wei[rb];
	}
	
	return 0;
}

int main(){
	int i, j, k;
	int x, y;
	
	n = read();
	m = read();
	w = read();
	
	for(i=1;i<=n;i++){
		fa[i] = i;
		wei[i] = read();
		we[i] = wei[i];
	}
	
	for(i=1;i<=n;i++){
		bea[i] = read();
		b[i] = bea[i];
	}
	
	for(i=1;i<=m;i++){
		x = read();
		y = read();
		join(x, y);
	}
	
	for(i=1;i<=n;i++){
		g[find(i)].push_back(i);
	}
	
	for(i=1;i<=n;i++){
		if(find(i) == i){
			for(j=0;j<=w;j++){
				tmpa[j] = f[j];
			}
			
			for(j=0;j<g[i].size();j++){	
				for(k=w;k>=we[g[i][j]];k--){
					f[k] = max(f[k], max(tmpa[k], tmpa[k - we[g[i][j]]] + b[g[i][j]]));
				}
			}
			
			for(j=w;j>=wei[i];j--){
				f[j] = max(f[j], max(tmpa[j], tmpa[j - wei[i]] + bea[i]));
			}
		}
	}
	
	cout << f[w] << endl;
	
	return 0;
}