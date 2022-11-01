#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cassert>
#include <vector>
#include <iostream>

const int N = 33;

int n, m;
int s[N][N], t[N][N];

struct Pos {
	int row, col;
	Pos(int row, int col) : row(row), col(col) {}
	Pos() {}
	void show() {
		printf("%d %d\n", row + 1, col + 1);
	}
	friend inline bool operator == (const auto &a, const auto &b) {
		return a.row == b.row && a.col == b.col;
	}
};

std::vector<Pos > answer;
Pos cursor;
bool locked[N][N];

Pos find(int color) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!locked[i][j] && s[i][j] == color && !(Pos(i, j) == cursor)) {
				return Pos(i, j);
			}
		}
	}
	return Pos(-1, -1);
}

void step(Pos p) {
	if (p == cursor) return ;
	answer.push_back(p);
	assert(std::max(std::abs(p.row - cursor.row), std::abs(p.col - cursor.col)) <= 1);
	std::swap(s[cursor.row][cursor.col], s[p.row][p.col]);
	cursor = p;
}

void run(Pos target) {
	while (cursor.col < target.col) step(Pos(cursor.row, cursor.col + 1));
	while (cursor.col > target.col) step(Pos(cursor.row, cursor.col - 1));
	while (cursor.row > target.row) step(Pos(cursor.row - 1, cursor.col));
	while (cursor.row < target.row) step(Pos(cursor.row + 1, cursor.col));
}

void colMove(Pos &where, Pos target) {
	assert(cursor == Pos(n - 2, m - 1));
	if (where.row == n - 1) {
		run(Pos(where.row - 1, where.col));
		while (where.col != target.col) {
			if (where.col > target.col) step(Pos(where.row, where.col - 1));
			if (where.col < target.col) step(Pos(where.row, where.col + 1));
			step(where);
			step(Pos(where.row - 1, where.col));
			if (where.col > target.col) where.col--; else where.col++;
			step(Pos(where.row - 1, where.col));
		}
	} else {
		if (where.row == cursor.row) run(Pos(n - 1, m - 1));
		run(Pos(where.row + 1, where.col));
		while (where.col != target.col) {
			if (where.col > target.col) step(Pos(where.row, where.col - 1));
			if (where.col < target.col) step(Pos(where.row, where.col + 1));
			step(where);
			step(Pos(where.row + 1, where.col));
			if (where.col > target.col) where.col--; else where.col++;
			step(Pos(where.row + 1, where.col));
		}
	}
}

void rowMove(Pos &where, Pos target) {
	if (where.row == target.row) return ;
	while (where.row > target.row) {
		if (where.col < m - 1) {
			step(Pos(where.row, where.col + 1));
		} else {
			step(Pos(where.row, where.col - 1));
		}
		Pos bak = cursor;
		step(Pos(where.row - 1, where.col));
		step(where);
		step(bak);
		where.row--;
	}
}

bool solve() {
	answer.clear();
	if (n == 1) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if (s[0][i] != t[0][j]) continue;
				std::vector<int > sv, tv;
				for (int k = 0; k < m; k++) {
					if (k != i) sv.push_back(s[0][k]);
					if (k != j) tv.push_back(t[0][k]);
				}
				if (sv == tv) {
					answer.push_back(cursor = Pos(0, i));
					if (i < j) {
						for (int k = i; k < j; k++) step(Pos(cursor.row, cursor.col + 1));
					} else {
						for (int k = i; k > j; k--) step(Pos(cursor.row, cursor.col - 1));
					}
					return true;
				}
			}
		}
		return false;
	} else if (m == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (s[i][0] != t[j][0]) continue;
				std::vector<int > sv, tv;
				for (int k = 0; k < n; k++) {
					if (k != i) sv.push_back(s[k][0]);
					if (k != j) tv.push_back(t[k][0]);
				}
				if (sv == tv) {
					answer.push_back(cursor = Pos(i, 0));
					if (i < j) {
						for (int k = i; k < j; k++) step(Pos(cursor.row + 1, cursor.col));
					} else {
						for (int k = i; k > j; k--) step(Pos(cursor.row - 1, cursor.col));;
					}
					return true;
				}
			}
		}
		return false;
	}

	cursor = Pos(-1, -1);
	answer.push_back(cursor = find(t[n - 2][m - 1]));
	if (cursor == Pos(-1, -1)) return false;
	run(Pos(n - 2, m - 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == n - 2 && j == m - 1) continue;
			Pos where = find(t[i][j]);
			if (where == Pos(-1, -1)) return false;
			assert(!(where == cursor));
			// printf("i = %d j = %d\n", i, j);
			//
			// printf("cursor = %d %d\n", cursor.row, cursor.col);
			// for (int i = 0; i < n; i++, puts(""))
			// 	for (int j = 0; j < m; j++) {
			// 		printf("%d ", s[i][j]);
			// 	}
			// puts("");
			colMove(where, Pos(where.row, j));
			//
			// printf("cursor = %d %d\n", cursor.row, cursor.col);
			// for (int i = 0; i < n; i++, puts(""))
			// 	for (int j = 0; j < m; j++) {
			// 		printf("%d ", s[i][j]);
			// 	}
			// puts("");
			rowMove(where, Pos(i, j));
			run(Pos(n - 2, m - 1));
			// printf("cursor = %d %d\n", cursor.row, cursor.col);
			// for (int i = 0; i < n; i++, puts(""))
			// 	for (int j = 0; j < m; j++) {
			// 		printf("%d ", s[i][j]);
			// 	}
			// puts("");
			locked[i][j] = true;
			assert(s[i][j] == t[i][j]);
		}
	}
	return true;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &s[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &t[i][j]);
		}
	}

	if (!solve()) {
		puts("-1");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			assert(s[i][j] == t[i][j]);
		}
	}
	printf("%d\n", answer.size() - 1);
	for (int i = 0; i < answer.size(); i++) {
		answer[i].show();
	}
	return 0;
}