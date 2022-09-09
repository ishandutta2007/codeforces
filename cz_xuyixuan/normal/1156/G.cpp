#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXM = 13252491;
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
set <int> processed;
map <pair <int, pair <int, int>>, int> mp;
bool vis[MAXM]; vector <string> ans;
int n, opt[MAXN], res[MAXN], l[MAXN], r[MAXN];
int now[MAXM]; pair <int, pair <int, int>> d[MAXN];
int ctoi(char c) {
	if (c >= 'a' && c <= 'z') return c - 'a' + 1;
	if (c >= 'A' && c <= 'Z') return c - 'A' + 27;
	if (c >= '0' && c <= '9') return c - '0' + 53;
	assert(false);
	return -1;
}
int itoc(int x) {
	if (x >= 1 && x <= 26) return x - 1 + 'a';
	if (x >= 27 && x <= 52) return x - 27 + 'A';
	if (x >= 53 && x <= 62) return x - 53 + '0';
	assert(false);
	return -1;
}
string itos(int x) {
	string res;
	while (x != 0) {
		res.insert(res.begin(), itoc(x % 63));
		x /= 63;
	}
	return res;
}
void work(int pos, int goal) {
	if (vis[pos] || processed.count(pos)) return;
	work(d[pos].second.first, 0);
	work(d[pos].second.second, 0);
	string res = "";
	if (goal != 0) res = res + itos(goal);
	else res = res + itos(pos);
	res.push_back('=');
	res = res + itos(d[pos].second.first);
	if (d[pos].first == 1) res.push_back('#');
	if (d[pos].first == 2) res.push_back('$');
	if (d[pos].first == 3) res.push_back('^');
	if (d[pos].first == 4) res.push_back('&');
	res = res + itos(d[pos].second.second);
	ans.push_back(res);
	processed.insert(pos);
}
bool invalid(int x) {
	while (x >= 63) {
		if (x % 63 == 0) return true;
		x /= 63;
	}
	return x >= 53;
}
int main() {
	read(n);
	int goal = ctoi('r') * 63 * 63 + ctoi('e') * 63 + ctoi('s');
	for (int i = 1; i <= n; i++) {
		char s[25]; scanf("\n%s", s + 1);
		int len = strlen(s + 1), p = 0, q = 0;
		for (int j = 1; j <= len; j++) {
			if (s[j] == '=') p = j;
			if (s[j] == '#' || s[j] == '$' || s[j] == '^' || s[j] == '&') q = j;
		}
		for (int j = 1; j <= p - 1; j++)
			res[i] = res[i] * 63 + ctoi(s[j]);
		if (q == 0) {
			opt[i] = 0;
			for (int j = p + 1; j <= len; j++)
				l[i] = l[i] * 63 + ctoi(s[j]);
		} else {
			if (s[q] == '#') opt[i] = 1;
			if (s[q] == '$') opt[i] = 2;
			if (s[q] == '^') opt[i] = 3;
			if (s[q] == '&') opt[i] = 4;
			for (int j = p + 1; j <= q - 1; j++)
				l[i] = l[i] * 63 + ctoi(s[j]);
			for (int j = q + 1; j <= len; j++)
				r[i] = r[i] * 63 + ctoi(s[j]);
		}
		vis[l[i]] = vis[r[i]] = vis[res[i]] = true;
		now[l[i]] = l[i], now[r[i]] = r[i];
		now[res[i]] = res[i];
	}
	if (!vis[goal]) {
		puts("0");
		return 0;
	}
	int point = 1;
	for (int i = 1; i <= n; i++) {
		while (invalid(point) || vis[point]) point++;
		if (opt[i] == 0) now[res[i]] = now[l[i]];
		else {
			pair <int, pair <int, int>> tmp = make_pair(opt[i], make_pair(now[l[i]], now[r[i]]));
			if (mp.count(tmp)) now[res[i]] = mp[tmp];
			else {
				d[point] = tmp, mp[tmp] = point;
				now[res[i]] = point++;
			}
		}
	}
	if (vis[now[goal]] && now[goal] != goal) {
		string res = "";
		res = res + itos(goal);
		res.push_back('=');
		res = res + itos(now[goal]);
		ans.push_back(res);
	}
	work(now[goal], goal);
	writeln(ans.size());
	for (auto x : ans) cout << x << endl;
	return 0;
}