#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll MOD;
ll P;

bool isPrime(ll n) {
	for(ll i=2;i*i<=n;++i) {
		if(n%i == 0) return false;
	}
	return true;
}

const int NMAX = 5050;
string s;
ll hsh[NMAX];
ll rev[NMAX];
ll pww[NMAX*2];
int N;

void setup() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	MOD = rng()%((int) 1e8) + 9e8;
	while(!isPrime(MOD)) ++MOD;
	P = rng()%((int) 1e8) + 1e8;
	while(!isPrime(P)) ++ P;
	ll pw = P;
	pww[0] = 1;
	for(int i=1;i<=N;++i, pw=(pw*P)%MOD) {
		hsh[i] = (hsh[i-1]+pw*s[i-1])%MOD;
		pww[i] = pw;
		rev[N-i] = (rev[N-i+1]+pw*s[N-i])%MOD;
	}
	for(int i=N+1;i<NMAX*2;++i, pw=(pw*P)%MOD) {
		pww[i] = pw;
	}
}

// [l, r)
ll gethash(int l, int r) {
	return (MOD+((MOD+hsh[r]-hsh[l])*pww[N-l])%MOD)%MOD;
}
ll getrevhash(int l, int r) {
	return (MOD+(MOD+rev[l]-rev[r])*pww[r]%MOD)%MOD;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> s;
	N = s.size();
	setup();
	for(int i=0;i<=N/2;++i) {
		ll h1 = gethash(i, i+N/2);
		ll h2 = getrevhash(0, i);
		h2 = (h2 + (MOD+rev[i+N-N/2]-rev[N])*pww[N+i]%MOD)%MOD;
		//cerr << " i = " << i << " " << h1 << " " << h2 << endl;
		if(h1 == h2 && h1 != gethash(0, N/2)) {
			cout << "1" << endl;
			return 0;
		}
	}
	for(int i=1;i<=N/2;++i) {
		if(getrevhash(0, i) != gethash(0, i)) {
			cout << "2" << endl;
			//////cerr << " at " << i << endl;
			return 0;
		}
	}
	for(int i=1;i<=N/2;++i) {
		for(int j=i+1;j<=N/2;++j) {
			ll h1 = gethash(0, j);
			ll h2 = gethash(i, j);
			h2 = (h2 + hsh[i]*pww[N-i+j]%MOD)%MOD;
			////cerr << "!! " << h1 << " " << h2 << " " << i << " " << j << endl;
			if(h2 != h1) {
				cout << "4" << endl;
				return 0;
			}
		}
	}
	cout << "Impossible" << endl;

	return 0;
}