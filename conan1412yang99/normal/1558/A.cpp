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
		int a, b;
		cin >> a >> b;
		set<int> s;
		int A = (a + b) / 2, B = a + b - A;
		for(int _ = 0; _ < 2; _++) {
			int r = min(a, A) + min(b, B);
			int l = a + b - (min(a, B) + min(b, A));
			assert(l % 2 == r % 2);
			for(int i = l; i <= r; i += 2)
				s.insert(i);
			swap(A, B);
		}
		cout << s.size() << '\n';
		for(int i:s)
			cout << i << " ";
		cout << '\n';
	}
	
}