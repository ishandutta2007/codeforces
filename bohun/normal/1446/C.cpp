#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
// c0 3f
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 2e5 + 500;

int n;

int solve(int bit, vector <int> &a) {
	if (bit == 0 || a.empty()) return 0;
	vector <int> Left, Right;
	for (auto x : a) {
		if ((x >> bit) & 1) Left.pb(x);
		else Right.pb(x);
	}
	int ansl = solve(bit - 1, Left);
	int ansr = solve(bit - 1, Right);
	return min(ansl + max(0, sz(Right) - 1), ansr + max(0, sz(Left) - 1));
}
	
int main() {
	scanf("%d", &n);
	vector <int> a(n);
	rep(i, 0, n - 1) 
		scanf("%d", &a[i]);
	printf ("%d\n", solve(29, a));
	return 0;
}