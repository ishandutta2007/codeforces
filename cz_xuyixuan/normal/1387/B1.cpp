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
vector <int> a[MAXN];
int n, ans, match[MAXN];
void work(int pos, int fa) {
	for (auto x : a[pos])
		if (x != fa) work(x, pos);
	if (match[pos] == pos) {
		ans += 2;
		if (fa == 0) swap(match[pos], match[a[pos][0]]);
		else swap(match[pos], match[fa]);
	}
}
int main() {
	read(n);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		match[i] = i;
	work(1, 0);
	cout << ans << endl;
	for (int i = 1; i <= n; i++)
		printf("%d ", match[i]);
	printf("\n");
	return 0;
}