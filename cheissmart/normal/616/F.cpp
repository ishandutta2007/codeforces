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

const int INF = 1e9 + 7, N = 1e6 + 7;
struct Suffix_Array {
	vi s;
	int n;
	vi sa, a, rank, cnt, lcp;
	void build_a() {
		unordered_map<int, int> mp;
		vi t = s;
		sort(ALL(t));
		t.resize(unique(ALL(t)) - t.begin());
		for(int i = 0; i < t.size(); i++) mp[t[i]] = i;
		for(int i = 0; i < n; i++) a[i] = mp[s[i]];
	}
	void init(vi _s) {
		s =  _s;
		n = s.size();
		sa.resize(n), a.resize(n), rank.resize(n), cnt.resize(n), lcp.resize(n);
		build_a();
	}
	void build() {
		for(int i = 0; i < n; i++) cnt[rank[i] = a[i]]++;
		for(int i = 1; i < n; i++) cnt[i] += cnt[i - 1];
		for(int i = n - 1; i >= 0; i--) sa[--cnt[rank[i]]] = i;
		for(int k = 1; k < n; k *= 2) {
			// sort by second half
			vi sa2;
			for(int i = n - k; i < n; i++) sa2.PB(i);
			for(int i = 0; i < n; i++) if(sa[i] >= k) sa2.PB(sa[i] - k);
			// sort by the first half
			for(int i = 0; i < n; i++) cnt[i] = 0;
			for(int i = 0; i < n; i++) cnt[rank[i]]++;
			for(int i = 1; i < n; i++) cnt[i] += cnt[i - 1];
			for(int i = n - 1; i >= 0; i--) sa[--cnt[rank[sa2[i]]]] = sa2[i];
			// build rank
			auto cmp = [&](int a, int b) {
				if(rank[a] != rank[b]) return rank[a] < rank[b];
				int rankaa = -1, rankbb = -1;
				if(a + k < n) rankaa = rank[a + k];
				if(b + k < n) rankbb = rank[b + k];
				return rankaa < rankbb;
			};
			vi nw_rank(n);
			int cur = 0;
			for(int i = 0; i < n; i++) {
				if(i && cmp(sa[i - 1], sa[i])) cur++;
				nw_rank[sa[i]] = cur;
			}
			rank = nw_rank;
		}
	}
	void build_lcp() {
		int k = 0;
		for(int i = 0; i < n; i++) {
			if(k) k--;
			if(rank[i] == n - 1) continue;
			while(i + k < n && sa[rank[i] + 1] + k < n && s[i + k] == s[sa[rank[i] + 1] + k])
				k++;
			lcp[rank[i] + 1] = k;
		}
	}
} sa;

int which[N], l[N], r[N];
ll psum[N];
int end_point[N];

signed main()
{
	IO_OP;

	memset(which, -1, sizeof which);

	int cnt = 30;
	int n;
	cin >> n;
	vi s, sz;
	for(int i = 0; i < n; i++) {
		if(i) s.PB(cnt++);
		string t;
		cin >> t;
		for(char c:t) {
			which[s.size()] = i;
			s.PB(c - 'a');
		}
		end_point[i] = s.size() - 1;
		sz.PB(t.size());
	} 
	vi c(n);
	ll ans = 0;
	for(int i = 0; i < n; i++)
		cin >> c[i];
	sa.init(s);
	sa.build();
	sa.build_lcp();
	for(int i = 0; i < sa.n; i++) {
		if(which[sa.sa[i]] == -1) continue;
		int len = end_point[which[sa.sa[i]]] - sa.sa[i] + 1;
		if(i && sa.lcp[i] >= len) continue;
		if(i + 1 < sa.n && sa.lcp[i + 1] >= len) continue;
		ans = max(ans, (ll) c[which[sa.sa[i]]] * len);
	}
	for(int i = 0; i < sa.n; i++) {
		if(which[sa.sa[i]] != -1)
			psum[i] = c[which[sa.sa[i]]];
		if(i) psum[i] += psum[i - 1];
	}
	for(int i = 1; i < sa.n; i++) {
		l[i] = i - 1;
		while(l[i] != 0 && sa.lcp[l[i]] >= sa.lcp[i]) l[i] = l[l[i]];
	}
	for(int i = sa.n - 1; i >= 1; i--) {
		r[i] = i + 1;
		while(r[i] != sa.n && sa.lcp[r[i]] >= sa.lcp[i]) r[i] = r[r[i]];
	}
	for(int i = 1; i < sa.n; i++) {
		int mn = sa.lcp[i];
		int L = l[i], R = r[i];
		ll sum = psum[R - 1] - (L - 1 >= 0 ? psum[L - 1] : 0LL);
		ans = max(ans, sum * mn);
	}
	cout << ans << '\n';

}