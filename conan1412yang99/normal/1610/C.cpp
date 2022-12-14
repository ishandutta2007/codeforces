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

void solve() {
	int n;
	cin >> n;
	vi a(n), b(n);
	for(int i = 0; i < n; i++)
		cin >> b[i] >> a[i];

	auto ok = [&] (int x) {
		int now = 0;
		for(int i = 0; i < n && now < x; i++) {
			if(a[i] >= now && b[i] >= x - now - 1) {
				now++;
			}
		}
		return now == x;
	};

	int lb = 1, rb = n;
	while(lb <= rb) {
		int mb = (lb + rb) / 2;
		if(ok(mb))
			lb = mb + 1;
		else
			rb = mb - 1;
	}
	cout << rb << '\n';
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--)
		solve();

}