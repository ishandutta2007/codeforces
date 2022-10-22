#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 100 + 5;

ll n, m, c[MAXN][MAXN], maxi, a[MAXN], b[MAXN];
ll mod = 1e18;

int main(){
	cin >> n >> m;
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
			cin >> c[i][j], maxi = max(maxi, c[i][j]);

	for (ll i = 0; i < n; i++)		
		a[i] = c[i][0];

	for (ll j = 1; j < m; j++){
		ll dif = c[0][j] - c[0][j - 1];
		for (ll i = 1; i < n; i++){
			ll x = c[i][j] - c[i][j - 1];
			if (dif == x)	continue;

			ll z = abs(dif - x);
			if (mod != 1e18 && z != mod){
				cout << "NO\n";
				return	0;
			}
			else	mod = z;

			if (mod <= maxi){
				cout << "NO\n";
				return	0;
			}
		}
		b[j] = c[0][j] - a[0];
	}
	
	cout << "YES\n";
	cout << mod << "\n";
	for (ll i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n";
	for (ll i = 0; i < m; i++){
		while (b[i] < 0)	b[i] += mod;
		cout << b[i] << " ";
	}
	cout << "\n";
	return	0;
}