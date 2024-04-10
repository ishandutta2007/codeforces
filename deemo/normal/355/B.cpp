#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 1e3 + 10;

ll a, b, c, d;
ll n, m, vec[MAXN], sec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b >> c >> d;
	cin >> n >> m;
	bool fl = 0;
	for (ll i = 0; i < n; i++)	cin >> vec[i], fl |= bool(vec[i]);
	for (ll i = 0; i < m; i++)	cin >> sec[i], fl |= bool(sec[i]);
	if (!fl){
		cout << "0\n";
		return	0;
	}

	ll ans = d;
	
	ll t = 0;
	for (ll i = 0; i < n; i++)
		t += min(vec[i] * a, b);
	ll tt = 0;
	for (ll i = 0; i < m; i++)
		tt += min(sec[i] * a, b);
	ans = min(ans, t + tt);
	
	ans = min(ans, c + t);
	ans = min(ans, c + tt);
	ans = min(ans, c + c);
	cout << ans << "\n";
	return	0;
}