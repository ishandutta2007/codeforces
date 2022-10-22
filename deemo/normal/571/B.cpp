#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 3e5 + 10;
const ll MAXK = 5e3 + 20;
const ll INF = 1e18;

ll n, k, vec[MAXN];
ll d[MAXK][MAXK];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (ll i = 0; i < n; i++)	cin >> vec[i];
	sort(vec, vec + n);

	ll s1 = n/k, a = k - (n % k);
	ll s2 = n/k + bool(n % k), b = k - a;
	d[0][0] = 0;
	for (ll i = 0; i <= a; i++)
		for (ll j = 0; j <= b; j++)
			if (i || j){
				ll sz = i * s1 + j * s2;
				d[i][j] = INF;
				if (i)
					d[i][j] = min(d[i - 1][j] + vec[sz - 1] - vec[sz - s1], d[i][j]);
				if (j)
					d[i][j] = min(d[i][j - 1] + vec[sz - 1] - vec[sz - s2], d[i][j]);
			}
	cout << d[a][b] << "\n";
	return	0;	
}