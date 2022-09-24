#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll P[505050];
vector <ll> A;
ll n, m, a;

ll find(ll u) { return u == P[u]? u : P[u] = find(P[u]); }

void tc()
{
	ll i, k, u, v;

	cin >> n >> m;

	iota(P, P + m + 1, 0);

	for(i = 1; i <= n; i ++){
		cin >> k >> u;
		if(k == 1) v = 0;
		else cin >> v;

		if(find(u) != find(v)){
			P[find(u)] = find(v);
			A.push_back(i);
		}
	}

	for(i = 0, a = 1; i < A.size(); i ++){
		a = (a + a) % mod;
	}
	cout << a << " " << A.size() << "\n";
	for(ll &t: A) cout << t << " ";
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
/*
	cin >> t;
/*/
	t = 1;
//*/
	for(; t --; ) tc();

	return 0;
}