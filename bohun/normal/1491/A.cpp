#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
#define mp make_pair
 
using ll = long long;
using namespace std;	

int n, q, s, t[1 << 20];

int main() {
	scanf("%d%d", &n, &q);
	rep(i, 1, n) scanf("%d", t + i), s += t[i];
	while (q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a == 1) s -= t[b], s += (t[b] ^= 1);
		else puts(b <= s ? "1" : "0");
	}
	return 0;
}