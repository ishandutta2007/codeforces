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
int main() {
	read(n);
	vector <pair <int, int>> ans;
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++) {
		vector <int> p;
		for (int j = i + 1; j <= n; j++)
			if (a[j] < a[i]) p.push_back(j);
		sort(p.begin(), p.end(), [&] (int x, int y) {
			if (a[x] != a[y]) return a[x] > a[y];
			else return x > y;
		});
		for (auto x : p) ans.emplace_back(i, x);
	}
	cout << ans.size() << endl;
	for (auto x : ans) printf("%d %d\n", x.first, x.second);
	return 0;
}