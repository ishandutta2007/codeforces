#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PI;
#define MP make_pair

PI q[4000020];
int s = 1, e = 0, n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
char str[2005][2005];
int deg[2005][2005];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i ++) scanf("%s", str[i] + 1);
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			if(str[i][j] == '*') continue;
			for(int k = 0;k < 4;k ++){
				int x = i + dx[k], y = j + dy[k];
				if(x >= 1 && x <= n && y >= 1 && y <= m && str[x][y] == '.') deg[i][j] ++;
			}
			if(deg[i][j] == 1) q[++ e] = MP(i, j);
		}
	}
	while(s <= e){
		int x = q[s].first, y = q[s].second;
		s ++;
		if(str[x][y] != '.') continue;
		int px, py;
		for(int k = 0;k < 4;k ++){
			int xx = x + dx[k], yy = y + dy[k];
			if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && str[xx][yy] == '.'){
				if(k == 0) str[x][y] = '<', str[xx][yy] = '>';
				else if(k == 1) str[x][y] = '>', str[xx][yy] = '<';
				else if(k == 3) str[x][y] = '^', str[xx][yy] = 'v';
				else if(k == 2) str[x][y] = 'v', str[xx][yy] = '^';
				px = xx, py = yy;
				deg[xx][yy] = deg[x][y] = 0;
			}
		}
		for(int k = 0;k < 4;k ++){
			int xx = px + dx[k], yy = py + dy[k];
			if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && str[xx][yy] == '.'){
				deg[xx][yy] --;
				if(deg[xx][yy] == 1) q[++ e] = MP(xx, yy);
			}
		}
	}
	int flag = 0;
	for(int i = 1;i <= n;i ++) for(int j = 1;j <= m;j ++) if(str[i][j] == '.') flag = 1;
	if(flag) printf("Not unique\n");
	else for(int i = 1;i <= n;i ++) printf("%s\n", str[i] + 1);
	return 0;
}