#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define vi vector <int>

using namespace std;

int n;
int all;

int group(int x, int y) {
	printf ("%d %d\n", x, y);
	fflush(stdout);
	char s[10];
	scanf ("%s", s);
	return (s[0] == 'b');
}

int main() {	
	scanf ("%d", &n);
	int N = n;
	n -= 1;
	
	int p = group(0, 1);
	all = p;
	
	if (n == 0) {
		printf ("2 10 2 5");
		return 0;
	}
	
	int l = 1;
	int r = 1000000000;
	
	while (n > 0) {
		assert(l <= r);
		n--;
		int m = (l + r) / 2;
		int g = group(m, 1);
		all += g;
		if (g == p) l = m + 1;
		else r = m - 1;
	}
	
	l--;
	r++;
	if (all == N || all == 0) {
		printf ("5 5 10 5");
		return 0;
	} 
	assert(l < r);
	printf ("%d %d %d %d\n", l, 2, r, 0);
	
	
	
	return 0;
}