#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector <ll> V;
ll D[33][2];
ll n, a1, a2;

void f(vector <ll> &V, ll b)
{
	if(V.empty() || b < 0) return;

	vector <ll> L, R;
	ll t = 1ll << b;
	ll l, r, lc, rc;

	l = r = lc = rc = 0;
	for(auto &x: V){
		if(x & t) l ++, lc += r, L.push_back(x);
		else r ++, rc += l, R.push_back(x);
	}
	D[b][1] += lc; D[b][0] += rc;

	f(L, b - 1); f(R, b - 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll i, x;

	cin >> n;

	for(i = 1; i <= n; i ++){
		cin >> x;
		V.push_back(x);
	}

	f(V, 31);

	for(i = 0; i <= 31; i ++){
		if(D[i][0] > D[i][1]) a2 |= (1ll << i), a1 += D[i][1];
		else a1 += D[i][0];
	}

	cout << a1 << " " << a2 << "\n";

	return 0;
}