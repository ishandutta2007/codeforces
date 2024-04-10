#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

#define X first.first
#define Y first.second
#define XX second.first
#define YY second.second

typedef long long ll;

const int MAX = 2e5 + 20;

char c[10][10];
bool mark[10][10][10][10];
pair<pair<int, int>, pair<int, int>>	q[MAX];

bool fit(int a, int b){return	a >= 0 && b >= 0 && a < 8 && b < 8;}

bool bfs(int x, int y, int xx, int yy){
	int h = 0, t = 0;
	for (int i = 0; i < 10; i++)
		for (int i1 = 0; i1 < 10; i1++)
			for (int i2 = 0; i2 < 10; i2++)
				for (int j = 0; j < 10; j++)
					mark[i][i1][i2][j] = 0;
	mark[x][y][xx][yy] = 1;
	q[t++] = {{x, y}, {xx, yy}};

	while (h < t){
		pair<pair<int, int>, pair<int, int>>	v = q[h++];
		for (int i = -1; i < 3; i += 2)
			for (int i1 = -1; i1 < 3; i1 += 2)
				for (int i2 = -1; i2 < 3; i2 += 2)
					for (int i3 = -1; i3 < 3; i3 += 2)
						if (fit(v.X + i * 2, v.Y + i1 * 2) && fit(v.XX + i2 * 2, v.YY + i3 * 2))
							if (!mark[v.X + i * 2][v.Y + i1 * 2][v.XX + i2 * 2][v.YY + i3 * 2]){
								mark[v.X + i * 2][v.Y + i1 * 2][v.XX + i2 * 2][v.YY + i3 * 2] = 1;
								q[t++] = {{v.X + i * 2, v.Y + i1 * 2}, {v.XX + i2 * 2, v.YY + i3 * 2}};
							}
					
	}

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (mark[i][j][i][j] && c[i][j] != '#')
				return	true;
	return	false;
}

int main(){
	int test;	cin >> test;
	while (test--){
		int x = -1, y, xx, yy;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++){
				cin >> c[i][j];
				if (c[i][j] == 'K'){
					if (x == -1)
						x = i, y = j;
					else
						xx = i, yy = j;
				}
			}
		if (bfs(x, y, xx, yy))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}