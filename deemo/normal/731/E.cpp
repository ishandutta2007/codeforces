#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;

ll n, a[MAXN], p[MAXN], d[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i], p[i + 1] = p[i] + a[i];

	d[n] = 0;
	ll x = p[n];
	for (int i = n - 1; i; i--){
		d[i] = x;
		x = max(x, p[i] - x);
	}
	
	d[0] = p[n];
	for (int i = 2; i < n; i++)
		d[0] = max(d[0], p[i] - d[i]);
	cout << d[0] << "\n";
	return 0;
}