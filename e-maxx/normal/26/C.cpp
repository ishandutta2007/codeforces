#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;


const int dxy[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

void no() {
	puts ("IMPOSSIBLE");
	exit (0);
}

int n, m;
set<char> u;
bool u2[200][200];

void dfs (int x, int y, vector < vector<int> > & v, vector<string> & s) {
	u2[x][y] = true;
	for (int i=0; i<4; ++i) {
		int nx = x + dxy[i][0],
			ny = y + dxy[i][1];
		if (nx>=0 && nx<n && ny>=0 && ny<m)
			if (v[nx][ny] == v[x][y] && !u2[nx][ny])
				dfs (nx, ny, v, s);
			else if (s[nx][ny] != '.')
				u.erase (s[nx][ny]);
	}
}

void dfs2 (int x, int y, vector < vector<int> > & v, char ch, vector<string> & s) {
	if (s[x][y] != '.')  return;
	s[x][y] = ch;
	for (int i=0; i<4; ++i) {
		int nx = x + dxy[i][0],
			ny = y + dxy[i][1];
		if (nx>=0 && nx<n && ny>=0 && ny<m)
			if (v[nx][ny] == v[x][y])
				dfs2 (nx, ny, v, ch, s);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	int n, m, a, b, c;
	cin >> n >> m >> a >> b >> c;
	int nn=n,  mm=m;

	if (n * m % 2)
		no();
	if (n % 2) {
		--n;
		a -= m/2;
	}
	if (m % 2) {
		--m;
		b -= n/2;
	}
	if (a < 0 || b < 0)
		no();
	
	int bc = a/2 + b/2 + c;
	if (bc * 4 < n * m)
		no();

	vector < vector<int> > v (nn, vector<int> (mm, -1));
	int idx = 0;

	if (n < nn)
		for (int i=0; i<mm; i+=2)
			v[nn-1][i] = v[nn-1][i+1] = idx++;
	if (m < mm)
		for (int i=0; i<nn; i+=2)
			v[i][mm-1] = v[i+1][mm-1] = idx++;

	for (int i=0; i<n; ++++i)
		for (int j=0; j<m; ++++j) {
			if (c)
				--c,  v[i][j] = v[i][j+1] = v[i+1][j] = v[i+1][j+1] = idx++;
			else if (b >= 2)
				b -= 2,  v[i][j] = v[i+1][j] = idx++,  v[i][j+1] = v[i+1][j+1] = idx++;
			else if (a >= 2)
				a -= 2,  v[i][j] = v[i][j+1] = idx++,  v[i+1][j] = v[i+1][j+1] = idx++;
		}

	::n = nn, ::m = mm;
	vector<string> s (nn, string (mm, '.'));
	for (int i=0; i<nn; ++i)
		for (int j=0; j<mm; ++j) {
			if (s[i][j] != '.')  continue;
			int idx = v[i][j];

			for (char ch='a'; ch<='z'; ++ch)
				u.insert (ch);
			dfs (i, j, v, s);

			dfs2 (i, j, v, *u.begin(), s);
		}
	for (int i=0; i<nn; ++i)
		cout << s[i] << endl;

}