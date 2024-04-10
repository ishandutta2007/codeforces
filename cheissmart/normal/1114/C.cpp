#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e18 + 7;

int cntb[15], cntn[15];

signed main()
{
	IO_OP;
	
	int n, b;
	cin >> n >> b;
	vi primes;
	int bb = b;
	for(int i=2;i*i<=bb;i++) {
		if(bb % i == 0) {
			primes.PB(i);
			while(bb % i == 0) bb /= i;
		}
	}
	if(bb != 1) primes.PB(bb);
	assert(primes.size() < 15);
	for(int i=0;i<primes.size();i++) {
		while(b % primes[i] == 0) {
			b /= primes[i];
			cntb[i]++;
		}
	}
	for(int i=0;i<primes.size();i++) {
		int p = primes[i];
		while(p <= n) {
			cntn[i] += n / p;
			if(p > (n + primes[i] - 1) / primes[i]) break;
			if(p == (n + primes[i] - 1) / primes[i] && n % primes[i]) break;
			p *= primes[i];
		}
	}
	int ans = INF;
	for(int i=0;i<primes.size();i++)
		ans = min(ans, cntn[i]/cntb[i]);
	cout << ans << endl;
}