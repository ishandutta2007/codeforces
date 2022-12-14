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

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vi a(n), b(n);
		for(int& i:a) cin >> i;
		for(int& i:b) cin >> i;
		auto ok = [&] (int m) {
			vi aa = a, bb = b;
			for(int i = 0; i < m; i++) {
				aa.PB(100);
				bb.PB(0);
			}
			sort(ALL(aa)), sort(ALL(bb));
			reverse(ALL(aa)), reverse(ALL(bb));
			int take = int(aa.size()) / 4;
			for(int i = 0; i < take; i++)
				aa.pop_back(), bb.pop_back();
			return accumulate(ALL(aa), 0LL) >= accumulate(ALL(bb), 0LL);
		};
		int lb = 0, rb = n;
		while(lb <= rb) {
			int mb = (lb + rb) / 2;
			if(ok(mb)) rb = mb - 1;
			else lb = mb + 1;
		}
		cout << lb << '\n';
	}

	
}