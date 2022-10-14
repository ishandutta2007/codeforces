// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 1000000007;

const int msqn = 316300;
bool isc[msqn+5];
int primes[27300]; int prc, c;
void sieve(int M) {
	isc[0]=isc[1]=1;
	iter(i, 2, M+1) {
		if(!isc[i]) primes[++prc] = i;
		if(!(i&1)&&(i<<1)<=M) {
			isc[i<<1] = 1;
			continue;
		}
		for(register int j=1; j<=prc; j+=5) {
			if(primes[j] * i > M+1) break;
			isc[primes[j] * i] = 1;
			if(!(i % primes[j]) || !primes[j+1] || (primes[j+1] * i > M+1)) break;
			isc[primes[j+1] * i] = 1;
			if(!(i % primes[j+1]) || !primes[j+2] || (primes[j+2] * i > M+1)) break;
			isc[primes[j+2] * i] = 1;
			if(!(i % primes[j+2]) || !primes[j+3] || (primes[j+3] * i > M+1)) break;
			isc[primes[j+3] * i] = 1;
			if(!(i % primes[j+3]) || !primes[j+4] || (primes[j+4] * i > M+1)) break;
			isc[primes[j+4] * i] = 1;
		}
	}
}

namespace PCF {
	ll ans[2*msqn+5], ind1[2*msqn+5], ind2[2*msqn+5], w[2*msqn+5], tot = 0, sqr, NN;
	void init(ll n) {
		sqr = sqrt(n);
		tot = 0;
		for(ll l = 1, r; l <= n; l = r + 1) {
			r = n / (n / l);
			w[++tot] = n / l;
			ans[tot] = w[tot] - 1;
			if(n / l <= sqr) ind1[n / l] = tot;
			else ind2[r] = tot;
		}
		rep1(i, prc)
			for(int j = 1; j <= tot && 1ll * primes[i] * primes[i] <= w[j]; j++) {
				ll v = w[j] / primes[i];
				ll k = (v <= sqr) ? ind1[v] : ind2[n / v];
				ans[j] -= ans[k] - (i - 1);
			}
		NN = n;
	}
	ll cnt(ll n) { 
		return (n <= sqr) ? ans[ind1[n]] : ans[ind2[NN / n]]; 
	}
}


ll cnt(ll n) {
    //PCF::init(n);
    return PCF::cnt(n);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    sieve(msqn);
    ll n; cin >> n;
    ll cbrt = 1, ans = 0;
    while((cbrt+1)*(cbrt+1)*(cbrt+1) <= n) {
        cbrt++;
        if(!isc[cbrt]) ans++;
    }
    PCF::init(n);
    rep1(i, prc) {
        if(n/primes[i] > primes[i]) ans += cnt(n/primes[i]) - i;
    }
    cout << ans << endl;
}