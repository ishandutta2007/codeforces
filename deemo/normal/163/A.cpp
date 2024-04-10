#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 5e3 + 10;
const int MOD = 1e9 + 7;

ll ans, d[MAXN][MAXN];
int n, m, f[MAXN];
string s, t;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;	n = s.size(), m = t.size();

	ll ans = 0;
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--){
			d[i][j] = d[i][j + 1];
			if (s[i] == t[j])
				d[i][j] = (d[i][j] + 1 + d[i + 1][j + 1]) % MOD;
			if (j == 0)	ans = (ans + d[i][j]) % MOD;
		}
	cout << ans << "\n";
	return	0;
}