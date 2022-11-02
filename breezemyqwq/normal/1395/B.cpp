#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int n, m, x, y, k;
bool vis[105][105];
int xi[10005], yi[10005];

void print() {
	for(int i = 1; i <= k; i++) {
		printf("%d %d\n", xi[i], yi[i]);
	}	
}

void dfs(int a, int b, int st) {
	if(st > k) {
		print();
		exit(0);
	}
	for(int i = 1; i <= n; i++) {
		if(!vis[i][b]) {
			vis[i][b] = true;
			xi[st] = i, yi[st] = b;
			dfs(i, b, st + 1);
			vis[i][b] = false;
		}
	}
	for(int i = 1; i <= m; i++) {
		if(!vis[a][i]) {
			vis[a][i] = true;
			xi[st] = a, yi[st] = i;
			dfs(a, i, st + 1);
			vis[a][i] = false;
		}
	}
}

int main() {
	cin >> n >> m >> x >> y;
	k = n * m;
	vis[x][y] = true;
	xi[1] = x, yi[1] = y; 
	dfs(x, y, 2);
	return 0;
}