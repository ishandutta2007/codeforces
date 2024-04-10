#include <iostream>
#include <string>
#include <stack>
#define debug(code)
using namespace std;

bool table[504][504];
bool visited[504][504];
int n, x, y;
string moves;

void readInput() {
	cin >> n >> x >> y;
	x--; y--; // 1-index to 0-index
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int k;
			cin >> k;
			table[i][j] = (k == 1);
		}
	}
}

bool seen(int dx, int dy) {
	int xx = x, yy = y;
	xx += dx;
	yy += dy;
	while (
			0 <= xx && xx < n &&
			0 <= yy && yy < n
			) {
		if (visited[xx][yy]) return false;
		if (table[xx][yy]) return true;
		xx += dx;
		yy += dy;
	}
	return false;
}

void ensureOn() {
	if (!table[x][y]) {
		table[x][y] = true;
		moves += '1';
	}
}
void ensureOff() {
	if (table[x][y]) {
		table[x][y] = false;
		moves += '2';
	}
}


// yay manual stackage
typedef struct st {
	int x;
	int y;
	int step;
	char post;
	st(int xx, int yy, int dd, char cc): x(xx), y(yy), step(dd), post(cc) {}
} st;
stack<st> stk;

void dfsd(char, int, int, char);
void dfs() {
	stk.push(st(x, y, 0, '\0'));
	while (!stk.empty()) {
		x = stk.top().x;
		y = stk.top().y;
		int d = stk.top().step++;
		switch (d) {
			case 0:
				visited[x][y] = true;
				ensureOn();
				debug( cout << "dfs" << x << "," << y << endl; )
				if (seen(0, 1))  dfsd('R', 0,  1, 'L');
				break;
			case 1:
				if (seen(0, -1)) dfsd('L', 0, -1, 'R');
				break;
			case 2:
				if (seen(1, 0))  dfsd('D', 1,  0, 'U');
				break;
			case 3:
				if (seen(-1, 0)) dfsd('U', -1,  0, 'D');
				break;
			case 4:
				ensureOff();
				char c = stk.top().post;
				if (c != '\0') {
					moves += c;
					debug( cout << "adding " << c << endl; )
				}
				stk.pop();
				break;
		}
	}
}

void dfsd(char pre, int dx, int dy, char post) {
	debug( cout << "adding " << pre << endl; )
	moves += pre;
	stk.push(st(x + dx, y + dy, 0, post));
}

int main() {
	readInput();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
	dfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (table[i][j]) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	cout << moves << endl;
}