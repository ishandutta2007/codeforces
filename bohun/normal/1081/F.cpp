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
 
int par;
int n, t, s[400], dif;
 
void ask(int l, int r) {
	par = (par + 1) % 2;
	printf ("? %d %d\n", l, r);
	fflush(stdout);
	int x;
	scanf ("%d", &x);
	dif = x - t;
}
 
int main() {
	scanf ("%d%d", &n, &t);
	
	if (n == 1) {
		printf ("! %d\n", t);
		fflush(stdout);
		return 0;
	}
	
	per(i, 1, n) {
		if (n % 2 == 0) {
			while (par % 2 == 0 || abs(dif) % 2 != i % 2)
				ask(i, i);
			s[i] = (i - dif) / 2;
			while (par % 2 == 1 || abs(dif) % 2)
				ask(i, i);
		}
		else {
			if (i > 1) {
				while (par % 2 == 0 || abs(dif) % 2 != i % 2)
					ask(i - 1, i);
				s[i] = (i - dif) / 2;
				while (par % 2 == 1 || abs(dif) % 2)
					ask(i - 1, i);
			}
			if (i == 1) {
				while (par % 2 == 0 || abs(dif) % 2 == 1)
					ask(2, n);
				s[1] = s[n] - (n - 1 - dif) / 2;
				while (par % 2 == 1 || abs(dif) % 2 == 1)
					ask(2, n);
			}
		}
	}
	printf ("! ");
	rep(i, 1, n) printf ("%d", s[i] - s[i - 1]);
	fflush(stdout);
				
			
			
		
	
	return 0;
}