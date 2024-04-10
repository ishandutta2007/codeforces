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
int n, Max; vector <int> a[MAXN];
vector <pair <int, int>> ans;
void dfs(int pos, int fa, int goal) {
	ans.emplace_back(pos, goal);
	vector <int> sons; int cur = goal;
	for (auto x : a[pos])
		if (x != fa) sons.push_back(x);
	for (unsigned i = 0; i < sons.size(); i++) {
		if (cur == Max) {
			int lft = sons.size() - i;
			ans.emplace_back(pos, cur = (goal - 1) - lft);
		}
		dfs(sons[i], pos, ++cur);
	}
	if (cur != goal - 1) ans.emplace_back(pos, goal - 1);
	ans.emplace_back(fa, goal);
}
int main() {
	read(n);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		if (a[i].size() > Max) Max = a[i].size();
	ans.emplace_back(1, 0);
	int cnt = 0;
	for (auto x : a[1])
		dfs(x, 1, ++cnt);
	cout << ans.size() << endl;
	for (auto x : ans) printf("%d %d\n", x.first, x.second);
	return 0;
}