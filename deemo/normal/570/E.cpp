#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 500 + 10;
const int MOD = 1e9 + 7;

int n, m;
string s[MAXN];
char cc[MAXN][MAXN];
int d[2][2 * MAXN][2 * MAXN];

bool fit(int a, int b){return 0 <= a && a < n && 0 <= b && b < m;}

void fix(){
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)	cc[i][j] = s[j][i];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)	s[i][j] = cc[i][j];
	swap(n, m);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> s[i];
	if (n > m)	fix();
	
	int a = (n + m - 2) / 2;
	int b = (n + m - 2) / 2 + bool((n + m - 2) % 2);

	bool cur = 0;
	if (a == b){
		for (int i = 0; i < n; i++)
			if (a - i >= 0)	d[cur][i][i] = 1;
	}
	else 
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (a - i >= 0 && b - j >= 0 && s[i][a - i] == s[j][b - j] && abs(i - j) + abs(a - i - (b - j)) == 1)
					d[cur][i][j] = 1;
	a--, b++;
	cur = !cur;
	for (; 0 <= a && b <= n + m - 2; a--, b++){
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++){
				d[cur][i][j] = 0;
				if (a - i >= 0 && b - j >= 0 && b - j < m && s[i][a - i] == s[j][b-j])
					for (int aa = 0; aa <= 1; aa++)
						for (int bb = 0; bb <= 1; bb++)
							if (aa + bb == 1 && fit(i + aa, a - i + bb))
								for (int cc = -1; cc <= 0; cc++)
									for (int dd = -1; dd <= 0; dd++)
										if (dd + cc == -1 && fit(j + cc, b - j + dd))
											d[cur][i][j] = (d[cur][i][j] + d[!cur][i + aa][j + cc]) % MOD;
			}
	
		cur = !cur;
	}
	
	cout << d[!cur][0][n - 1] << "\n";
	return	0;
}