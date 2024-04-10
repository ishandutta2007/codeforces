#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 200 + 10;
const int MAXVAL = 1e3 + 10;

int n, k, vec[MAXN];
ll d[2][MAXN][MAXVAL];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)	cin >> vec[i];
	sort(vec, vec + n);
	
	bool cur = 0;
	d[cur][0][0] = 1;
	for (int i = 0; i < n; i++){
		int x = vec[i], dif = vec[i];
		if (i)	dif -= vec[i - 1];
		else	dif = 0;

		for (int t = 0; t <= i; t++)
			for (int j = 0; j <= k; j++)	d[!cur][t][j] = 0;

		for (int t = 0; t <= i; t++)
			for (int j = 0; j <= k; j++)
				if (j + t * dif <= k){
					if (t)	d[!cur][t - 1][j + t * dif] = (d[!cur][t - 1][j + t * dif] + d[cur][t][j] * t) % MOD;
					d[!cur][t + 1][j + t * dif] = (d[!cur][t + 1][j + t * dif] + d[cur][t][j]) % MOD;
					d[!cur][t][j + t * dif] = (d[!cur][t][j + t * dif] + d[cur][t][j] * t) % MOD;
					d[!cur][t][j + t * dif] = (d[!cur][t][j + t * dif] + d[cur][t][j]) % MOD;
				}

		cur = !cur;
	}

	ll ans = 0;
	for (int i = 0; i <= k; i++)
		ans = (ans + d[cur][0][i]) % MOD;
	cout << ans <<"\n";
	return	0;	
}