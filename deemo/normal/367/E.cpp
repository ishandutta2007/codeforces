//Bones, sinking like stones all that we fought for..

#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 320;
const int MAXM = 1e5 + 10;
const int MOD = 1e9 + 7;

int n, m, x, d[2][MAXN][MAXM];;

int main(){
	//cout << sizeof(d) << "\n";
	cin >> n >> m >> x;
	if (n > m){
		cout << "0\n";
		return	0;
	}
	
	for (int i = 0; i < x; i++)	d[0][0][i] = 1;
	bool cur = 1;
	for (int w = 1; w <= n; w++){
		for (int i = 0; i <= n; i++)	d[cur][i][0] = 0;
		for (int i = n; i >= 0; i--)
			for (int j = 1; j <= m; j++){
				d[cur][i][j] = 0;
				if (j != x){
					d[cur][i][j] = d[cur][i][j - 1];
					d[cur][i][j] = (d[cur][i][j] + d[cur][i + 1][j - 1]) % MOD;
				}
				if (i)	d[cur][i][j] = (d[cur][i][j] + d[!cur][i - 1][j - 1]) % MOD;
				d[cur][i][j] = (d[cur][i][j] + d[!cur][i][j - 1]) % MOD;
			}
		cur = !cur;
	}

	long long ans = d[!cur][0][m];
	for (int i = 2; i <= n; i++)
		ans = (ans * i) % MOD;
	cout << ans << "\n";
	return	0;
}