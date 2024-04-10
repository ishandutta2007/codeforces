#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXK = 250 + 10;
const int MAXN = 1e6 + 10;

ll n, k, x[MAXK], y[MAXK], ans[MAXN];

ll get(ll a, ll b, ll c, ll d){
	if (b == d)	return	-1;
	if (a > c)	swap(a, c), swap(b, d);

	ll aa = abs(b - d);
	ll bb = abs(a - c);
	ll z = bb * max(b, d);
	if (z % aa)	return	-1;
	z /= aa;
	
	if (b < d)	return	c - z;
	return	a + z;
}

bool on_the_line(int a, int b, int c){
	return (b[x] - a[x]) * (c[y] - a[y]) - (b[y] - a[y]) * (c[x] - a[x]) == 0;
}	

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;	for (ll i = 0; i < k; i++)	cin >> x[i] >> y[i];
	for (ll i = 0; i < k; i++)
		for (ll j = 0; j < k; j++)
			if (i != j){
				ll xx = get(x[i], y[i], x[j], y[j]);
				if (0 < xx && xx <= n){
					ll ret = 2;
					for (ll w = 0; w < k; w++)
						if (w != i && w != j && on_the_line(i, j, w))	ret++;
					ans[xx] = max(ans[xx], ret);
				}
			}

	ll res = 0;
	for (ll i = 1; i <= n; i++)	res += max(1LL, ans[i]);
	cout << res << "\n";
	return	0;
}