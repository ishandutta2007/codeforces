#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <set>
using namespace std;

int n = 6;

const int UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3;
set<vector<vector<int> > > HASH;
vector<vector<int> > mat, table;
vector<pair<int, int> > answer;

void go(int p, int dir, int times = 1) {
	p %= n;
	vector<vector<int> > ret = mat;
	if (dir == UP || dir == DOWN) {
		int delta = (dir == UP) ? times : -times;
		delta %= n;
		for (int i = 0; i < n; i++) {
			ret[i][p] = mat[(i + delta + n) % n][p];
		}
	} else {
		int delta = (dir == LEFT) ? times : -times;
		delta %= n;
		for (int i = 0; i < n; i++) {
			ret[p][i] = mat[p][(i + delta + n) % n];
		}
	}
	for (int t = 0; t < times; t++) {
		answer.push_back(make_pair(p, dir));
	}
	mat = ret;
}


void move2(int i, int j) {
//	cout << "move2 " << i << " " << j << endl;
	go(j + 2, DOWN);
	go(i + 0, RIGHT);
	go(j + 2, UP);
	go(i + 0, RIGHT);
	go(j + 2, DOWN);
	go(i + 0, LEFT, 2);
	go(j + 2, UP);
}

void show(vector<vector<int> > mat) {
	for (int i = 0; i < 6; i++, puts(""))
		for (int j = 0; j < 6; j++) {
			printf("%d ", mat[i][j]);
		}
	puts("");
}

int main() {
	for (int i = 0, tot = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < n; j++) {
			v.push_back(tot++);
		}
		table.push_back(v);
	}
	for (int i = 0; i < n; i++) {
		static char buffer[1024];
		scanf("%s", buffer);
		vector<int> v;
		for (int j = 0; j < n; j++) {
			int id;
			if ('0' <= buffer[j] && buffer[j] <= '9') {
				id = buffer[j] - '0';
			} else {
				id = buffer[j] - 'A' + 10;
			}
			v.push_back(id);
		}
		mat.push_back(v);
	}

	for (int i = 0; i + 1 < n; i++) {
		for (int j = 0; j < n; j++) {
			int row = -1, col = -1;
			for (int k = 0; k < n && row == -1; k++) {
				for (int l = 0; l < n && col == -1; l++) {
					if (mat[k][l] == table[i][j]) {
						row = k;
						col = l;
					}
				}
			}
			if (row == i) {
				go(col, DOWN);
				row++;
				go(row, RIGHT);
				go(col, UP);
				col = (col + 1) % n;
			}
			if (col == j) {
				go(row, RIGHT);
				col = (col + 1) % n;
			}
			go(j, DOWN, (row - i));
			if (col > j) go(row, LEFT, col - j);
			if (col < j) go(row, RIGHT, j - col);
			go(j, UP, (row - i));
		}
	}
	//show(mat);
	for (int i = n - 1; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (table[i][0] == mat[i][k]) go(i, LEFT, k);
		}
		for (int j = 1; j < n; j++) {
			if (table[i][j] == mat[i][j]) continue;
			int col = -1;
			for (int k = 0; k < n; k++) {
				if (table[i][j] == mat[i][k]) col = k;
			}
			while (table[i][j] != mat[i][j]) {
			//	cout << "pre " << endl;
			//	show(mat);
				move2(i, col);
				(col += 2) %= n;
				if (col < 2) {
					go(i, RIGHT);
					col++;
				}
			//	show(mat);
			}
			//puts("---------");
		}
	}
	printf("%d\n", answer.size());
	for (auto d : answer) {
		switch (d.second) {
			case UP : printf("U"); break;
			case DOWN : printf("D"); break;
			case LEFT : printf("L"); break;
			case RIGHT : printf("R"); break;
		}
		printf("%d\n", d.first + 1);
	}
}