#include<bits/stdc++.h>
using namespace std;
const int MAXN = 8505;
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
vector <int> a[MAXN]; bool vis[MAXN];
int n, root, p[MAXN], q[MAXN], res[MAXN];
int main() {
	int T; read(T);
	while (T--) {
		read(n); int m = n;
		for (int i = 1; i <= n; i++)
			read(p[i]);
		for (int v = 1; m != 0; v++) {
			set <int> st;
			for (int i = 1; i <= m; i++) {
				a[p[i]].clear();
				vis[p[i]] = false;
			}
			for (int i = 1; i <= m; i++) {
				auto tmp = st.insert(p[i]).first;
				auto suf = tmp; suf++;
				if (suf != st.end()) a[p[i]].push_back(*suf);
				if (tmp != st.begin()) {
					auto pre = tmp; pre--;
					a[p[i]].push_back(*pre);
				}
			}
			int tm = 0;
			for (int i = m; i >= 1; i--)
				if (!vis[p[i]]) {
					res[p[i]] = v;
					for (auto x : a[p[i]]) vis[x] = true;
				} else q[++tm] = p[i];
			m = tm;
			for (int i = 1; i <= m; i++)
				p[i] = q[m - i + 1];
		}
		for (int i = 1; i <= n; i++)
			printf("%d ", res[i]);
		printf("\n");
	}
	return 0;
}