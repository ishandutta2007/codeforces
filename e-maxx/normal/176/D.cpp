#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


typedef long long int64;
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double PI = acos(0.0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define mp  make_pair
#define pb  push_back


const int MAXN = 2100;


char buf[1100000];
int n;
string a[MAXN];
int m, b[MAXN];
string s;


bool read() {
	if (! (cin >> n))
		return false;
	forn(i,n) {
		scanf (" %s", buf);
		a[i] = buf;
	}
	cin >> m;
	forn(i,m) {
		scanf ("%d", &b[i]);
		--b[i];
	}
	scanf (" %s", buf);
	s = buf;
	return true;
}


pair<int,int> d[MAXN][MAXN];
vector<int> next[MAXN][26];
pair<int,int> next2[MAXN][26];


inline pair<int,int> find_next (int idx, int pos, char c) {
	c -= 'a';

	if (pos < a[b[idx]].length()) {
		int there = next[b[idx]][c][pos];
		if (there != INF)
			return mp (idx, there);
	}

	if (idx == m-1)
		return mp(INF,INF);

	return next2[idx+1][c];
}


void solve() {
	forn(i,n) {
		forn(c,26)
			next[i][c].assign (a[i].length()+1, INF);
		ford(j,a[i].length()) {
			forn(c,26)
				next[i][c][j] = next[i][c][j+1];
			char curc = a[i][j] - 'a';
			next[i][curc][j] = j;
		}
	}

	forn(c,26)
		next2[m][c] = mp(INF,INF);
	ford(i,m) {
		int id = b[i];
		forn(c,26) {
			next2[i][c] = next2[i+1][c];
			if (next[id][c][0] != INF)
				next2[i][c] = mp (i, next[id][c][0]);
		}
	}


	forn(i,MAXN)
		forn(j,MAXN)
			d[i][j] = mp(INF,INF);
	d[0][0] = mp(0,0);

	forn(i,s.length())
		forn(j,s.length()+1) {
			pair<int,int> my = d[i][j];
			if (my == mp(INF,INF))  continue;

			d[i+1][j] = min (d[i+1][j], my);

			pair<int,int> nd = find_next (my.fs, my.sc, s[i]);
			++nd.sc;
			d[i+1][j+1] = min (d[i+1][j+1], nd);
		}

	int ans = 0;
	forn(i,s.length()+1)
		if (d[s.length()][i] != mp(INF,INF))
			ans = i;
	cout << ans << endl;
}


int main() {
#ifdef SU2_PROJ
	cerr << "D" << endl;
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	while (read())
		solve();

}