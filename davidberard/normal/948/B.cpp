#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int lgfact[1000001];
vector<int> primes;

void setup() {
	vector<bool> sieve(1000001, true);
	for(int i=2;i<=1000000;++i) {
		primes.push_back(i);
		if(sieve[i]) {
			for(ll j=i;j<1000001;j+=i) {
				lgfact[j] = max(i, lgfact[j]);
				if(j >= i*i)
					sieve[j] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	setup();
	int X2; cin >> X2;
	int mn = X2-lgfact[X2]+1;
	int X0=X2;
	for(int i=mn;i<=X2;++i) {
		if(i == lgfact[i]) continue;
		//cerr; if(i-lgfact[i]+1 < X0) {
			//cerr << "Improvement from step " << i << " going to " << i-lgfact[i]+1 << " by factor " << lgfact[i] << endl;
		//cerr; }
		X0 = min(X0, i-lgfact[i]+1);
	}
	cout << X0 << endl;

	return 0;
}