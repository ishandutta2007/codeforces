#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> primes;
vector<bool> sieve;

void setup() {
	sieve = vector<bool>(35000, true);
	for(int i=2;i<35000;++i) {
		if(sieve[i]) {
			primes.push_back(i);
			for(ll j=(ll) i * i; j< 35000;j+=i) {
				sieve[j] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	setup();
	int p, y;
	cin >> p >> y;
	bool found = false;
	for(int v = y; v > y-1e3 && v > p; --v) {
		int u = v;
		bool good = true;
		for(int i=0; good && (ll) primes[i] * primes[i] <= u;++i) {
			if(u%primes[i] == 0 && primes[i] <= p)
				good = false;
			while(u%primes[i] == 0) {
				u /= primes[i];
			}
		}
		if(good) {
			found = true;
			cout << v << endl;
			break;
		}
	}
	if(!found)
		cout << -1 << endl;

	return 0;
}
// David Berard