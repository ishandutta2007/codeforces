#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 998244353;

ll F[303030], A[303030];

ll pow(ll x, ll y)
{
	ll z = 1;
	for(; y; y >>= 1){
		if(y & 1) z = z * x % mod;
		x = x * x % mod;
	}
	return z;
}

void tc()
{
	ll n, i, x, s = 0;
	cin >> n;

	for(i = 1, F[0] = 1; i <= n + n; i ++){
		cin >> A[i];
		F[i] = F[i - 1] * i % mod;
	}
	sort(A + 1, A + n + n + 1);
	for(i = 1; i <= n; i ++){
		s += A[n + i] - A[i];
	}
	s %= mod;
	x = pow(F[n], mod - 2);
	s = s * F[n + n] % mod;
	s = s * x % mod * x % mod;
	cout << s << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; t = 1;

	for(; t --; ) tc();

	return 0;
}