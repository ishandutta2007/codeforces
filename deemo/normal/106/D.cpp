#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAXN = 1e3 + 10;
const int MAXQ = 1e5 + 10;

int n, m, q, p[MAXN][MAXN], t[MAXQ];
char dir[MAXQ];
string s[MAXN], ans;

bool fit(int a, int b){return 0 <= a && a < n && 0 <= b && b < m;}

bool not_empty(int a, int b, int c, int d){
	if (a > c)	return p[a + 1][b + 1] - p[c][b + 1] - p[a + 1][b] + p[c][b];
	if (c > a)	return p[c + 1][b + 1] - p[a][b + 1] - p[c + 1][b] + p[a][b];
	if (b > d)	return p[a + 1][b + 1] - p[a + 1][d] - p[a][b + 1] + p[a][d];
	return p[a + 1][d + 1] - p[a + 1][b] - p[a][d + 1] + p[a][b];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> s[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)	p[i + 1][j + 1] = p[i + 1][j] + p[i][j + 1] - p[i][j] + (int)(s[i][j] == '#');
	cin >> q;
	for (int i = 0; i < q; i++)	cin >> dir[i] >> t[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] != '#' && s[i][j] != '.'){
				int x = i, y = j;
				bool fail = 0;
				for (int w = 0; w < q; w++){
					int tx = x, ty = y;
					if (dir[w] == 'N')	tx -= t[w];
					if (dir[w] == 'S')	tx += t[w];
					if (dir[w] == 'E')	ty += t[w];
					if (dir[w] == 'W')	ty -= t[w];
					if (!fit(tx, ty) || not_empty(x, y, tx, ty)){
						fail = 1;
						break;
					}
					x = tx, y = ty;
				}
				if (!fail)
					ans += s[i][j];
			}

	sort(ans.begin(), ans.end());
	if (ans.empty())
		cout << "no solution\n";
	else
		cout << ans << "\n";
	return	0;	
}