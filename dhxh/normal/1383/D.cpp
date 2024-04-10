#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 305;

int n, m, t;

int a[maxn][maxn];
int r[maxn];
int c[maxn];

bool f[maxn * maxn][2];

struct ex {
	int x, y;
};

ex p[maxn * maxn];

int ans[maxn][maxn];
bool vis[maxn][maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	scanf("%d%d", &n, &m);
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d", &a[i][j]);
			c[j] = a[1][j];
		}
		r[i] = a[i][1];
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			c[j] = max(c[j], a[i][j]);
			r[i] = max(r[i], a[i][j]);
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			f[a[i][j]][0] = (r[i] == a[i][j]);
			f[a[i][j]][1] = (c[j] == a[i][j]);
		}
	}
	
	int x = 0, y = 0;
	
	queue <ex> q;
	
	for(i=n*m;i>0;i--){
		if(f[i][0] and f[i][1]){
			x++, y++;
			ans[x][y] = i;
			p[i] = {x, y};
			vis[x][y] = true;
			for(j=x-1;j>0;j--){
				q.push({j, y});
			}
			for(j=y-1;j>0;j--){
				q.push({x, j});
			}
		}else if(f[i][0]){
			x++;
			ans[x][y] = i;
			p[i] = {x, y};
			vis[x][y] = true;
			for(j=y-1;j>0;j--){
				q.push({x, j});
			}
		}else if(f[i][1]){
			y++;
			ans[x][y] = i;
			p[i] = {x, y};
			vis[x][y] = true;
			for(j=x-1;j>0;j--){
				q.push({j, y});
			}
		}else{
			//while(q.size() and vis[q.front().x][q.front().y]) q.pop();
			vis[q.front().x][q.front().y] = true;
			ans[q.front().x][q.front().y] = i;
			p[i] = {q.front().x, q.front().y};
			q.pop();
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			printf("%d", ans[i][j]);
			if(j != m) printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}