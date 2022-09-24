#include<bits/stdc++.h>
using namespace std;
 
const int nax = 2005;
char sl[nax][nax];
// horizontal and vertical
int hor[nax][nax], ver[nax][nax];
 
int main() {
	int w, h;
	scanf("%d%d", &h, &w);
	for(int y = 0; y < h; ++y) scanf("%s", sl[y]);
	for(int y = 0; y < h; ++y) for(int x = 0; x < w; ++x) {
		hor[x+1][y+1] = hor[x][y+1] + hor[x+1][y] - hor[x][y];
		ver[x+1][y+1] = ver[x][y+1] + ver[x+1][y] - ver[x][y];
		if(sl[y][x] != '.') continue;
		if(x != w - 1 && sl[y][x+1] == '.') ++hor[x+1][y+1];
		if(y != h - 1 && sl[y+1][x] == '.') ++ver[x+1][y+1];
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
		--x1;--y1;
		int ans = 0;
		ans += hor[x2-1][y2] - hor[x1][y2] - hor[x2-1][y1] + hor[x1][y1];
		ans += ver[x2][y2-1] - ver[x1][y2-1] - ver[x2][y1] + ver[x1][y1];
		printf("%d\n", ans);
	}
	return 0;
}