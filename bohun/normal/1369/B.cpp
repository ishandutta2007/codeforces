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

char s[100005];

int main() {				
	int T, n;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%s", &n, s + 1);
		int one = n + 1, zer = -1;
		rep(i, 1, n) {
			if (s[i] == '0') zer = i;
			if (s[i] == '1' && one == n + 1) one = i;
		}
		if (!(one < zer)) {
			rep(i, 1, n) printf ("%c", s[i]);
			printf ("\n");
		}
		else {
			rep(i, 1, one - 1)
				printf ("%c", s[i]);
			rep(i, zer, n)
				printf ("%c", s[i]);
			printf ("\n");
		}
	}
	return 0;
}