#include <bits/stdc++.h>
#define LL long long
#define LD long double
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

int k;
int a[4][4];
int x = (1 << 17);

int main() {
	scanf ("%d", &k);
	rep(i, 1, 3)
		rep(j, 1, 3) 
			if (i != j || (i == j && i == 1))
				a[i][j] += x;
	a[1][1] += k;
	a[1][2] += k;
	a[2][2] += k;
	a[2][3] += k;
	a[3][3] += k;
	printf ("3 3\n");
	rep(i, 1, 3) {
		rep(j, 1, 3)
			printf ("%d ", a[i][j]);
		printf ("\n");
	}
    return 0;
}