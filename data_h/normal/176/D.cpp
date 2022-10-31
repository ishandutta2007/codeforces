#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <cassert>
#include <set>
#include <cstring>
using namespace std;

const int MAXN = 2005;

string words[MAXN];
set<int> p[MAXN][26];
char str[MAXN];
int n, m, seq[MAXN], len, ast[MAXN][26];
pair<int, int> f[MAXN][MAXN];
pair<int, int> inf, last[26], next[MAXN][26];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	memset(ast, -1, sizeof(ast));
	for(int i = 1; i <= n; i++) {
		cin >> words[i];
		for(int j = 0; j < words[i].size(); j++) {
			int idx = words[i][j] - 'a';
			p[i][idx].insert(j);
			if (ast[i][idx] == -1)
				ast[i][idx] = j;
		}
	}
	cin >> m;
	for(int i = 1; i <= m; i++) {
		cin >> seq[i];
	}
	inf.first = m + 1;
	for(int i = 0; i < 26; i++)
		last[i] = inf;
	for(int i = m; i >= 1; i--) {
		int x = seq[i];
		for(int j = 0; j < 26; j++)
			next[i][j] = last[j];
		for(int j = 0; j < 26; j++)
			if (ast[x][j] != -1)
				last[j] = make_pair(i, ast[x][j]);
	}
	cin >> str + 1;
	len = strlen(str + 1);
	for(int i = 0; i <= len; i++)
		for(int j = 0; j <= len; j++)
			f[i][j] = inf;
	f[0][0] = make_pair(1, -1);
	set<int> :: iterator it;
	for(int i = 0; i < len; i++)
		for(int j = 0; j <= i; j++)
			if (f[i][j].first <= m) {
				f[i + 1][j] = min(f[i + 1][j], f[i][j]);
				int idx = str[i + 1] - 'a';
				int a = f[i][j].first, b = f[i][j].second;
				it = p[seq[a]][idx].upper_bound(b);
				if (it != p[seq[a]][idx].end()) {
					int x = *it;
					f[i + 1][j + 1] = min(f[i + 1][j + 1], make_pair(a, *it));
				} else {
					if (next[a][idx].first > m)
						continue;
					b = next[a][idx].second; a = next[a][idx].first; 
					f[i + 1][j + 1] = min(f[i + 1][j + 1], make_pair(a, b));
				}
			}
	int ans = 0;
	for(int i = 1; i <= len; i++)
		for(int j = 1; j <= i; j++)
			if (f[i][j].first <= m)
				ans = max(ans, j);
/*
	for(int i = 1; i <= len; i++)
		for(int j = 1; j <= i; j++)
			if (f[i][j].first <= m) {
				cout << "(" << i << ", " << j << ") = " << "( " << f[i][j].first << ", " << f[i][j].second << ")" << endl;
			}
*/
	cout << ans << endl;
	return 0;
}