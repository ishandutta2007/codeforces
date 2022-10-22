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
const int nax = 1e6 + 111;
int n, m, p;
int a[nax];
int b[nax];

int main() {
	scanf ("%d%d%d", &n, &m, &p);
	rep(i, 1, n) scanf ("%d", a + i);
	rep(i, 1, m) scanf ("%d", b + i);
	
	int w1 = n, w2 = m;
	while (a[w1] % p == 0) w1--;
	while (b[w2] % p == 0) w2--;
	
	printf ("%d\n", w1 + w2 - 2);
	
	
	return 0;
}