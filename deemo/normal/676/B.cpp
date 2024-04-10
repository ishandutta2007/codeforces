#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 10 + 2;

int n, t, ans, cc[MAXN][MAXN], zz[MAXN][MAXN];

int main(){
	cin >> n >> t;
	cc[1][1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cc[i][j] = cc[i - 1][1] << 1;

	for (int w = 1; w <= t; w++){
		zz[1][1]++;
		for (int i = 2; i <= n; i++)
			for (int j = 1; j <= i; j++){
				if (zz[i - 1][j] > cc[i - 1][j])
					zz[i][j] += zz[i - 1][j] - cc[i - 1][j];
				if (zz[i - 1][j - 1] > cc[i - 1][j-1])
					zz[i][j] += zz[i - 1][j - 1] - cc[i - 1][j - 1];
			}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= i; j++)
				zz[i][j] = min(zz[i][j], cc[i][j]);
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			if (cc[i][j] <= zz[i][j])
				ans++;
	cout << ans << endl;
	return 0;
}