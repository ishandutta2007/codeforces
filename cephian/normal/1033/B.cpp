#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;


#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

const int N = 1e6;
ll comp[N] = {};
vector<ll> primes;
bool prime(ll a) {
	for(auto x : primes) {
		if(x * x > a) return true;
		if(a%x == 0) return false;
	}
	return true;
}

int main() {
	fio;
	for(int i = 2; i < N; ++i) {
		if(!comp[i]) {
			primes.push_back(i);
			for(ll j = i; j < N; j += i) {
				comp[j] = true;
			}
		}
	}

	int t;
	cin >> t;
	for(int i = 0; i < t; ++i) {
		ll a, b;
		cin >> a >> b;
		if(a-b == 1 && prime(a+b)) {
			cout << "YES\n";
		} else cout << "NO\n";
	}
}