#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

ll f(ll x, ll n){
	if(x & 1) return x / 2 + 1;
	ll t = x/2, m = (n + 1) / 2;
	if(n & 1) {
		t--;
		if(t == 0) t = n - m;
	}
	ll r = f(t, n-m);
	return r + m;
} 

int main()
{
	IO_OP;

	ll n;
	int q;
	cin >> n >> q;
	while(q--) {
		ll x;
		cin >> x;
		cout << f(x, n) << endl;
	}
	
}