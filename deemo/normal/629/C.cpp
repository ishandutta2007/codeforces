#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 20;
const int MAXM = 5e3 + 20;
const int MOD = 1e9 + 7;

int n, m;
string s;
ll d[MAXM][MAXM];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	d[0][0] = 1;
	for (int i = 1; i < MAXM; i++)
		for (int j = 0; j <= i; j++){
			if (j)
				d[i][j] = (d[i - 1][j - 1] + d[i][j]) % MOD;
			d[i][j] = (d[i][j] + d[i - 1][j + 1]) % MOD;
		}

	cin >> n >> m;
	cin >> s;
	int sm = 0, mn = 0, mx = 0;
	for (char ch:s){
		if (ch == '(')	sm++;
		else	sm--;
		mn = min(mn, sm);
		mx = max(mx, sm);
	}	

	if (sm > (int)2e3 + 5){
		cout << "0\n";
		return	0;
	}

	ll ans = 0;
	for (int i = 0; i <= (n - m); i++){
		int rem = (n - m) - i;
		for (int j = 0; j <= i; j++)
			if (mn + j >= 0)
				ans = (ans + d[i][j] * d[rem][sm + j]) % MOD;
	}
	cout << ans << "\n";
	return	0;
}