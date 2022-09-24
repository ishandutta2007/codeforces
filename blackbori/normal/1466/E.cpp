#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll X[505050], S[66];
ll n;

void tc()
{
	ll i, j, s, t;
	cin >> n;

	for(i = 0; i < 60; i ++){
		S[i] = 0;
	}

	for(i = 0; i < n; i ++){
		cin >> X[i];
		for(j = 0; j < 60; j ++){
			if(X[i] & 1ll << j){
				S[j] ++;
			}
		}
	}

	s = 0;
	for(i = 0; i < n; i ++){
		t = 0;
		for(j = 0; j < 60; j ++){
			if(X[i] & 1ll << j) t = (t + (1ll << j) % mod * n) % mod;
			else t = (t + (1ll << j) % mod * S[j]) % mod;
		}
		for(j = 0; j < 60; j ++) if(X[i] & 1ll << j){
			s = (s + (1ll << j) % mod * t % mod * S[j]) % mod;
		}
	}

	cout << s << "\n";
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