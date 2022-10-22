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

const int nax = 2e5 + 100;

int T;
char s[15][15];

void f(int a, int b) {
	if (s[a][b] == '1') s[a][b] = '2';
	else s[a][b] = '1';
}

void solve() {
	int n = 9;
	rep(i, 1, n) {
		scanf ("%s", s[i] + 1);
	}
	f(1, 1);
	f(4, 2);
	f(7, 3);
	f(2, 5);
	f(5, 4);
	f(8, 6);
	f(3, 7);
	f(6, 8);
	f(9, 9);
	rep(i, 1, n) {
		rep(j, 1, n) printf ("%c", s[i][j]);
		printf ("\n");
	}
	
}	
	

int main() {
	scanf ("%d", &T);
	while (T--) solve();
	
	
	return 0;
}