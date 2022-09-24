#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll W[202020], S[202020];

void tc()
{
	vector <ll> V;
	ll n, i, u, v, s; s = 0;

	cin >> n;

	fill(S, S + n + 1, 0);
	for(i = 1; i <= n; i ++){
		cin >> W[i]; s += W[i];
	}
	for(i = 1; i < n; i ++){
		cin >> u >> v;
		S[u] ++; S[v] ++;
	}
	for(i = 1; i <= n; i ++){
		for(; -- S[i]; ){
			V.push_back(W[i]);
		}
	}
	sort(V.rbegin(), V.rend());

	cout << s;
	for(i = 0; i < V.size(); i ++){
		s += V[i];
		cout << " " << s;
	}
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
//*
	cin >> t;
/*/
	t = 1;
//*/
	for(; t --; ) tc();

	return 0;
}