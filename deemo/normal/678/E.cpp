#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector>

using namespace std;

typedef long double ld;

const int MAXN = 18 + 2;

int n;
int save[1<<MAXN];
ld p[MAXN][MAXN], d[MAXN][1<<MAXN];

int main(){
	cout << fixed << setprecision(12);
	cin >> n;
	for (int i = 0; i < n; i++)
		save[1<<i] = i;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> p[i][j];

	d[0][1] = 1;

	for (int ms = 1; ms < (1<<n); ms++)
		if (__builtin_popcount(ms) > 1){
			for (int i = 0; i < n; i++)
				if ((ms >> i) & 1){
					for (int j = 0; j < n; j++)
						if (i^j && (ms >> j) & 1){
							d[i][ms] = max(d[i][ms], p[i][j] * d[i][ms ^ (1<<j)] + p[j][i] * d[j][ms ^ (1<<i)]);
						}
				}
		}
	ld ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, d[i][(1<<n) - 1]);
	cout << ans << endl;
	return 0;
}