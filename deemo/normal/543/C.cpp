#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 20;

int n, m, val[MAXN][MAXN], d[1<<MAXN], mx[30][30], sm[30][30], mask[30][30];
string s[MAXN];

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		for (int j = 0; j < m; j++)
			mask[j][s[i][j] - 'a'] |= 1<<i;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			cin >> val[i][j];

			int &temp = mx[j][s[i][j] - 'a'];
			temp = max(temp, val[i][j]);

			sm[j][s[i][j] - 'a'] += val[i][j];
		}

	memset(d, 63, sizeof(d));
	d[0] = 0;
	for (int ms = 1; ms < 1<<n; ms++){
		int v = __builtin_ctz(ms&-ms);
		
		for (int j = 0; j < m; j++){
			d[ms] = min(d[ms], d[ms ^ 1<<v] + val[v][j]);
			
			int ch = s[v][j] - 'a';
			d[ms] = min(d[ms], d[(ms ^ mask[j][ch]) & ms] + sm[j][ch] - mx[j][ch]);
		}
	}

	cout << d[(1<<n) - 1] << "\n";
	return 0;
}