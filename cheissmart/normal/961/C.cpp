#include <iostream>

#define oo 2147483647

using namespace std;

int main()
{
	int n, cb[4][105][105], p[24][4] = {
		{0,1,2,3},{1,0,2,3},{2,0,1,3},{0,2,1,3},
		{1,2,0,3},{2,1,0,3},{2,1,3,0},{1,2,3,0},
		{3,2,1,0},{2,3,1,0},{1,3,2,0},{3,1,2,0},
		{3,0,2,1},{0,3,2,1},{2,3,0,1},{3,2,0,1},
		{0,2,3,1},{2,0,3,1},{1,0,3,2},{0,1,3,2},
		{3,1,0,2},{1,3,0,2},{0,3,1,2},{3,0,1,2}
	};

	cin >> n;
	for(int i=0;i<4;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++) {
				char c;
				cin >> c;
				cb[i][j][k] = c - '0';
			}
	int ans = oo;
	for(int i=0;i<24;i++) {
		for(int j=0;j<2;j++) {
			int d = 0;
			bool cur = j;
			for(int k=0;k<2*n;k++, cur=!cur)
				for(int l=0;l<2*n;l++) {
					int x = k, y = l, z = 0;
					if(k >= n) {
						x -= n;
						z += 2;
					}
					if(l >= n) {
						y -= n;
						z += 1;
					}
					if(cb[p[i][z]][x][y]!=cur) d++;
					cur = !cur;
				}
			ans = min(d, ans);
		}
	}
	cout << ans << endl;
}