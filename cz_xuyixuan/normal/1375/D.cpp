#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
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
int n, a[MAXN];
int cur() {
	static int vis[MAXN], tag = 0; tag++;
	for (int i = 1; i <= n; i++)
		vis[a[i]] = tag;
	int ans = 0;
	while (vis[ans] == tag) ans++;
	return ans;
}
bool check() {
	for (int i = 2; i <= n; i++)
		if (a[i - 1] > a[i]) return false;
	return true;
}
int main() {
	int T; read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++)
			read(a[i]);
		vector <int> ans;
		while (!check()) {
			int val = cur();
			if (val != n) {
				a[val + 1] = val;
				ans.push_back(val + 1);
			} else {
				int pos = 0;
				for (int i = 1; i <= n; i++)
					if (a[i] != i - 1) pos = i;
				a[pos] = val;
				ans.push_back(pos);
			}
		}
		cout << ans.size() << endl;
		for (auto x : ans) printf("%d ", x);
		printf("\n");
	}
	return 0;
}