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

const int N = 1 << 11;

int n;
int ans[N+1];

int ask(int p, int q) {
	printf ("? %d %d\n", p, q);
	fflush(stdout);
	int x;
	scanf ("%d", &x);
	return x;
}

int value(int x) {
	int ans = N - 1;
	rep(i, 1, 15) {
		int a = rand() % n + 1;
		if (a == x) continue;
		ans &= ask(x, a);
	}
	return ans;
}		

int main() {
	srand(2137);
	scanf ("%d", &n);
	vector <int> v;
	rep(i, 1, n) v.pb(i);
	random_shuffle(all(v));
	pair<int, int> zero = {v[0], value(v[0])};
	rep(i, 1, n - 1) {
		int a = ask(zero.fi, v[i]);
		if ((a & zero.se) == a)
			zero = {v[i], value(v[i])};
	}
	rep(i, 1, n)
		if (i != zero.fi)
			ans[i] = ask(i, zero.fi);
	printf ("! ");
	rep(i, 1, n)
		printf ("%d ", ans[i]);
		
	return 0;
}