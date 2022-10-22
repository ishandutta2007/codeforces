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

int t, a, b, c, d;

bool ok(int a, int b, int c, int d) {
	if (a != c) return false;
	return a == b + d;
}

int main() {		
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d%d%d%d", &a, &b, &c, &d);
		if (ok(a, b, c, d) || ok(a, b, d, c) || ok(b, a, c, d) || ok(b, a, d, c)) printf ("YES\n");
		else printf ("NO\n");
		
	}
	
	return 0;
}