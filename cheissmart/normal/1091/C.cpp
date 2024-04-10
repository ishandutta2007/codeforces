#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

vector<ll> v;
int gcd(int a, int b) {
	return a == 0 ? b : gcd(b%a, a);
}

void sol(int n, int k) {
	ll d = gcd(n, k), m = n/d;
	ll ans = m + d * m * (m - 1) / 2;
	v.PB(ans);
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int k=1;k*k<=n;k++) {
		if(n % k) continue;
		sol(n, k);
		if(k*k == n) continue;
		sol(n, n/k);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end())-v.begin());
	for(int e:v)
		cout << e << " ";
}