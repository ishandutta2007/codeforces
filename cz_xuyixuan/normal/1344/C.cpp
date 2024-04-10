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
char res[MAXN];
int n, m, d[MAXN];
bool visa[MAXN], visb[MAXN];
vector <int> a[MAXN], b[MAXN];
void dfsa(int pos) {
	visa[pos] = true;
	for (auto x : a[pos])
		if (!visa[x]) dfsa(x);
}
void dfsb(int pos) {
	visb[pos] = true;
	for (auto x : b[pos])
		if (!visb[x]) dfsb(x);
}
bool loop() {
	static int q[MAXN]; int l = 1, r = 0;
	for (int i = 1; i <= n; i++)
		if (d[i] == 0) q[++r] = i;
	while (l <= r) {
		int pos = q[l++];
		for (auto x : a[pos])
			if (--d[x] == 0) q[++r] = x;
	}
	return r != n;
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y), d[y]++;
		b[y].push_back(x);
	}
	if (loop()) {
		puts("-1");
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!visa[i] && !visb[i]) res[i] = 'A', ans++;
		else res[i] = 'E';
		dfsa(i), dfsb(i);
	}
	cout << ans << endl;
	printf("%s\n", res + 1);
	return 0;
}