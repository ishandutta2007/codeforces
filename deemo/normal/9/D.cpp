#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int MAXN = 35 + 2;

int n, h;
ull d[MAXN][MAXN];

int main(){
	cin >> n >> h;
	d[0][0] = d[1][1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++)
			for (int k = 1; k <= i; k++)
				for (int a = 0; a < j; a++)
					for (int b = 0; b < j; b++)
						if (max(a, b) == j-1)
							d[i][j] += d[k - 1][a] * d[i - k][b];

	ull ans = 0;
	for (int i = h; i < MAXN; i++)
		ans += d[n][i];
	cout << ans << endl;
	return 0;
}