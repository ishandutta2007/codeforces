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

int n, k;

int query(int a, int b, int c) {
	printf ("? %d %d %d\n", a, c, b);
	fflush(stdout);
	char s[10];
	scanf ("%s", s);
	return s[0] == 'Y';
}

int myrand() {
	int x = (LL) rand() * rand() % n + 1;
	return x;
}

vector <int> z;

int main() {
	srand(1337);
	scanf ("%d%d", &n, &k);
	int h = 0;
	int s = 1;
	int p = 1;
	while (s < n) {
		p *= k;
		s += p;
		h++;
	}
	int x, y;
	while (true) {
		x = myrand();
		y = myrand();
		while (x == y) y = myrand();
		z.clear();
		rep(i, 1, n)
			if (i != x && i != y)
				if (query(x, y, i) == true)
					z.pb(i);
		if (2 + ss(z) == 2 * h + 1) break;
	}
	for (auto root : z) {
		int f = 0;
		for (auto it : z)
			if (it != root && query(root, x, it))
				f++;
		if (f == h - 1) return printf ("! %d\n", root), 0;
	}
	assert(false);
			
		
	
    return 0;
}