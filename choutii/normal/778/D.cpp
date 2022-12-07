#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;
typedef vector<int> VI;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}

int read() {
	int x = 0, f = 1;char ch;
	for (ch = getchar(); !isdigit(ch); ch = getchar())
		if (ch == '-') f = -1;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 55;
int n, m; char s[MaxN][MaxN];

vector<pii> ans, res;

void dfs2(int x, int y);
void dfs1(int x, int y) {
	if(s[x][y] == 'U')
		return;
	dfs2(x + 1, y);
	ans.pb(mp(x, y));
	s[x][y] = s[x][y + 1] = 'U';
	s[x + 1][y] = s[x + 1][y + 1] = 'D';	
}

void dfs2(int x, int y) {
	if(s[x][y] == 'L')
		return;
	dfs1(x, y + 1);
	ans.pb(mp(x, y));
	s[x][y] = s[x + 1][y] = 'L';
	s[x][y + 1] = s[x + 1][y + 1] = 'R';
}

int main() {
	n = read(); m = read();
	for (int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	if(n & 1)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j += 2)
				dfs2(i, j);
	else 
		for (int j = 1; j <= m; j++)
			for (int i = 1; i <= n; i += 2)
				dfs1(i, j);
	for (auto x : ans) res.pb(x);
	ans.clear();
	
	for (int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	if(n & 1)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j += 2)
				dfs2(i, j);
	else 
		for (int j = 1; j <= m; j++)
			for (int i = 1; i <= n; i += 2)
				dfs1(i, j);
	reverse(ALL(ans));
	for (auto x : ans) res.pb(x);
	printf("%d\n", SZ(res));
	for (auto x : res)
		printf("%d %d\n", x.fi, x.se);
	return 0;
}