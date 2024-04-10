#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 10;

ll n, x, a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> x;	x--;
	ll mn = 1e9;
	for (ll i = 0; i < n; i++)	cin >> a[i], mn = min(mn, a[i]);
	ll ans = mn * n;
	for (ll i = 0; i < n; i++)	a[i] -= mn;
	if (a[x] == 0)
		a[x] = ans;
	else{
		while (1){
			a[x]--;
			ans++;
			if (a[(x - 1 + n) % n] == 0){
				a[(x - 1 + n) % n] = ans;
				break;
			}
			x = (x - 1 + n) % n;
		}
	}

	for (ll i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n";
	return	0;
}