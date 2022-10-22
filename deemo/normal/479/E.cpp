#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 5e3 + 4;
const int MOD = 1e9 + 7;

int n, a, b, k;
int d[MAXN][MAXN], p[MAXN][MAXN];

int main(){
	cin >> n >> a >> b >> k;
	for (int i = 1; i <= n; i++)	
		if (i != b)	d[i][0] = 1;

	for (int j = 0; j <= k; j++)
		for (int i = 1; i <= n; i++){
			if (j){
				int z = abs(i - b);
				if (z > 1){
					z--;
					d[i][j] = (p[j - 1][min(n, i + z)] + MOD - p[j - 1][max(0, i - z - 1)]) % MOD;
					d[i][j] = (d[i][j] + MOD - d[i][j - 1]) % MOD;
				}	
			}
			
			p[j][i] = (p[j][i - 1] + d[i][j]) % MOD;
		}
	cout << d[a][k] << "\n";
	return	0;
}