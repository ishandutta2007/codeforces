#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef long long ll;

const ll MAXN = 2e3 + 10;
const ll MOD = 1e9 + 7;

ll n, m;
ll dd;
string s1, s2;
ll d[MAXN][MAXN], c[MAXN][MAXN], e[MAXN][MAXN];

ll solve(){
	d[0][0] = 1;
	c[0][0] = 1;
	e[0][0] = 1;
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
			for (ll w = 0; w < 10; w++){
				if (i % 2 == 1 && w != dd)	continue;
				if (i % 2 == 0 && w == dd)	continue;
				d[i + 1][(j * 10 + w) % m] = (d[i + 1][(j * 10 + w) % m] + d[i][j]) % MOD;
				
				if (w < s1[i] - '0')	d[i + 1][(j * 10 + w) % m] = (d[i + 1][(j * 10 + w) % m] + MOD - c[i][j]) % MOD;
				if (w > s2[i] - '0')	d[i + 1][(j * 10 + w) % m] = (d[i + 1][(j * 10 + w) % m] + MOD - e[i][j]) % MOD;

				if (w == s1[i] - '0')	c[i + 1][(j * 10 + w) % m] = (c[i + 1][(j * 10 + w) % m] + c[i][j]) % MOD;
				if (w == s2[i] - '0')	e[i + 1][(j * 10 + w) % m] = (e[i + 1][(j * 10 + w) % m] + e[i][j]) % MOD;
			}
	return	d[n][0];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> dd;
	cin >> s1 >> s2;	n = s1.size();
	cout << solve() << "\n";
	return	0;
}