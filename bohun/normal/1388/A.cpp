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

int main() {
	int T, n;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		if (n < 31) printf ("NO\n");
		else {
			printf ("YES\n");
			int x = n - 30;
			if (x != 6 && x != 10 && x != 14)
				printf ("6 10 14 %d\n", n - 30);
			else
				printf ("6 10 15 %d\n", n - 31);
		}
	}
	return 0;
}