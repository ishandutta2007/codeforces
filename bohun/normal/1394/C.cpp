#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
#define cat(x) cerr << #x << " = " << x << endl
 
using namespace std;	

const int N = 5e5 + 100;

int n;
char s[N];
vector <pair<int, int>> q;

int LX, RX, LY, RY, BUP, BDOWN, xx, yy;

void umax(int &a, int b) {
	a = max(a, b);
}

void umin(int &a, int b) {
	a = min(a, b);
}

bool check(int x, int y) {
	if (x < 0 || y < 0) return false;
	if (x == 0 && y == 0) return false;
	if (x < LX || RX < x) return false;
	if (y < LY || RY < y) return false;
	if (!(x + BUP >= y) || !(x + BDOWN <= y)) return false;
	xx = x; yy = y;
	return true;
}

bool solve(int d) {
	LX = LY = 0;
	RX = RY = 1e9;
	BUP = 1e9;
	BDOWN = -1e9;
	
	for (auto it : q) {
		int x = it.fi, y = it.se;
		
		umin(RX, x + d);
		umax(LX, x - d);
		
		umin(RY, y + d);
		umax(LY, y - d);
		
		int z = x - d;
		int f = y - z;
		
		umin(BUP, f);
		
		z = x + d;
		f = y - z;
		
		umax(BDOWN, f);
	}
	
	rep(i, 0, 1) rep(j, 0, 1) if (check(i, j)) return true;
	
	if (check(LX, LY)) return true;
	if (check(LX, RY)) return true;
	if (check(RX, LY)) return true;
	if (check(RX, RY)) return true;
	
	if (check(LX, LX + BUP)) return true;
	if (check(LX, LX + BDOWN)) return true;
	
	if (check(RX, RX + BUP)) return true;
	if (check(RX, RX + BDOWN)) return true;
	
	if (check(LY - BUP, LY)) return true;
	if (check(LY - BDOWN, LY)) return true;
	
	if (check(RY - BUP, RY)) return true;
	if (check(RY - BDOWN, RY)) return true;
	
	return false;
}
	

int main() {
	scanf ("%d", &n);
	rep(i, 1, n) {
		scanf ("%s", s + 1);
		int m = strlen(s + 1), a = 0, b = 0;
		rep(j, 1, m) 
			(s[j] == 'B' ? a : b) += 1;
		q.pb({a, b});
	}
	
	int l = 0, r = 1e6;
	while (l < r) {
		int m = (l + r) / 2;
		if (solve(m)) r = m;
		else l = m + 1;
	}
	
	solve(l);
	
	printf ("%d\n", l);
	rep(i, 1, xx) printf ("B");
	rep(i, 1, yy) printf ("N");
	return 0;
}