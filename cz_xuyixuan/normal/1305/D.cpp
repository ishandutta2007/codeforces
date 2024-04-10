#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
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
bool res[MAXN]; int vis[MAXN], task;
int n; vector <int> a[MAXN];
void erase(vector <int> &a, int x) {
	for (unsigned i = 0; i < a.size(); i++)
		if (a[i] == x) {
			swap(a[i], a[a.size() - 1]);
			a.pop_back();
			return;
		}
}
int cntres() {
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		cnt += res[i];
	return cnt;
}
void col(int pos, int fa) {
	vis[pos] = task;
	for (auto x : a[pos])
		if (x != fa) col(x, pos);
}
void dres(int pos, int fa) {
	res[pos] = false;
	for (auto x : a[pos])
		if (x != fa) dres(x, pos);
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		res[i] = true;
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	while (cntres() != 1) {
		int x = 0, y = 0;
		for (int i = 1; i <= n; i++)
			if (res[i] && a[i].size() == 1) {
				y = x;
				x = i;
			}
		assert(x != 0 && y != 0);
		cout << '?' << ' ' << x << ' ' << y << endl;
		int z, rx = 0, ry = 0; read(z);
		if (z == x || z == y) {
			cout << '!' << ' ' << z << endl;
			return 0;
		}
		for (auto p : a[z]) {
			task++;
			col(p, z);
			if (vis[x] == task) rx = p;
			if (vis[y] == task) ry = p;
		}
		erase(a[z], rx);
		erase(a[z], ry);
		dres(rx, z), dres(ry, z);
	}
	for (int i = 1; i <= n; i++)
		if (res[i] == true) {
			cout << '!' << ' ' << i << endl;
			return 0;
		}
	return 0;
}