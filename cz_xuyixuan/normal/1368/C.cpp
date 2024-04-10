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
int main() {
	int n; read(n);
	vector <pair <int, int>> ans;
	for (int i = 0; i <= n + 1; i++)
		ans.emplace_back(i, i);
	for (int i = 0; i <= n; i++) {
		ans.emplace_back(i, i + 1);
		ans.emplace_back(i + 1, i);
	}
	cout << ans.size() << endl;
	for (auto x : ans) printf("%d %d\n", x.first, x.second);
	return 0;
}