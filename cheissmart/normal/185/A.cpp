#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)
#define m int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

ll mpow(ll n) {
	if(n == 0) return 1;
	ll p = mpow(n/2);
	if(n&1) {
		return p * p % m * 2;
	} else {
		return p * p % m;
	}
}

int main()
{
	IO_OP;
	
	ll n;
	cin >> n;
	if(n == 0) {
		cout << 1 << endl;
		return 0;
	}
	ll p = mpow(n-1);
	cout << ((p * p % m * 2 % m) + p % m) % m << endl;
}