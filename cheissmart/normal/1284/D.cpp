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

const int M = 1e9 + 9, N = 100005;

int w[N], l1[N], r1[N], l2[N], r2[N];
int h1[N], h2[N];

bool easy(int n) {
	for(int i=0;i<n;i++)
		cin >> l1[i] >> r1[i] >> l2[i] >> r2[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) {
			bool x = max(l1[i], l1[j]) <= min(r1[i], r1[j]);
			bool y = max(l2[i], l2[j]) <= min(r2[i], r2[j]);
			if(x != y) return false;
		}
	return true;
}

vi add[2*N], del[2*N];
int p[N];

void go(V<pair<pi, int>> & v, int* h) {
	for(int i=0;i<2*N;i++) add[i].clear(), del[i].clear();
	vi d;
	for(auto e:v)  d.PB(e.F.F), d.PB(e.F.S);
	d.resize(unique(ALL(d)) - d.begin());
	sort(ALL(d));
	for(auto& e:v) {
		e.F.F = lower_bound(ALL(d), e.F.F) - d.begin();
		e.F.S = lower_bound(ALL(d), e.F.S) - d.begin();
	}
	for(auto e:v) {
		int l = e.F.F, r = e.F.S, i = e.S;
		add[l].PB(i);
		del[r].PB(i);
	}
	int s = 0;
	for(int i=0;i<2*N;i++) {
		for(int j:add[i]) {
			h[j] = (h[j] + s) % M;
		}
		for(int j:del[i]) {
			s += p[w[j]] % M;
			s %= M;
		}
	}
	s = 0;
	for(int i=2*N-1;i>=0;i--) {
		for(int j:del[i]) {
			h[j] = (h[j] + s) % M;
		}
		for(int j:add[i]) {
			s += p[w[j]];
			s %= M;
		}
	}
} 

bool hard(int n) {
	V<pair<pi, int>> x, y;
	for(int i=0;i<n;i++) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		x.PB({{l1, r1}, i});
		y.PB({{l2, r2}, i});
	}
	go(x, h1);
	go(y, h2);
	for(int i=0;i<n;i++) {
		if(h1[i] != h2[i]) {
			return false;
		}
	}
	return true;
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	iota(w, w+n, 2);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	shuffle(w, w+n, rng);
	p[0] = 1;
	for(int i=1;i<n;i++)
		p[i] = p[i-1] * 2 % M;
	if(n < 1000) {
		if(easy(n)) cout << "YES" << endl;
		else cout << "NO" << endl;
	} else {
		if(hard(n)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
}