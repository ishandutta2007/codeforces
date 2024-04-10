#include<bits/stdc++.h>

using namespace std;

const int MAXN = 50 + 10;

int n, m, k, g;
int comp[MAXN][MAXN], cnt[MAXN * MAXN], sec[MAXN * MAXN];
bool mark[MAXN * MAXN], del[MAXN * MAXN], vis[MAXN][MAXN];
string s[MAXN];

bool valid(int a, int b){return 0 <= a && a < n && 0 <= b && b < m && s[a][b] == '.';}
bool cmp(int a, int b){return cnt[a] < cnt[b];}

void dfs(int a, int b){
	if (vis[a][b])	return;
	vis[a][b] = 1;
	cnt[g]++;
	comp[a][b] = g;
	if (a == 0 || a == n - 1 || b == 0 || b == m - 1)	mark[g] = 1;
	for (int aa = -1; aa <= 1; aa++)
		for (int bb = -1; bb <= 1; bb++)
			if (abs(aa) + abs(bb) == 1 && valid(a + aa, b + bb))
				dfs(a + aa, b + bb);
}

int main(){
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!vis[i][j] && s[i][j] == '.')
				dfs(i, j), g++;
	iota(sec, sec + g, 0);
	sort(sec, sec + g, cmp);
	int tt = 0;
	for (int i = 0; i < g; i++)
		if (!mark[i])	tt++;
	int cur = 0;
	int sm = 0;
	while (tt > k){
		tt--;
		while (mark[sec[cur]])	cur++;
		sm += cnt[sec[cur]];
		del[sec[cur++]] = 1;
	}
	cout << sm << "\n";
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (s[i][j] == '.' && del[comp[i][j]])	s[i][j] = '*';
			cout << s[i][j];
		}
		cout << "\n";
	}
	return 0;
}