#include <bits/stdc++.h>
#define ll long long
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

int a;
int b[200005];
int x, y;

int main() {
	int T, n;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		int good = 0;
		x = -1, y = -1;
		rep(i, 1, n) {
			scanf ("%d", &a);
			b[i] = (a == i);
			good += b[i];
			if (!b[i]) {
				if (x == -1) x = i;
				y = i;
			}
		}
		if (good == n) {
			printf ("0\n");
			continue;
		}
		if (good == 0) {
			printf ("1\n");
			continue;
		}
		bool q = false;
		rep(i, 1, n) 
			if (b[i] && x < i && i < y) q = true;
		if (!q) printf ("1\n");
		else printf ("2\n");
	}
	
	return 0;
}