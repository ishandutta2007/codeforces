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

const int INF = 1e9 + 7, N = 1e6 + 7;

int a[N], lp[N];
int n;

multiset<int> ms;

struct DS {
	V<pi> tt; // pos val
	int lz, ans;
	DS() {
		lz = 0, ans = -1;
	}
	void undo() {
		if(ans != -1)
			ms.erase(ms.find(ans));
	}

	void godo() {
		if(tt.empty()) ans = n;
		else ans = tt.back().F;
		ms.insert(ans);
	}

	void upd(int pos, int op) {
		undo();
		tt.EB(pos, -lz);
		lz += op;
		while(tt.size() && tt.back().S + lz >= 0)
			tt.pop_back();
		godo();
	}
} ds[N];

ll ans;

signed main()
{
	IO_OP;
	
	for(int i = 2; i < N; i++) {
		if(lp[i]) continue;
		lp[i] = i;
		for(int j = 2 * i; j < N; j += i)
			lp[j] = i;
	}

	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	string s;
	cin >> s;

	ans = 0;
	ms.insert(n);

	auto upd = [&] (int x, int pos, int op) {
		while(x != 1) {
			int p = lp[x];
			int p_cnt = 0;
			while(x % p == 0) {
				p_cnt++;
				x /= lp[x];
			}
			ds[p].upd(pos, op * p_cnt);
		}
	};

	for(int i = n - 1; i >= 0; i--) {
		if(a[i] == 1)
			s[i] = '*';
		if(s[i] == '*')
			upd(a[i], i, 1);
		else
			upd(a[i], i, -1);
		ans += *ms.begin() - i;
	}
	cout << ans << '\n';

}