#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 20 + 1;
const int MAXT = 10 + 1;

int n, t;
ll d[2][MAXN][MAXT][5];

int main(){
	cin >> n >> t; n--;
	for (int w = 2; w <= 4; w++)
		d[1][1][0][w] = w-1;
	
	for (int i = 1; i < n; i++)
		for (int z = 0; z < 2; z++)
			for (int j = 0; j <= t; j++)
				for (int w = 1; w <= 4; w++){
					for (int w1 = w-1; w1; w1--)
						d[0][i + 1][j + z][w1] += d[z][i][j][w];
					if (j < t)
						for (int w1 = w+1; w1<5; w1++)
							d[1][i + 1][j][w1] += d[z][i][j][w];
				}

	ll ans = 0;
	for (int w = 1; w <= 4; w++)
		ans += d[0][n][t][w];
	cout << ans << endl;
	return 0;
}