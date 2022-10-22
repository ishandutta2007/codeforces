//I can't believe in you..

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 2e3 + 10;

char c[MAXN][MAXN], sc[MAXN][MAXN];
ll dn[MAXN][MAXN], ri[MAXN][MAXN], le[MAXN][MAXN], up[MAXN][MAXN], p[MAXN][MAXN], d[MAXN][MAXN];
ll n, m, aa, bb, cc, dd;

void rotate(){
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
			sc[m - j - 1][i] = c[i][j];
	swap(n, m);
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
			c[i][j] = sc[i][j];
}

void get_partial(){
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
			p[i + 1][j + 1] = p[i][j + 1] + d[i][j];
}

void cal(){
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
			if (c[i][j] == '#')	up[i][j] = le[i][j] = 0;
			else{
				if (i == 0)	up[i][j] = 1;
				else	up[i][j] = 1 + up[i - 1][j];
				if (j == 0)	le[i][j] = 1;
				else	le[i][j] = 1 + le[i][j - 1];
			}
	for (ll i = n - 1; i >= 0; i--)
		for (ll j = m - 1; j >= 0; j--)
			if (c[i][j] == '#')	dn[i][j] = ri[i][j] = 0;
			else{
				if (i == n - 1)	dn[i][j] = 1;
				else	dn[i][j] = 1 + dn[i + 1][j];
				if (j == m - 1)	ri[i][j] = 1;
				else	ri[i][j] = 1 + ri[i][j + 1];
			}

	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)	d[i][j] = 0;
	
	for (ll i = 1; i < n - 1; i++)	if (ri[i][0] == m)	aa++;
	for (ll i = 1; i < n - 1; i++)
		for (ll j = 1; j < m - 1; j++){
			if (le[i][j] == j + 1 && up[i][j] == i + 1)	bb++;
			if (le[i][j] == j + 1 && dn[i][j] == n - i)	bb++;	
		}

	for (ll i = 1; i < n - 1; i++)
		for (ll j = 1; j < m - 1; j++)
			d[i][j] = bool(ri[i][j] == m - j);
	get_partial();
	for (ll i = 1; i < n - 1; i++)
		for (ll j = 1; j < m - 1; j++)
			if (le[i][j] == j + 1){
				cc += p[i][j + 1] - p[i + 1 - up[i][j]][j + 1];
				cc += p[i + dn[i][j]][j + 1] - p[i + 1][j + 1];
			}

	for (ll i = 1; i < n - 1; i++)
		for (ll j = 1; j < m - 1; j++)	d[i][j] = bool(le[i][j] == j + 1);
	get_partial();
	for (ll i = 1; i < n - 1; i++)
		for (ll j = 1; j < m - 1; j++)
			if (le[i][j] == j + 1 && up[i][j] > 2)
				dd += p[i - 1][j + 1] - p[i + 1 - up[i][j]][j + 1];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (ll i = 0; i < n; i++){
		string temp;	cin >> temp;
		for (ll j = 0; j < m; j++)
			c[i][j] = temp[j];
	}
	for (ll i = 0; i < 4; i++)	cal(), rotate();
	cout << aa/2 + bb/2 + cc/2 + dd << "\n";
	return	0;
}