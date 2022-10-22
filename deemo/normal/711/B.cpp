#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAXN = 1e3 + 10;

ll n, a[MAXN][MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	if (n == 1){
		cout << "1\n";
		return 0;
	}
	ll x = 0, y = 0;
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < n; j++){
			cin >> a[i][j];
			if (a[i][j] == 0)
				x = i, y = j;
		}
	ll sm = 0;
	for (ll i = 0; i < n; i++){
		sm = 0;
		bool found = 0;
		for (ll j = 0; j < n; j++){
			sm += a[i][j];
			if (a[i][j] == 0)	found = 1;
		}
		if (!found)	break;
	}
	ll temp = 0;
	for (ll j = 0; j < n; j++)	temp += a[x][j];
	if (temp >= sm){
		cout << "-1\n";
		return 0;
	}
	a[x][y] = sm - temp;
	for (ll i = 0; i < n; i++){
		ll v = 0;
		for (ll j = 0; j < n; j++)		v += a[i][j];
		if (v^sm){
			cout << "-1\n";
			return 0;
		}
	}
	for (ll j = 0; j < n; j++){
		ll v = 0;
		for (ll i = 0; i < n; i++)
			v += a[i][j];
		if (v^sm){
			cout << "-1\n";
			return 0;
		}
	}

	ll v = 0;
	for (ll i = 0; i < n; i++)	v += a[i][i];
	if (v^sm){
		cout << "-1\n";
		return 0;
	}

	v = 0;
	for (ll i = 0; i < n; i++)	v += a[i][n - i - 1];
	if (v^sm){
		cout << "-1\n";
		return 0;
	}

	cout << a[x][y] << "\n";
	return 0;
}