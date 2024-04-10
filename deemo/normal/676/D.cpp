#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cassert>
#include<cstring>
#include<utility>

using namespace std;

#define F first
#define S second

const int MAXN = 1e3 + 10;

int n, m, d[4][MAXN][MAXN];
string s[4][MAXN];
pair<int, pair<int, int>>	q[MAXN * MAXN * 4];

bool fit(int a, int b){return 0 <= a && a < n && 0 <= b && b < m && s[0][a][b] != '*';}

char rot(char c, int t){
	while (t--){
		if (c == '-')	c = '|';
		else if (c == '|')	c = '-';
		else if (c == '^')	c = '>';
		else if (c == '>')	c = 'v';
		else if (c == 'v')	c = '<';
		else if (c == '<')	c = '^';
		else if (c == 'L')	c = 'U';
		else if (c == 'U')	c = 'R';
		else if (c == 'R')	c = 'D';
		else if (c == 'D')	c = 'L';
	}
	return c;
}

bool open(char c, int v){//0 -> U
	if (v == 0)//U
		return c == '+' || c == '|' || c == '^' || c == 'D' || c == 'L' || c == 'R';
	if (v == 1)//R
		return c == '+' || c == '-' || c == '>' || c == 'D' || c == 'L' || c == 'U';
	if (v == 2)//D
		return c == '+' || c == '|' || c == 'v' || c == 'L' || c == 'U' || c == 'R';
	if (v == 3)//L
		return c == '+' || c == '-' || c == '<' || c == 'U' || c == 'R' || c == 'D';
	assert(0);
}

int go(int a, int b, int aa, int bb){
	memset(d, 63, sizeof(d));
	d[0][a][b] = 0;
	int h = 0, t = 0, w;
	q[t++] = {0, {a, b}};
	
	while (h < t){
		w = q[h].F, a = q[h].S.F, b = q[h].S.S;
		h++;
		if (d[(w + 1) % 4][a][b] > d[w][a][b] + 1)
			d[(w + 1) % 4][a][b] = d[w][a][b] + 1, q[t++] = {(w + 1) % 4, {a, b}};
		if (fit(a - 1, b) && open(s[w][a][b], 0) && open(s[w][a - 1][b], 2) && d[w][a][b] + 1 < d[w][a - 1][b])
			d[w][a - 1][b] = d[w][a][b] + 1, q[t++] = {w, {a - 1, b}};
		if (fit(a, b + 1) && open(s[w][a][b], 1) && open(s[w][a][b + 1], 3) && d[w][a][b] + 1 < d[w][a][b + 1])
			d[w][a][b + 1] = d[w][a][b] + 1, q[t++] = {w, {a, b + 1}};
		if (fit(a + 1, b) && open(s[w][a][b], 2) && open(s[w][a + 1][b], 0) && d[w][a][b] + 1 < d[w][a + 1][b])
			d[w][a + 1][b] = d[w][a][b] + 1, q[t++] = {w, {a + 1, b}};
		if (fit(a, b - 1) && open(s[w][a][b], 3) && open(s[w][a][b - 1], 1) && d[w][a][b] + 1 < d[w][a][b - 1])
			d[w][a][b - 1] = d[w][a][b] + 1, q[t++] = {w, {a, b - 1}};
	}

	int ret = 1e9;
	for (int w = 0; w < 4; w++)
		ret = min(ret, d[w][aa][bb]);
	return (ret > 1e8?-1:ret);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> s[0][i];
		for (int w = 1; w < 4; w++){
			s[w][i].resize(m);
			for (int j = 0; j < m; j++)
				s[w][i][j] = rot(s[0][i][j], w);
		}
	}

	int x1, y1, x2, y2;	cin >> x1 >> y1 >> x2 >> y2, x1--, y1--, x2--, y2--;
	cout << go(x1, y1, x2, y2) << "\n";
	return 0;
}