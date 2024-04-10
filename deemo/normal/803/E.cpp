#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;
const int C = 1e3 + 10;

int n, k;
string s;
int par[MAXN][C<<1];
bool d[MAXN][C<<1];

void go(int a, int b){
	string ans;
	while (a){
		if (par[a][b] == b)
			ans += 'D', a--;
		else if (par[a][b] == b+1)
			ans += 'L', a--, b++;
		else if (par[a][b] == b-1)
			ans += 'W', a--, b--;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
	exit(0);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	cin >> s;
	memset(par, -1, sizeof(par));
	d[0][0+C] = 1;
	int lo = -k+C, hi = k+C;
	for (int i = 0; i < n; i++)
		for (int j = lo+1; j < hi; j++)
			if (d[i][j]){
				if (s[i] != '?'){
					if (s[i] == 'L')
						d[i+1][j-1] = 1, par[i+1][j - 1] = j;
					if (s[i] == 'W')
						d[i+1][j+1] = 1, par[i+1][j + 1] = j;
					if (s[i] == 'D')
						d[i+1][j] = 1, par[i+1][j] = j;
				}
				else{
					d[i+1][j-1] = 1, par[i+1][j - 1] = j;
					d[i+1][j+1] = 1, par[i+1][j + 1] = j;
					d[i+1][j] = 1, par[i+1][j] = j;
				}
			}

	if (d[n][k+C]) go(n, k+C);
	else if (d[n][-k+C]) go(n, -k+C);
	cout << "NO\n";
	return 0;
}