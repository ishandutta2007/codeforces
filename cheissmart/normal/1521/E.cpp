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
		int m, k;
		cin >> m >> k;
		vi a(k);
		for(int& i:a) cin >> i;
		int mx = *max_element(ALL(a));
		int lb = 1, rb = 1e5;
		while(lb <= rb) {
			int mb = (lb + rb) / 2;
			if(m <= (ll) mb * mb - (ll) (mb / 2) * (mb / 2) &&
			   mx <= (ll) mb * ((mb + 1) / 2))
				rb = mb - 1;
			else 
				lb = mb + 1;
		}
		cout << lb << '\n';
		vi aux;
		for(int i = 0; i < k; i++) if(a[i] != mx) {
			for(int j = 0; j < a[i]; j++)
				aux.PB(i + 1);
		}
		for(int i = 0; i < k; i++) if(a[i] == mx) {
			for(int j = 0; j < a[i]; j++)
				aux.PB(i + 1);
		}
		V<vi> ans(lb, vi(lb));
		auto go = [&] (int i, int j) {
			if(aux.empty()) return;
			ans[i][j] = aux.back();
			aux.pop_back();
		};
		for(int i = 0; i < lb; i += 2)
			for(int j = 1; j < lb; j += 2)
				go(i, j);
		for(int i = 0; i < lb; i += 2)
			for(int j = 0; j < lb; j += 2)
				go(i, j);
		for(int i = 1; i < lb; i += 2)
			for(int j = 0; j < lb; j += 2)
				go(i, j);
		assert(aux.empty());

		for(int i = 0; i < lb; i++)
			for(int j = 0; j < lb; j++)
				cout << ans[i][j] << " \n"[j == lb - 1];
	}

}