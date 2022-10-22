#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;

int n, a, b;
int t[2005];

void solve() {
	scanf ("%d%d%d", &n, &a, &b);
	rep(i, 1, b) t[i] = i - 1;
	rep(i, b + 1, a) t[i] = t[i - 1];
	rep(i, a + 1, n) t[i] = t[i - a];
	rep(i, 1, n) printf ("%c", (char) ('a' + t[i]));
	printf ("\n");
	
}
	

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) solve();
	
	
	return 0;
}