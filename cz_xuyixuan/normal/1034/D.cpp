#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
const int INF = 1e9;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
struct info {int l, r, val; };
bool operator < (info a, info b) {return a.l < b.l; }
multiset <info> st;
int n, k, l[MAXN], r[MAXN];
vector <pair <int, int> > a[MAXN];
int cnt(int mid) {
	static int add[MAXN];
	memset(add, 0, sizeof(add));
	int ans = 0, l = 1, now = 0;
	for (int i = 1; i <= n; i++) {
		unsigned j = 0;
		while (j < a[i].size() && a[i][j].first <= l) now += a[i][j++].second;
		while (l <= i && now >= mid) {
			now += add[++l];
			while (j < a[i].size() && a[i][j].first <= l) now += a[i][j++].second;
		}
		ans += l - 1;
		while (j < a[i].size()) add[a[i][j].first] += a[i][j].second, j++;
		if (ans > INF) return INF;
	}
	return ans;
}
ll sum(int mid) {
	static int add[MAXN];
	memset(add, 0, sizeof(add));
	ll ans = 0; int l = 1, now = 0;
	for (int i = 1; i <= n; i++) {
		unsigned j = 0;
		while (j < a[i].size() && a[i][j].first <= l) {
			ans += (n - i + 1ll) * (l - a[i][j].first + 0ll) * a[i][j].second;
			now += a[i][j++].second;
		}
		while (l <= i && now >= mid) {
			ans += now * (n - i + 1ll);
			now += add[++l];
			while (j < a[i].size() && a[i][j].first <= l) now += a[i][j++].second;
		}
		while (j < a[i].size()) add[a[i][j].first] += a[i][j].second, j++;
	}
	return ans;
}
int main() {
	//freopen("1034D.in", "r", stdin);
	//freopen("1034D.out", "w", stdout);
	read(n), read(k);
	for (int i = 1; i <= n; i++)
		read(l[i]), read(r[i]), r[i]--;
	st.insert((info) {1, INF, 0});
	for (int i = 1; i <= n; i++) {
		int ql = l[i], qr = r[i], lv = i, rv = i;
		info now = (info) {l[i], r[i], i};
		multiset <info> :: iterator tmp = st.upper_bound(now);
		if (--tmp != st.end()) {
			ql = (*tmp).l;
			lv = (*tmp).val;
		}
		while (tmp != st.end() && (*tmp).l <= r[i]) {
			if ((*tmp).r >= r[i]) {
				qr = (*tmp).r;
				rv = (*tmp).val;
			}
			multiset <info> :: iterator tnp = tmp;
			a[i].push_back(make_pair((*tmp).val + 1, (*tmp).r - (*tmp).l + 1));
			tmp++; st.erase(tnp);
		}
		if (ql != l[i]) {
			st.insert((info) {ql, l[i] - 1, lv});
			a[i].push_back(make_pair(lv + 1, -(l[i] - ql)));
		}
		if (qr != r[i]) {
			st.insert((info) {r[i] + 1, qr, rv});
			a[i].push_back(make_pair(rv + 1, -(qr - r[i])));
		}
		st.insert((info) {l[i], r[i], i});
		a[i].push_back(make_pair(i + 1, -(r[i] - l[i] + 1)));
		sort(a[i].begin(), a[i].end());
		//for (unsigned j = 0; j < a[i].size(); j++)
		//	printf("%d %d\n", a[i][j].first, a[i][j].second);
		//printf("\n");
	}
	int l = 1, r = 1e9;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (cnt(mid) >= k) l = mid;
		else r = mid - 1;
	}
	ll ans = 1ll * l * (k - cnt(l + 1));
	writeln(ans + sum(l + 1));
	return 0;
}