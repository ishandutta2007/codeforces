#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, N = 2e5 + 7;

vi G[N];

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int m, k;
		cin >> m >> k;
		G[m].PB(k);
	}
	pair<ll, int> mx = {-1LL, 1LL};
	for(int take = 1; take < 20; take++) {
		vi tt;
		for(int i = 0; i < N; i++) if(G[i].size()) {
			int sum = 0;
			for(int j:G[i])
				sum += min(j, take);
			tt.PB(sum);
		}
		sort(ALL(tt), greater<int>());
		ll ss = 0;
		for(int i = 0; i < min(take, int(tt.size())); i++)
			ss += tt[i];
		if(ss * mx.S > take * mx.F) {
			mx = {ss, take};
		}
	}
	vi tt;
	for(int i = 0; i < N; i++) if(G[i].size()) {
		int sum = 0;
		for(int j:G[i])
			sum += j;
		tt.PB(sum);
	}
	sort(ALL(tt), greater<int>());
	ll ss = 0;
	for(int i = 0; i < min(19, int(tt.size())); i++)
		ss += tt[i];
	for(int take = 20; take <= int(tt.size()); take++) {
		ss += tt[take - 1];
		if(ss * mx.S > take * mx.F) {
			mx = {ss, take};
		}
	}
	{
		int take = mx.S;
		cout << take << '\n';
		V<pi> tt;
		for(int i = 0; i < N; i++) {
			int sum = 0;
			for(int j:G[i])
				sum += min(j, take);
			tt.EB(sum, i);
		}
		sort(ALL(tt), greater<pi>());
		for(int i = 0; i < take; i++)
			cout << tt[i].S << " ";
		cout << '\n';
	}
}