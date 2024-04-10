#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 100 + 10;
const ll MOD = 1e9 + 7;

ll n;
ll a[15], b[12];
ll c[MAXN][MAXN];
ll save[MAXN], ss[MAXN];
ll d[MAXN][MAXN], e[MAXN][MAXN];

void init(){
	c[0][0] = 1;
	for (ll i = 1; i < MAXN; i++){
		c[i][i] = c[i][0] = 1;
		for (ll j = 1; j < i; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
}

int main(){
	cin >> n;
	ll sum = 0;
	for (ll i = 0; i < 10; i++){
		cin >> a[i];
		sum += a[i];
	}
	init();
	d[0][0] = 1;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 10; j++)
			for (int w = a[j]; w <= i; w++)
				d[i][j + 1] = (d[i][j + 1] + c[i][w] * d[i - w][j]) % MOD;
			
	if (a[0])	a[0]--;
	e[1][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 10; j++)
			for (int w = a[j]; w < i; w++)
				e[i][j + 1] = (e[i][j + 1] + c[i - 1][w] * e[i - w][j]) % MOD;
	
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + MOD + d[i][10] - e[i][10]) % MOD;
	cout << ans << endl;
	return 0;
}