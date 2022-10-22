#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 2e3 + 10;

ll n, c[MAXN][MAXN];
ll ul[MAXN][MAXN], ur[MAXN][MAXN], dl[MAXN][MAXN], dr[MAXN][MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < n; j++)
			cin >> c[i][j];
	for (ll i = 1; i <= n; i++)
		for (ll j = 1; j <= n; j++){
			ul[i][j] = ul[i - 1][j - 1] + c[i - 1][j - 1];
			ur[i][j] = ur[i - 1][j + 1] + c[i - 1][j - 1];
		}
	for (ll i = n; i; i--)
		for (ll j = 1; j <= n; j++){
			dl[i][j] = dl[i + 1][j - 1] + c[i - 1][j - 1];
			dr[i][j] = dr[i + 1][j + 1] + c[i - 1][j - 1];
		}

	ll m1 = -1, m2 = -1;
	ll x, y, xx, yy;
	for (ll i = 1; i <= n; i++)
		for (ll j = 1; j <= n; j++){
			ll val = ul[i][j] + ur[i][j] + dr[i][j] + dl[i][j] - 3 * c[i - 1][j - 1];
			if ((i + j) % 2 == 0){
				if (m1 < val){
					m1 = val;
					x = i;
					y = j;
				}
			}
			else	if (m2 < val){
				m2 = val;
				xx = i;
				yy = j;
			}
		}
	cout << m1 + m2 << "\n";
	cout << x << " " << y << " " << xx << " " << yy << "\n";
	return	0;
}