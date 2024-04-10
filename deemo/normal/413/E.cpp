#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 2e5 + 100;
const int LOG = 20;

int n, q, par[2][MAXN], col[2][MAXN], g;
int nxt[LOG][2][MAXN];
bool vis[2][MAXN];
string s[2];

bool fit(int x, int y){return	x >= 0 && x < 2 && y >= 0 && y < n;}

void dfs(int x, int y){
	if (vis[x][y])	return;
	vis[x][y] = 1;
	col[x][y] = g;
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			if (fit(x + i, y + j) && abs(i) + abs(j) == 1 && s[x + i][y + j] != 'X')
				dfs(x + i, y + j);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	cin >> s[0] >> s[1];
	for (int j = 0; j < 2; j++)
		for (int i = 0; i < n; i++)
			par[j][i + 1] = par[j][i] + bool(s[j][i] == '.');

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++)
			if (!vis[j][i])	g++, dfs(j, i);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++){
			int cur = i;
			for (int w = LOG - 1; w >= 0; w--)
				if (cur + (1<<w) <= n && par[j][cur + (1<<w)] - par[j][cur] == (1<<w))	cur += (1<<w);
			nxt[0][j][i] = cur;
		}

	for (int w = 1; w < LOG; w++)
		for (int j = 0; j < 2; j++)
			for (int i = 0; i < n; i++)
				if (nxt[w - 1][j][i] >= n)
					nxt[w][j][i] = n;
				else{
					if (w == 1)
						nxt[w][j][i] = nxt[w - 1][1 - j][nxt[w - 1][j][i]];
					else
						nxt[w][j][i] = nxt[w - 1][j][nxt[w-1][j][i]];
				}

	for (int i = 0; i < q; i++){
		int a, b, aa = 0, bb = 0;	cin >> a >> b;	a--, b--;
		if (a == b){
			cout << "0\n";
			continue;
		}	

		if (a >= n)	aa = 1, a -= n;
		if (b >= n)	bb = 1, b -= n;

		if (col[aa][a] != col[bb][b]){
			cout << "-1\n";
			continue;
		}
	
		if (a == b){
			cout << "1\n";
			continue;
		}

		if (a > b)
			swap(a, b), swap(aa, bb);

		int ans = b - a, cnt = 0;
		int ta = aa;
		for (int w = LOG - 1; w >= 0; w--)
			if (nxt[w][aa][a] < b){
				//cout << w << "  " << aa << "  " << a << " " << nxt[w][aa][a] << "\n";
				cnt += (1<<w);
				a = nxt[w][aa][a];
				if (w == 0)
					aa = 1 - aa;
			}

		//cout << aa << " " << a << " " << bb << " " << b << " " << cnt << "\n";
		if (cnt % 2 != bool(ta != bb))	cnt++;
		cout << cnt + ans << "\n";
	}

	return	0;
}