#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAX = 2e3;

ll save[MAX];
int n, m;
ll a[MAX];
ll d[MAX][MAX];

void init(){
	save[0] = 1;
	for (int i = 1; i < MAX; i++)	save[i] = (save[i - 1] * 2) % MOD;

	d[0][0] = 1;
	for (int i = 1; i < MAX; i++){
		d[i][i] = d[i][0] = 1;
		for (int j = 1; j < i; j++)
			d[i][j] = (d[i - 1][j] + d[i - 1][j - 1]) % MOD;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;

	init();
	for (int i = 0; i < m; i++)	cin >> a[i];
	sort(a, a + m);

	ll x = a[0] - 1, y = n - a[m - 1];
	ll ans = d[n - m][x + y];

	ll left = (n - m) - (x + y);
	for (int i = 0; i < m - 1; i++){
		if (a[i] + 1 == a[i + 1])	continue;
		ans = (ans * d[left][a[i + 1] - a[i] - 1]) % MOD;
		ans = (ans * save[a[i + 1] - a[i] - 2]) % MOD;
		left -= a[i + 1] - a[i] - 1;
	}
	
	ans = (ans * d[x + y][x]) % MOD;

	cout << ans << endl;
	return 0;
}