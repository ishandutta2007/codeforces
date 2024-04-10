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

char s[105], t[205];
int n;

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%s", s);
		int x[2];
		x[0] = x[1] = 0;
		n = strlen(s);
		rep(i, 0, n - 1)
			x[s[i] == '0']++;
		if (x[0] && x[1]) {
			rep(i, 0, 2 * n - 1) {
				if (i % 2 == 0) t[i] = '0';
				else t[i] = '1';
			}
		}
		else {
			rep(i, 0, 2 * n - 1)
				t[i] = s[0];
		}
		rep(i, 0, 2 * n - 1)
			printf ("%c", t[i]);
		printf ("\n");
				
	}
	
	return 0;
}