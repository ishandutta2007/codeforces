#include <cstdio>
#include <cstdlib>
#include <typeinfo>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 2000;
const int X = 1000, Y = 1000;
const int MAX = 1200, RANGE = 400;
const int DEBUG = 0;

int map[N][N];
int m;

bool inside(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

struct Position {
	int x, y;
	Position(int x, int y) : x(x), y(y) {}
	Position() {}
	void read() {
		scanf("%d %d", &x, &y);
		x += X;
		y += Y;
	}
	friend bool operator ==(const Position &a, const Position &b) {
		return a.x == b.x && a.y == b.y;
	}
	friend bool operator !=(const Position &a, const Position &b) {
		return !(a == b);
	}
	void show() {
		printf("(%d, %d)\n", x, y);
	}
	void run(char c) {
		int xx = x, yy = y;
		switch (c) {
			case 'U' : y++; break;
			case 'D' : y--; break;
			case 'L' : x--; break;
			case 'R' : x++; break;
		}
		if (inside(x, y) && map[x][y]) {
if (DEBUG) 	cout << "ouch" << endl;
			x = xx, y = yy;
		} else {
			assert(x != xx || y != yy);
		}
		//printf("(%d %d) -> (%d %d)\n", xx, yy, x, y);
	}
};

Position prince, shadow;
vector<Position> trees;
string answer;

int visit[N][N];
char dir[N][N];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char dc[4] = {'R', 'U', 'L', 'D'};

bool current() {
	return (m == 400 && trees[0].x == -31 + X && trees[0].y == 1 + Y);
}

void run(string s) {
	for (int i = 0; i < s.size(); i++) {
		prince.run(s[i]);
		shadow.run(s[i]);
	}
	answer += s;
}

string go(Position source, Position target) {
	static vector<Position> queue;
	queue.clear();
	queue.push_back(source);
	visit[source.x][source.y] = 1;
	for (int head = 0; head < (int)queue.size(); head++) {
		Position pos = queue[head];
		for (int d = 0; d < 4; d++) {
			int xx = pos.x + dx[d];
			int yy = pos.y + dy[d];
			if (inside(xx, yy) && !visit[xx][yy] && !map[xx][yy]) {
				visit[xx][yy] = 1;
				queue.push_back(Position(xx, yy));
				dir[xx][yy] = dc[d];
				if (Position(xx, yy) == target) break;
			}
		}
	}

	bool flag = visit[target.x][target.y];
	for (auto d : queue) {
		visit[d.x][d.y] = 0;
	}
	if (!flag) return "";

	Position cur = target;
	string ret = "";
	while (cur != source) {
		//cout << cur.x << " " << cur.y << " " << source.x << " " << source.y << " " << dir[cur.x][cur.y] << endl;
		ret += dir[cur.x][cur.y];
		switch (dir[cur.x][cur.y]) {
			case 'U' : cur.y--; break;
			case 'D' : cur.y++; break;
			case 'L' : cur.x++; break;
			case 'R' : cur.x--; break;
		}
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

void gofar() {
	// go far away
	if (prince.x < MAX - RANGE && shadow.x < MAX - RANGE) {
		for (int i = 0; prince.y < MAX + RANGE || shadow.y < MAX + RANGE; i++) run("U");
		for (int i = 0; prince.x < MAX + RANGE || shadow.x < MAX + RANGE; i++) run("R");
	} else if (prince.y < MAX - RANGE && shadow.y < MAX - RANGE) {
		for (int i = 0; prince.x < MAX + RANGE || shadow.x < MAX + RANGE; i++) run("R");
		for (int i = 0; prince.y < MAX + RANGE || shadow.y < MAX + RANGE; i++) run("U");
	} else {
		for (int i = 0; min(prince.x, shadow.x) < MAX + RANGE ||
						min(prince.y, shadow.y) < MAX + RANGE ; i++) run("R"), run("U");
	}
}

void solve() {
	string possible = go(prince, shadow);
	if (possible == "" || trees.size() == 0) {
		answer = "-1";
		return ;
	}

	string gout = go(prince, Position(MAX + RANGE, MAX + RANGE));
	if (gout != "") {
if (DEBUG) {
	cout << "go out" << endl;
}
		run(gout);
		assert(prince == Position(MAX + RANGE, MAX + RANGE));
		gout = go(shadow, Position(MAX + RANGE, MAX + RANGE));
		assert(gout != "");
		run(gout);
if (DEBUG) {
		cout << "prince (" << prince.x << ", " << prince.y << ")" << endl;
		cout << "shadow (" << shadow.x << ", " << shadow.y << ")" << endl;
}
		Position target;
		if (shadow.x < prince.x) {
			target = Position(-MAX, -MAX);
			for (auto t : trees) {
				if (t.x > target.x) target = t;
			}
			target.x++;
			gofar();

			while (shadow.y > target.y) run("D");
			while (shadow.x > target.x) run("L");
			assert(shadow == target);

			while (shadow.x < prince.x) run("L");
			for (int i = 0; i < MAX + RANGE; i++) run("R");
		} else if (prince.x < shadow.x) {
			target = Position(MAX, MAX);
			for (auto t : trees) {
				if (t.x < target.x) target = t;
			}
			target.x--;
			gofar();

			while (shadow.x > MAX - RANGE) run("L");
			while (shadow.y > target.y) run("D");
			while (shadow.x < target.x) run("R");
			assert(shadow == target);

			while (prince.x < shadow.x) run("R");
			for (int i = 0; i < MAX + RANGE; i++) run("L");
		}

		if (shadow.y < prince.y) {
			target = Position(-MAX, -MAX);
			for (auto t : trees) {
				if (t.y > target.y) target = t;
			}
			target.y++;
			gofar();

			while (shadow.x > target.x) run("L");
			while (shadow.y > target.y) run("D");
			assert(shadow == target);

			while (shadow.y < prince.y) run("D");
			for (int i = 0; i < MAX + RANGE; i++) run("U");
		} else if (prince.y < shadow.y) {
			target = Position(MAX, MAX);
			for (auto t : trees) {
				if (t.y < target.y) target = t;
			}
			target.y--;
			gofar();
			while (shadow.y > MAX - RANGE) run("D");
			while (shadow.x > target.x) run("L");
			while (shadow.y < target.y) run("U");
			assert(shadow == target);

			while (prince.y < shadow.y) run("U");
			for (int i = 0; i < MAX + RANGE; i++) run("D");
		}
		return ;
	}
if (DEBUG) {
	cout << "go loop" << endl;
}
	string s = go(prince, shadow);
	//if (m == 180) { cout << s << endl; exit(0); }
	for (int head = 0; head < s.size() && shadow != prince; head++) {
		Position tmp = shadow, t2 = prince;
		run(string("") + s[head]);
		if (shadow != tmp) s += s[head];
	}
	assert(shadow == prince);
	return ;
}


int main() {
	prince.read();
	shadow.read();
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		Position pos;
		pos.read();
		trees.push_back(pos);
		map[pos.x][pos.y] = 1;
	}
	assert(map[prince.x][prince.y] == 0);
	assert(map[shadow.x][shadow.y] == 0);
	solve();
	if (answer != "-1") assert(prince == shadow);
	cout << answer << endl;
	return 0;
}