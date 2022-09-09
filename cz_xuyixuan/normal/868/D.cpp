#include<bits/stdc++.h>
using namespace std;
#define MAXN	205
#define MAXK	11
#define MAXM	4096
struct Trie {
	int size, root;
	int child[MAXM][2], depth[MAXM];
	bool endpoint[MAXM];
	string start;
	void init(string &s) {
		size = root = 0;
		start = "";
		for (unsigned i = 0; i < s.length(); i++) {
			if (i < MAXK) start += s[i];
			int now = 0;
			for (unsigned j = i; j < s.length(); j++) {
				if (depth[now] == MAXK) break;
				if (child[now][s[j] - '0'] == 0) child[now][s[j] - '0'] = ++size;
				depth[child[now][s[j] - '0']] = depth[now] + 1;
				now = child[now][s[j] - '0'];
			}
			if (depth[now] < MAXK) endpoint[now] = true;
		}
	}
} T[MAXN];
int now, goal, cnt[MAXN];
string nowstart;
void print(int pos, string s) {
	cout << s << endl;
	if (T[now].child[pos][0]) print(T[now].child[pos][0], s + '0');
	if (T[now].child[pos][1]) print(T[now].child[pos][1], s + '1');
}
void work(int pos) {
	if (T[now].child[pos][0]) work(T[now].child[pos][0]);
	if (T[now].child[pos][1]) work(T[now].child[pos][1]);
	if (T[now].endpoint[pos]) {
		T[now].endpoint[pos] = false;
		int Now = pos;
		for (unsigned j = 0; j < nowstart.length(); j++) {
			if (T[now].depth[Now] == MAXK) break;
			if (T[now].child[Now][nowstart[j] - '0'] == 0) T[now].child[Now][nowstart[j] - '0'] = ++T[now].size;
			T[now].depth[T[now].child[Now][nowstart[j] - '0']] = T[now].depth[Now] + 1;
			Now = T[now].child[Now][nowstart[j] - '0'];
		}
		if (T[now].depth[Now] < MAXK) T[now].endpoint[Now] = true;
	}
}
void work(int x, int y, int dep) {
	if (T[goal].child[y][0]) {
		if (T[now].child[x][0] == 0) {
			T[now].child[x][0] = ++T[now].size;
			T[now].depth[T[now].size] = dep + 1;
		}
		work(T[now].child[x][0], T[goal].child[y][0], dep + 1);
	}
	if (T[goal].child[y][1]) {
		if (T[now].child[x][1] == 0) {
			T[now].child[x][1] = ++T[now].size;
			T[now].depth[T[now].size] = dep + 1;
		}
		work(T[now].child[x][1], T[goal].child[y][1], dep + 1);
	}
	T[now].endpoint[x] |= T[goal].endpoint[y];
}
void Combine(Trie &x, Trie &y) {
	x.start += y.start;
	if (x.start.length() > MAXK) x.start.resize(MAXK);
	nowstart = y.start;
	//print(0, "");
	work(0);
	//print(0, "");
	work(0, 0, 0);
	//print(0, "");
}
void dfs(int pos) {
	if (T[now].child[pos][0]) dfs(T[now].child[pos][0]);
	if (T[now].child[pos][1]) dfs(T[now].child[pos][1]);
	cnt[T[now].depth[pos]]++;
}
int Getans() {
	memset(cnt, 0, sizeof(cnt));
	dfs(0);
	int ans = 0;
	for (int i = 1; i <= MAXK; i++)
		if (cnt[i] == 1 << i) ans = i;
	return ans;
}
void debug() {
	int a = 10;
}
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		T[i].init(s);
	}
	int m; cin >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		T[i + n] = T[x];
		now = i + n; goal = y;
		if (i == 3) debug();
		Combine(T[now], T[goal]);
		cout << Getans() << endl;
		//print(0, "");
		//cout << endl;
	}
	return 0;
}