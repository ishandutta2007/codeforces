#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e3 + 10;

int n, m;
pii a, b;
string s[MAXN];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int d[4][MAXN][MAXN];
bool mark[4][MAXN][MAXN];
deque<pair<int, pii>> q;

bool valid(int x, int y){return 0 <= x && x < n && 0 <= y && y < m && s[x][y]!='*';}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> s[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == 'S')
				a = {i, j};
			else if (s[i][j] == 'T')
				b = {i, j};

	memset(d, 63, sizeof(d));
	int h = 0, t = 0;
	for (int w = 0; w < 4; w++){
		d[w][a.F][a.S] = 0;
		q.push_back({w, {a.F, a.S}});
	}
	while (q.size()){
		auto v = q.front().S; int dir = q.front().F; q.pop_front();
		if (mark[dir][v.F][v.S]) continue;
		mark[dir][v.F][v.S] = 1;

		for (int w = 0; w < 4; w++)
			if (valid(v.F+dx[w], v.S+dy[w]) && d[w][v.F+dx[w]][v.S+dy[w]] > d[dir][v.F][v.S] + int(w != dir)){
				int x = v.F+dx[w], y = v.S+dy[w];
				d[w][x][y] = d[dir][v.F][v.S] + int(w!=dir);
				if (dir == w)
					q.push_front({w, {x, y}});
				else
					q.push_back({w, {x, y}});
			}
	}
	int mn = 1e9;
	for (int w = 0; w < 4; w++)
		mn = min(mn, d[w][b.F][b.S]);
	if (mn <= 2)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}