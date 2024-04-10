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

const int INF = 1e9 + 7, N = 1e5 + 7;

int bit[N];

void add(int pos, int val = 1) {
	for(; pos < N; pos += pos & -pos)
		bit[pos] += val;
}

int qry(int pos) {
	int res = 0;
	for(; pos; pos -= pos & -pos)
		res += bit[pos];
	return res;
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vi a(n);
		map<int, int> tt;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			if(i & 1) tt[a[i]]++;
			else tt[a[i]]--;
		}
		sort(ALL(a));
		for(int i = 0; i < n; i++) {
			if(i & 1) tt[a[i]]--;
			else tt[a[i]]++;
		}
		bool ans = true;
		for(int i = 0; i < n; i++)
			if(tt[a[i]])
				ans = false;
		cout << (ans ? "YES" : "NO") << '\n';
	}

}