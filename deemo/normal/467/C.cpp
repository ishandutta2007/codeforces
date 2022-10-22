#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;

const ll max_n = 5e3 + 2;

ll n, m, k;
ll p[max_n], a[max_n];
ll d[max_n][max_n];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	p[0] = 0;
	for (ll i = 0; i < n; i++)
		p[i + 1] = p[i] + a[i];
	
	for (ll i = 0; i < n; i++)
		for (ll j = 1; j * m <= i + 1; j++){
			if (i + 1 == j * m)	d[i][j] = p[i + 1];
			else d[i][j] = max(d[i - 1][j], d[i - m][j - 1] + p[i + 1] - p[i - m + 1]);
		}
	cout << d[n - 1][k] << endl;
	return 0;
}