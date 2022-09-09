#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int MAXM = 5e3 + 5;
const int INF  = 1e9;
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
int tot, cnt, prime[MAXN], f[MAXN];
int dist[MAXM][MAXM], realnum[MAXN];
int factors[MAXM];
map <int, int> st; vector <int> pos;
map <vector <int>, int> num;
vector <int> a[MAXM];
void bfs(int from) {
	static int dis[MAXM], q[MAXM];
	memset(dis, -1, sizeof(dis));
	dis[from] = 0, q[0] = from;
	int l = 0, r = 0;
	while (l <= r) {
		int pos = q[l++];
		for (auto x : a[pos])
			if (dis[x] == -1) {
				dis[x] = dis[pos] + 1;
				q[++r] = x;
			}
	}
	for (unsigned i = 1; i <= pos.size(); i++)
		dist[from][i] = 1e9;
	for (int i = 1; i <= cnt; i++)
		chkmin(dist[from][factors[i]], dis[i]);
}
void sieve(int n) {
	for (int i = 2; i <= n; i++) {
		if (f[i] == 0) prime[++tot] = f[i] = i;
		for (int j = 1; j <= tot && prime[j] <= f[i]; j++) {
			int tmp = prime[j] * i;
			if (tmp > n) break;
			f[tmp] = prime[j];
		}
	}
	for (int i = 1; i <= n; i++) {
		int tmp = i;
		vector <int> now;
		now.clear();
		while (tmp != 1) {
			int val = f[tmp], vbl = 0;
			while (tmp % val == 0) {
				vbl++;
				tmp /= val;
			}
			now.push_back(vbl);
		}
		sort(now.begin(), now.end(), [&] (int x, int y) {return x > y; });
		int res = 1;
		for (unsigned j = 0; j < now.size(); j++) {
			for (int k = 1; k <= now[j]; k++)
				res *= prime[j + 1];
		}
		realnum[i] = res;
		if (i == res) bfs(num[now]);
		realnum[i] = num[now];
	}
}
void work(int sum, int k, vector <int> tmp) {
	if (sum == 0) {
		int fac = 1;
		for (auto x : tmp)
			fac *= x + 1;
		if (!st.count(fac)) {
			pos.push_back(fac);
			st[fac] = pos.size();
		}
		num[tmp] = ++cnt;
		factors[cnt] = st[fac];
		for (unsigned i = 0; i < tmp.size(); i++) {
			vector <int> tnp = tmp;
			tnp[i]++; sort(tnp.begin(), tnp.end(), [&] (int x, int y) {return x > y; });
			if (num.count(tnp)) {
				int dest = num[tnp];
				a[dest].push_back(cnt);
				a[cnt].push_back(dest);
			}
			tnp = tmp, tnp[i]--;
			sort(tnp.begin(), tnp.end(), [&] (int x, int y) {return x > y; });
			if (tnp.size() != 0 && tnp.back() == 0) tnp.pop_back();
			if (num.count(tnp)) {
				int dest = num[tnp];
				a[dest].push_back(cnt);
				a[cnt].push_back(dest);
			}
		}
		tmp.push_back(1);
		if (num.count(tmp)) {
			int dest = num[tmp];
			a[dest].push_back(cnt);
			a[cnt].push_back(dest);
		}
		return;
	}
	if (k >= 2) work(sum, k - 1, tmp);
	tmp.push_back(k);
	if (sum >= k) work(sum - k, k, tmp);
}
int main() {
	//freopen("1071D.in", "r", stdin);
	//freopen("1071D.out", "w", stdout);
	for (int i = 0; i <= 22; i++)
		work(i, i, vector <int> {});
	sieve(1e6);
	int T; read(T);
	while (T--) {
		int l, r; read(l), read(r);
		l = realnum[l], r = realnum[r];
		int ans = 1e9;
		for (unsigned i = 1; i <= pos.size(); i++)
			chkmin(ans, dist[l][i] + dist[r][i]);
		printf("%d\n", ans);
	}
	return 0;
}