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
map <int, ll> sum;
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		sum[x - i] += x;
	}
	ll ans = 0;
	for (auto x : sum) {
		chkmax(ans, x.second);
	}
	cout << ans << endl;
	return 0;
}