#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
namespace SuffixArray {
	const int MAXN = 100005;
	const int MAXLOG = 18;
	const int MAXC = 256; 
	int sa[MAXN], rnk[MAXN], height[MAXN];
	int Min[MAXN][MAXLOG], bit[MAXN], N;
	void init(char *a, int n) {
		N = n, a[n + 1] = 0;
		for (int i = 0; i <= n + 1; i++)
			sa[i] = rnk[i] = 0;
		static int x[MAXN], y[MAXN], cnt[MAXN], rk[MAXN];
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++)
			cnt[(int) a[i]]++;
		for (int i = 1; i <= MAXC; i++)
			cnt[i] += cnt[i - 1];
		for (int i = n; i >= 1; i--)
			sa[cnt[(int) a[i]]--] = i;
		rnk[sa[1]] = 1;
		for (int i = 2; i <= n; i++)
			rnk[sa[i]] = rnk[sa[i - 1]] + (a[sa[i]] != a[sa[i - 1]]);
		for (int k = 1; rnk[sa[n]] != n; k <<= 1) {
			for (int i = 1; i <= n; i++) {
				x[i] = rnk[i];
				y[i] = (i + k <= n) ? rnk[i + k] : 0;
			}
			memset(cnt, 0, sizeof(cnt));
			for (int i = 1; i <= n; i++)
				cnt[y[i]]++;
			for (int i = 1; i <= n; i++)
				cnt[i] += cnt[i - 1];
			for (int i = n; i >= 1; i--)
				rk[cnt[y[i]]--] = i;
			memset(cnt, 0, sizeof(cnt));
			for (int i = 1; i <= n; i++)
				cnt[x[i]]++;
			for (int i = 1; i <= n; i++)
				cnt[i] += cnt[i - 1];
			for (int i = n; i >= 1; i--)
				sa[cnt[x[rk[i]]]--] = rk[i];
			rnk[sa[1]] = 1;
			for (int i = 2; i <= n; i++)
				rnk[sa[i]] = rnk[sa[i - 1]] + (x[sa[i]] != x[sa[i - 1]] || y[sa[i]] != y[sa[i - 1]]);		
		}
		int now = 0;
		for (int i = 1; i <= n; i++) {
			if (now) now--;
			while (a[i + now] == a[sa[rnk[i] + 1] + now]) now++;
			height[rnk[i]] = now;
		}
		for (int i = 1; i <= n; i++)
			Min[i][0] = height[i];
		for (int p = 1; p < MAXLOG; p++) {
			int tmp = 1 << (p - 1);
			for (int i = 1, j = tmp + 1; j <= n; i++, j++)
				Min[i][p] = min(Min[i][p - 1], Min[i + tmp][p - 1]);
		}
		for (int i = 1; i <= n; i++) {
			bit[i] = bit[i - 1];
			if (i >= 1 << (bit[i] + 1)) bit[i]++;
		}
	}
	int lcp(int x, int y) {
		if (x == y) return N - x + 1;
		x = rnk[x], y = rnk[y];
		if (x > y) swap(x, y);
		int tmp = bit[y - x];
		return min(Min[x][tmp], Min[y - (1 << tmp)][tmp]);
	}
}
int n, type; char s[MAXN]; ll ans;
struct info {int x; };
int lcp(info a, info b) {
	assert(a.x + type <= n + 1 && b.x + type <= n + 1);
	if (a.x + type <= n && b.x + type <= n) return SuffixArray :: lcp(a.x + type, b.x + type);
	else return 0;
}
int dist(info a, info b) {
	int tmp = lcp(a, b);
	return n + 1 - (a.x + type) + n + 1 - (b.x + type) - 2 * tmp;
}
bool operator < (info a, info b) {
	int tmp = lcp(a, b);
	return s[a.x + type + tmp] < s[b.x + type + tmp];
}
struct SuffixSet {
	set <info> st; int key; ll size;
	void debug() {
		for (auto x : st)
			cerr << x.x << ' ';
		cerr << '(' << size << ')' << endl;
	}
	void ins(info a) {
		type = key;
		auto tmp = st.insert(a).first;
		auto suf = tmp; suf++;
		if (suf != st.end()) {
			size += dist(*tmp, *suf);
			if (tmp != st.begin()) {
				auto pre = tmp; pre--;
				size -= dist(*pre, *suf);
				size += dist(*pre, *tmp);
			}
		} else if (tmp != st.begin()) {
			auto pre = tmp; pre--;
			size += dist(*pre, *tmp);
		}
	}
	void del(info a) {
		type = key;
		auto tmp = st.lower_bound(a);
		auto suf = tmp; suf++;
		if (suf != st.end()) {
			size -= dist(*tmp, *suf);
			if (tmp != st.begin()) {
				auto pre = tmp; pre--;
				size += dist(*pre, *suf);
				size -= dist(*pre, *tmp);
			}
		} else if (tmp != st.begin()) {
			auto pre = tmp; pre--;
			size -= dist(*pre, *tmp);
		}
		st.erase(tmp);
	}
	ll query() {
		type = key;
		if (st.size() == 0) return 0;
		auto pre = st.begin(), suf = st.end(); suf--;
		return (dist(*pre, *suf) + size) / 2 + lcp(*pre, *suf) + 1;
	}
} SS[MAXN];
namespace SuffixAutomaton {
	const int MAXN = 2e5 + 5;
	const int MAXC = 26;
	int root, size, last;
	vector <int> a[MAXN];
	int fail[MAXN], depth[MAXN];
	int child[MAXN][MAXC], key[MAXN];
	int newnode(int dep) {
		fail[size] = 0;
		depth[size] = dep;
		memset(child[size], 0, sizeof(child[size]));
		return size++;
	}
	void extend(int ch, int from) {
		int p = last, np = newnode(depth[last] + 1);
		while (child[p][ch] == 0) {
			child[p][ch] = np;
			p = fail[p];
		}
		if (child[p][ch] == np) fail[np] = root;
		else {
			int q = child[p][ch];
			if (depth[q] == depth[p] + 1) fail[np] = q;
			else {
				int nq = newnode(depth[p] + 1);
				fail[nq] = fail[q];
				fail[q] = fail[np] = nq;
				memcpy(child[nq], child[q], sizeof(child[q]));
				while (child[p][ch] == q) {
					child[p][ch] = nq;
					p = fail[p];
				}
			}
		}
		key[last = np] = from;
	}
	void init(char *s) {
		size = 0;
		root = last = newnode(0);
		int len = strlen(s + 1);
		for (int i = len; i >= 1; i--)
			extend(s[i] - 'a', i);
		ans = 1;
		for (int i = 1; i < size; i++) {
			a[fail[i]].push_back(i);
			ans += depth[i] - depth[fail[i]];
		}
	}
	int sz[MAXN], son[MAXN]; ll endpoints[MAXN];
	void dfs(int pos) {
		endpoints[pos] = 1;
		sz[pos] = key[pos] != 0;
		for (auto x : a[pos]) {
			dfs(x); sz[pos] += sz[x];
			endpoints[pos] += endpoints[x] + depth[x] - depth[pos] - 1;
			if (son[pos] == 0 || sz[x] > sz[son[pos]]) son[pos] = x;
		}
	}
	ll func(int x) {
		return (x - 1ll) * x / 2;
	}
	void work(int pos) {
		if (son[pos]) {
			work(son[pos]);
			swap(SS[pos], SS[son[pos]]);
			ans += endpoints[son[pos]] * (depth[son[pos]] - depth[pos] - 1);
			ans += func(depth[son[pos]] - depth[pos] - 1);
		}
		SS[pos].key = depth[pos] + 1;
		for (auto x : a[pos])
			if (x != son[pos]) {
				work(x);
				ans += endpoints[x] * (depth[x] - depth[pos] - 1);
				ans += func(depth[x] - depth[pos] - 1);
				type = SS[x].key;
				vector <info> tmp;
				for (auto y : SS[x].st)
					tmp.push_back(y);
				for (auto y : tmp)
					SS[pos].ins(y);
			}
		ans += SS[pos].query();
		for (auto x : a[pos])
			if (x != son[pos]) {
				type = SS[x].key;
				vector <info> tmp;
				for (auto y : SS[x].st)
					tmp.push_back(y);
				for (auto y : tmp)
					SS[pos].del(y);
			}
		SS[pos].key = depth[pos];
		if (key[pos] != 0) SS[pos].ins((info) {key[pos]});
		for (auto x : a[pos])
			if (x != son[pos]) {
				type = SS[x].key;
				vector <info> tmp;
				for (auto y : SS[x].st)
					tmp.push_back(y);
				for (auto y : tmp)
					SS[pos].ins(y);
			}
	}
	void work() {
		dfs(root);
		work(root);
		cout << ans << endl;
	}
}
int main() {
	scanf("\n%s", s + 1);
	n = strlen(s + 1);
	SuffixArray :: init(s, n);
	SuffixAutomaton :: init(s);
	SuffixAutomaton :: work();
	return 0;
}