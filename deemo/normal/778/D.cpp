#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 50 + 3;
const int XX = 2e5;

int n, m;
string s[2][MAXN], tt[MAXN];
pii ans[XX]; int sz;

void go(int x, int y, int t){
	if (s[t][x][y] == 'U') return;
	if (s[t][x + 1][y] != 'L'){
		go(x+1, y+1, t);
		ans[sz++] = {x+1, y};
		s[t][x+1][y] = s[t][x+2][y] = 'L';
		s[t][x+1][y+1] = s[t][x+2][y+1] = 'R';
	}

	ans[sz++] = {x, y};
	s[t][x][y] = s[t][x][y+1] = 'U';
	s[t][x+1][y] = s[t][x+1][y+1] = 'D';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int w = 0; w < 2; w++)
		for (int i = 0; i < n; i++)
			cin >> s[w][i];

	bool fl = 0;
	if (n&1){
		fl = 1;
		for (int w = 0; w < 2; w++){
			for (int i = 0; i < n; i++) tt[i] = s[w][i];

			for (int j = 0; j < m; j++) s[w][j].resize(m);
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
					s[w][i][j] = tt[n-1-j][i];

			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
					if (s[w][i][j] == 'U') s[w][i][j] = 'R';
					else if (s[w][i][j] == 'D') s[w][i][j] = 'L';
					else if (s[w][i][j] == 'R') s[w][i][j] = 'D';
					else s[w][i][j] = 'U';
		}
		swap(n, m);
	}
	
	for (int i = 0; i < n; i += 2)
		for (int j = 0; j < m; j++)
			go(i, j, 0);
	int temp = sz;
	for (int i = 0; i < n; i += 2)
		for (int j = 0; j < m; j++)
			go(i, j, 1);
	reverse(ans + temp, ans + sz);

	if (fl)
		for (int i = 0; i < sz; i++){
			auto temp = ans[i];
			ans[i].S = temp.F;
			ans[i].F = m-1-temp.S-1;
		}

	cout << sz << "\n";
	for (int i = 0; i < sz; i++)
		cout << ans[i].F+1 << " " << ans[i].S+1 << "\n";
	return 0;
}