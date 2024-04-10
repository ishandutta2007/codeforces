#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cassert>
#include<utility>

using namespace std;

const int MAXN = 35 + 2;
const int MAX = 1e3 + 2;

int n, m, in[MAXN][MAXN], out[MAXN][MAXN], sec[MAXN][MAXN], cnt[2][MAX];
int x = -1, y;
vector<pair<int, int>>	ans;
string moves;
bool mark[MAXN][MAXN];

bool same(bool sc = 0){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (sc && sec[i][j] != out[i][j])
				return	false;
			else
				if (!sc && in[i][j] != out[i][j])
					return	false;
	return	true;
}

pair<int, int>	find(int xx, int yy){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!mark[i][j] && (i != x || j != y) && in[i][j] == out[xx][yy])
				return	make_pair(i, j);
	//assert(0);
	return	{-1, -1};//it won't get here ;-)
}

void move_it(char dir){
	if (dir == 'L')	swap(in[x][y], in[x][y - 1]), ans.push_back({x, --y});
	if (dir == 'R')	swap(in[x][y], in[x][y + 1]), ans.push_back({x, ++y});
	if (dir == 'U')	swap(in[x][y], in[x - 1][y]), ans.push_back({--x, y});
	if (dir == 'D')	swap(in[x][y], in[x + 1][y]), ans.push_back({++x, y});
	if (dir == 'Q')	swap(in[x][y], in[x + 1][y - 1]), ans.push_back({++x, --y});
	if (dir == 'Z')	swap(in[x][y], in[x - 1][y + 1]), ans.push_back({--x, ++y});
}

void fix(int xx, int yy, bool fl = 0){
	int cur = 0;
	while ((x == xx && y == yy) || in[xx][yy] != out[xx][yy]){
		move_it(moves[cur]);
		cur = (cur + 1) % (int)moves.size();
	}
	
	if (!fl){
		if (yy != m - 1)	yy++;
		else	xx++, yy = 0;

		while (y > yy)	move_it('L');
		while (y < yy)	move_it('R');
		while (x > xx)	move_it('U');
	}
	else{
		if (xx != n - 1)	xx++;
		else	xx--, yy++;

		while (x < xx)	move_it('D');
		while (x > xx)	move_it('U');
		while (y > yy)	move_it('L');
	}
}

int main(){
	//input
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &in[i][j]), cnt[0][in[i][j]]++;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &out[i][j]), cnt[1][out[i][j]]++;

	//checking the obvious case
	for (int i = 0; i < MAX; i++)
		if (cnt[0][i] != cnt[1][i]){
			printf("-1\n");
			return	0;
		}

	//the case when n == 1 or m == 1
	if (n == 1 || m == 1){
		bool changed = 0;
		if (m == 1){
			for (int i = 0; i < n; i++)
				in[0][i] = in[i][0], out[0][i] = out[i][0];
			changed = 1;
			swap(n, m);
		}
		
		for (int touch = 0; touch < m; touch++){
			for (int j = 0; j < m; j++)	sec[0][j] = in[0][j];
			for (int cur = touch + 1; cur < m; cur++){
				swap(sec[0][cur], sec[0][cur - 1]);
				if (same(1)){
					printf("%d\n", cur - touch);
					for (int w = touch; w <= cur; w++)
						if (!changed)
							printf("%d %d\n", 1, w + 1);
						else
							printf("%d %d\n", w + 1, 1);
					return	0;	
				}
			}
		}

		for (int touch = 0; touch < m; touch++){
			for (int j = 0; j < m; j++)	sec[0][j] = in[0][j];
			for (int cur = touch - 1; cur >= 0; cur--){
				swap(sec[0][cur], sec[0][cur + 1]);
				if (same(1)){
					printf("%d\n", touch - cur);
					for (int w = touch; w >= cur; w--)
						if (!changed)
							printf("%d %d\n", 1, w + 1);
						else
							printf("%d %d\n", w + 1, 1);
					return	0;	
				}
			}
		}
		printf("-1\n");
		return	0;
	}

	for (int i = 0; x == -1 && i < n; i++)
		for (int j = 0; x == -1 && j < m; j++)
			if (out[n - 1][m - 1] == in[i][j])
				x = i, y = j;
	ans.push_back({x, y});
	//moving x and y to (1, 1)
	while (x)
		move_it('U');
	while (y)
		move_it('L');

	//the first n - 2 rows
	for (int i = 0; i < n - 2; i++)
		for (int j = 0; j < m; j++){
			pair<int, int>	target = find(i, j);
			moves = "";
			if (target.second > y){
				int a = y + 1, b = x + 1;
				moves += "R";
				for (; a < target.second; a++)	moves += "R";
				moves += "D";
				for (; b < target.first; b++)	moves += "D";
				for (; a > y; a--)	moves += "L";
				for (; b > x; b--)	moves += "U";
			}
			else if (j){//here comes the trickier part!
				moves += "Q";//down-left
				int a = y - 1, b = x + 2;
				for (; a > target.second; a--)		moves += "L";
				moves += "D";
				for (; b < target.first; b++)	moves += "D";
				for (; a < y; a++)	moves += "R";
				for (; b > x; b--)	moves += "U";
			}
			else{
				int a = y + 1, b = x + 1;
				moves += "R";
				for (;a < target.second; a++)	moves += "R";
				moves += "D";
				for (; b < target.first; b++)	moves += "D";
				for (; a > y; a--)	moves += "L";
				for (; b > x; b--)	moves += "U";
			}
			fix(i, j);
			mark[i][j] = 1;
		}
	//if (n > 6)
	//	return	0;

	//the last two rows
	for (int j = 0; j < m - 1; j++)
		for (int i = n - 2; i < n; i++){
			pair<int, int>	target = find(i, j);
			moves = "";
			if (i == n - 2){
				moves += "R";
				int a = y + 1;
				for (; a < target.second; a++)	moves += "R";
				moves += "D";
				for (; a > y; a--)	moves += "L";
				moves += "U";
			}
			else{
				moves += "Z";//up-right
				int a = j + 1;
				for (; a < target.second; a++)	moves += "R";
				moves += "D";
				for (; a > j; a--)	moves += "L";
			}
			fix(i, j, 1);
			mark[i][j] = 1;
		}
	ans.push_back({n - 1, m - 1});
//*/
	printf("%d\n", (int)ans.size() - 1);
	for (pair<int, int>	ret:ans)
		printf("%d %d\n", ret.first + 1, ret.second + 1);
	return	0;
}