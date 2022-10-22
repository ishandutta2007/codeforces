#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef long long ll;

const ll MAXN = 2e3 + 100;

ll n, t[MAXN], c[MAXN];
ll d[MAXN][MAXN], e[MAXN][MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> t[i] >> c[i];

	memset(e, 63, sizeof(e));
	memset(d, 63, sizeof(d));
	e[0][0] = 0;
	for (ll i = 0; i < MAXN; i++)	d[0][i] = 0;
	for (ll i = 1; i <= n; i++)
		for (ll j = 0; j <= n; j++){
			d[i][j] = d[i - 1][min(n, j + t[i - 1])] + c[i - 1];
			if (t[i - 1] > j)
				e[i][j] = d[i - 1][min(n, t[i - 1] - j)] + c[i - 1];
			else
				e[i][j] = e[i - 1][j - t[i - 1]] + c[i - 1];

			if (j)
				d[i][j] = min(d[i][j], d[i - 1][j - 1]);
			else
				d[i][j] = min(d[i][j], e[i - 1][1]);
			e[i][j] = min(e[i][j], e[i - 1][j + 1]);
		}
	cout << d[n][0] << "\n";
	return	0;
}