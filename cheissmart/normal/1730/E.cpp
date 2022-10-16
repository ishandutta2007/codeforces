#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
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

const int INF = 1e9 + 7, N = 5e5 + 7, C = 1e6 + 7;

int a[N], ls[N], rs[N], r[N], l[N], cnt[C];
vi divisor[C], pos[C];

void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		pos[a[i]].PB(i);
	}
	for(int i = 0; i < n; i++) {
		l[i] = i - 1;
		while(l[i] != -1 && a[l[i]] >= a[i])
			l[i] = l[l[i]];
		ls[i] = i - 1;
		while(ls[i] != -1 && a[ls[i]] < a[i])
			ls[i] = ls[ls[i]];
	}
	for(int i = n - 1; i >= 0; i--) {
		r[i] = i + 1;
		while(r[i] != n && a[r[i]] >= a[i])
			r[i] = r[r[i]];
		rs[i] = i + 1;
		while(rs[i] != n && a[rs[i]] <= a[i])
			rs[i] = rs[rs[i]];
	}
	memset(cnt, 0, sizeof cnt);
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		auto lpos = [&] (int j) {
			if(j == a[i]) return i;
			if(cnt[j] == 0) return -1;
			return pos[j][cnt[j] - 1];
		};
		auto rpos = [&] (int j) {
			if(j == a[i]) return i;
			if(cnt[j] == SZ(pos[j])) return n;
			return pos[j][cnt[j]];
		};
		for(int j:divisor[a[i]]) {
			if(lpos(j) >= 0) {
				int lb = max(ls[i] + 1, l[lpos(j)] + 1);
				int rb = min(rs[i] - 1, r[lpos(j)] - 1);
				if(lb <= lpos(j) && rb >= i) {
					ans += 1LL * (lpos(j) - lb + 1) * (rb - i + 1);
				}
			}
			if(rpos(j) < n) {
				int lb = max(ls[i] + 1, l[rpos(j)] + 1);
				int rb = min(rs[i] - 1, r[rpos(j)] - 1);
				if(lb <= i && rb >= rpos(j)) {
					ans += 1LL * (i - lb + 1) * (rb - rpos(j) + 1);
				}
			}
			if(lpos(j) >= 0 && rpos(j) < n) {
				int lb = max({ls[i] + 1, l[lpos(j)] + 1, l[rpos(j)] + 1});
				int rb = min({rs[i] - 1, r[lpos(j)] - 1, r[rpos(j)] - 1});
				if(lb <= lpos(j) && rb >= rpos(j)) {
					ans -= 1LL * (lpos(j) - lb + 1) * (rb - rpos(j) + 1);
				}
			}			
		}
		cnt[a[i]]++;
	}
	cout << ans << '\n';
	for(int i = 0; i < n; i++)
		pos[a[i]].clear();
}

signed main()
{
	IO_OP;

	for(int i = 1; i < C; i++)
		for(int j = i; j < C; j += i)
			divisor[j].PB(i);

	int t;
	cin >> t;
	while(t--)
		solve();
	
}