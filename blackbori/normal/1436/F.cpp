#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 998244353;

ll A[101010], M[101010];
vector <ll> P;
ll m, a;

ll pow(ll x, ll y)
{
	y %= mod - 1;
	if(y < 0) y += mod - 1;

	ll z = 1;

	for(; y; y >>= 1){
		if(y & 1) z = z * x % mod;
		x = x * x % mod;
	}

	return z;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll x, y, i, j, s0, s1, s2;

	cin >> m;

	for(i = 1; i <= m; i ++){
		cin >> x >> y;
		A[x] = y;
	}

	m = 1e5;

	for(i = 2, M[1] = 1; i <= m; i ++){
		if(!M[i]) M[i] = i, P.push_back(i);
		for(ll &p: P){
			if(p * i > m) break;
			M[p * i] = p;
			if(p == M[i]) break;
		}
		M[i] = i / M[i] % M[i]? -M[i / M[i]] : 0;
	}

	for(i = 1; i <= m; i ++) if(M[i]){
		s0 = s1 = s2 = 0;
		for(j = i; j <= m; j += i){
			s0 += A[j];
			s1 = (s1 + j * A[j]) % mod;
			s2 = (s2 + j * j % mod * A[j]) % mod;
		}
		x = ((s0 - 1) % mod * pow(2ll, s0 - 2) % mod * s2 +
			s0 % mod * pow(2ll, s0 - 3) % mod * ((s1 * s1 - s2) % mod)) % mod;
		a += x * M[i];
	}

	a %= mod;
	cout << (a + mod) % mod << "\n";

	return 0;
}