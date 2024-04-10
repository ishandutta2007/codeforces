#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
ostream& operator<<(ostream& o, const vector<int>& v) {
	o << '[';
	for(size_t i = 0; i < v.size(); ++i) {
		if(i) o << " ";
		o << v[i];
	}
	o << ']';
	return o;
}

ostream& operator<<(ostream& o, const vector<ll>& v) {
	o << '[';
	for(size_t i = 0; i < v.size(); ++i) {
		if(i) o << " ";
		o << v[i];
	}
	o << ']';
	return o;
}

#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

const int N = 1005;
int board[N][N] = {0};

int n;

bool ok(int a, int b) {
	return a >= 1 && a <= n && b >= 1 && b <= n;
}

int main() {
	fio;
	int a, b, c, d, e, f;
	cin >> n >> a >> b >> c >> d >> e >> f;
	vector<int> dx = {1, 1, 0, -1, -1, -1, 0, 1};
	vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};
	for(int i = 0; i < 8; ++i) {
		int x = a, y = b;
		while(ok(x, y)) {
			board[x][y] = 1;
			x += dx[i];
			y += dy[i];
		}
	}
	queue<pair<int, int>> Q;
	Q.emplace(c, d);
	pii p(e, f);
	while(!Q.empty()) {
		auto x = Q.front();
		Q.pop();
		if(x == p) {
			cout << "YES\n";
			return 0;
		}
		for(int i = 0; i < 8; ++i) {
			pii t = x;
			t.first += dx[i];
			t.second += dy[i];
			if(!ok(t.first, t.second)) continue;
			if(board[t.first][t.second] != 0) continue;
			board[t.first][t.second] = 1;
			Q.push(t);
		}
	}
	cout << "NO\n";
}