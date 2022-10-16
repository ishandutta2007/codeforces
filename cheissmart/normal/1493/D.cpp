#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7, M = 1e9 + 7;

int qpow(int a, int b) {
	if(b == 0) return 1;
	ll t = qpow(a, b / 2);
	t = t * t % M;
	if(b & 1) return t * a % M;
	else return t;
}

int cur = 1;
int ps[N];
unordered_map<int, int> cnt[N];
multiset<int> s[N];
int n, q;

int get(int p) {
	if(int(s[p].size()) < n) return 0;
	return *s[p].begin();
}

void upd(int pos, int val) {
	while(val != 1) {
		int p = ps[val], c = cnt[pos][p];
		while(val % p == 0) {
			val /= p;
			c++;
		}
		int old = cnt[pos][p], old_max = get(p);
		if(old) s[p].erase(s[p].find(old));
		s[p].insert(c);
		cur = (ll) cur * qpow(p, get(p) - old_max) % M;
		cnt[pos][p] = c;
	}
}

signed main()
{
	IO_OP;

	for(ll i = 2; i < N; i++) {
		if(ps[i]) continue;
		ps[i] = i;
		for(ll j = i * i; j < N; j += i)
			ps[j] = i;
	}

	cin >> n >> q;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		upd(i, x);
	}
	while(q--) {
		int i, x;
		cin >> i >> x;
		i--;
		upd(i, x);
		cout << cur << '\n';
	}
	
}