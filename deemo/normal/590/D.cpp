#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>

using namespace std;

const int MAXN = 150 + 4;
const int MAXMOVE = MAXN * MAXN/ 2;

int n, k, s, vec[MAXN];
int d[MAXN][MAXMOVE], c[MAXN][MAXMOVE];
int ans;

int main(){
	cin >> n >> k >> s;
	for (int i = 0; i < n; i++){
		cin >> vec[i];
		if (i < k)	ans += vec[i];
	}
	memset(d, 63, sizeof(d));
	for (int i = 0; i < MAXMOVE; i++)	d[0][i] = 0;
	for (int i = k; i < n; i++)	d[i - k + 1][0] = d[i - k][0] + vec[i];
	for (int i = 1; i < n - k; i++)
		for (int j = 1; j < MAXMOVE; j++)	d[i][j] = min(d[i][j], d[i][j - 1]);
	for (int i = k; i < n; i++)
		for (int j = i-k + 1; j; j--){
			for (int w = 0; w < MAXMOVE; w++)
				if (w >= max(0, (i - k - j + 1)))
					d[j][w] = min(d[j][w], d[j - 1][w - max(0, (i - k - j + 1))] + vec[i]);
			for (int w = 1; w < MAXMOVE; w++)
				d[j][w] = min(d[j][w], d[j][w - 1]);
		}	
	
	for (int i = k - 1; i >= 0; i--)
		for (int j = k - i; j; j--){
			for (int w = 0; w < MAXMOVE; w++)
				if (w >= max(0, (k - i - j)))
					c[j][w] = max(c[j][w], c[j - 1][w - max(0, (k - i - j))] + vec[i]);
			for (int w = 1; w < MAXMOVE; w++)
				c[j][w] = max(c[j][w], c[j][w - 1]);
		}

	int sum = ans;
	for (int i = 1; i <= k; i++)
		for (int j = 0; j <= min(s - i * i, MAXMOVE - 1); j++)
			ans = min(ans, sum - c[i][j] + d[i][min(s - j - i * i, MAXMOVE - 1)]);
	cout << ans << "\n";
	return	0;
}