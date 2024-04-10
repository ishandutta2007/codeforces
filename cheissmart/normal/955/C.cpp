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

const int INF = 1e9 + 7;

int sp[1000006], pre[1000006];
vi primes;
vi cnt[100];

int pw(int a, int b) {
	if(b == 0) return 1;
	int t = pw(a, b/2);
	if(b&1) {
		if(t > 1e9) return (ll)1e18+1;
		if(a > 1e18/(t*t)) return (ll)1e18+1;
		return t * t * a;
	}
	else {
		if(t > 1e9) return (ll)1e18+1;
		return t * t;
	}
}

int go(int n) {
	if(n == 0) return 0;
	if(n < 4) return 1;
	int ans = (int)(sqrt(n));
	for(int i=0;i<primes.size();i++) {
		if(cnt[i].empty()) continue;
		ans += upper_bound(ALL(cnt[i]), n) - cnt[i].begin();
	}
	return ans;
}

int32_t main()
{
	IO_OP;

	for(int i=2;i<1000006;i++) {
		if(sp[i]) continue;
		sp[i] = i;
		if(i < 60 && i != 2) primes.PB(i);
		for(int j=i*i;j<1000006;j+=i)
			if(!sp[j]) sp[j] = i;
	}
	for(int i=2;i<1000006;i++) {
		int x = i, g = 0;
		while(x != 1) {
			int p = sp[x], t = 0;
			while(x % p == 0) {
				x /= p;
				t++;
			}
			g = __gcd(g, t);
		}
		if(g != 1)
			pre[i] = sp[g];
		else
			pre[i] = INF;
	}
	for(int ii=0;ii<primes.size();ii++) {
		int p = primes[ii];
		for(int i=2;pw(i,p)<=(ll)1e18;i++) {
			if(pre[i] >= p)
				cnt[ii].PB(pw(i, p));
		}
	}

	int q;
	cin >> q;
	while(q--) {
		int l, r;
		cin >> l >> r;
		cout << go(r) - go(l - 1) << endl;
	}
}