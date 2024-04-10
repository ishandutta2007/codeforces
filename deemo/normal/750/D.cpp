#include<bits/stdc++.h>

using namespace std;

const int MAXN = 300 + 30;

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
bool mark[8][MAXN][MAXN], _mark[8][MAXN][MAXN], vis[MAXN][MAXN];
int pt[8][MAXN][MAXN];

int add(int x, int y){
	x += y;
	if (x >= 8)	x -= 8;
	if (x < 0)	x += 8;
	return x;
}

bool fit(int x, int y){return 0<=x && x < MAXN && 0 <= y && y < MAXN;}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	mark[0][160][160] = 1;
	vis[160][160] = 1;
	bool fl = 0;
	while (n--){
		int t;	cin >> t;
		if (!fl)	t--;
		for (int dir = 0; dir < 8; dir++)
			for (int i = 0; i < MAXN; i++)
				for (int j = 0; j < MAXN; j++)
					if (mark[dir][i][j]){
						pt[dir][i+dx[dir]*t][j+dy[dir]*t]++, pt[dir][i-dx[dir]][j-dy[dir]]--;
						_mark[add(dir, 1)][i+dx[dir]*t][j+dy[dir]*t] = 1;
						_mark[add(dir, -1)][i+dx[dir]*t][j+dy[dir]*t] = 1;
					}

		for (int i = MAXN - 1; ~i; i--)
			for (int j = MAXN - 1; ~j; j--){
				int dir = 0;
				if (fit(i+dx[dir], j+dy[dir]))
					pt[dir][i][j] += pt[dir][i+dx[dir]][j+dy[dir]];
			}

		for (int i = MAXN - 1; ~i; i--)
			for (int j = MAXN - 1; ~j; j--){
				int dir = 1;
				if (fit(i+dx[dir], j+dy[dir]))
					pt[dir][i][j] += pt[dir][i+dx[dir]][j+dy[dir]];
			}

		for (int i = MAXN - 1; ~i; i--)
			for (int j = MAXN - 1; ~j; j--){
				int dir = 2;
				if (fit(i+dx[dir], j+dy[dir]))
					pt[dir][i][j] += pt[dir][i+dx[dir]][j+dy[dir]];
			}

		for (int i = 0; i < MAXN; i++)
			for (int j = MAXN - 1; ~j; j--){
				int dir = 3;
				if (fit(i+dx[dir], j+dy[dir]))
					pt[dir][i][j] += pt[dir][i+dx[dir]][j+dy[dir]];
			}

		for (int i = 0; i < MAXN; i++)
			for (int j = MAXN - 1; ~j; j--){
				int dir = 4;
				if (fit(i+dx[dir], j+dy[dir]))
					pt[dir][i][j] += pt[dir][i+dx[dir]][j+dy[dir]];
			}
		
		for (int i = 0; i < MAXN; i++)
			for (int j = 0; j < MAXN; j++){
				int dir = 5;
				if (fit(i+dx[dir], j+dy[dir]))
					pt[dir][i][j] += pt[dir][i+dx[dir]][j+dy[dir]];
			}

		for (int i = 0; i < MAXN; i++)
			for (int j = 0; j < MAXN; j++){
				int dir = 6;
				if (fit(i+dx[dir], j+dy[dir]))
					pt[dir][i][j] += pt[dir][i+dx[dir]][j+dy[dir]];
			}

		for (int i = MAXN-1; ~i; i--)
			for (int j = 0; j < MAXN; j++){
				int dir = 7;
				if (fit(i+dx[dir], j+dy[dir]))
					pt[dir][i][j] += pt[dir][i+dx[dir]][j+dy[dir]];
			}

		for (int dir = 0; dir < 8; dir++)
			for (int i = 0; i < MAXN; i++)
				for (int j = 0; j < MAXN; j++)
					vis[i][j] |= bool(pt[dir][i][j]);

		memset(pt, 0, sizeof(pt));
		memcpy(mark, _mark, sizeof(_mark));
		memset(_mark, 0, sizeof(_mark));
		fl = 1;
	}

	int ans = 0;
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			ans += vis[i][j];
	cout << ans << "\n";
	return 0;
}