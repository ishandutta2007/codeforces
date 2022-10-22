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

int n, k;

//vector <int> W = {0, 5, 5, 5, 1, 2};


int ask(vector <int> a, vector <int> b) {
	while (ss(a) > ss(b)) a.pop_back();
	printf ("? %d %d\n", ss(a), ss(b));
	for (auto it : a) 
		printf ("%d ", it);
	printf ("\n");
	for (auto it : b)
		printf ("%d ", it);
	printf ("\n");
	fflush(stdout);
	char s[10];
	scanf ("%s", s);
	if (s[0] == 'F') return 1;
	if (s[0] == 'S') return 2;
	if (s[0] == 'E') return 3;
	
	/*int A = 0, B = 0;
	for (auto it : a) A += W[it];
	for (auto it : b) B += W[it];
	if (A < B) return 2;
	if (A > B) return 1;
	return 3;*/
	assert(false);
}
	

void solve() {
	scanf ("%d%d", &n, &k);
	int stone = 1;
	int K = 25;
	while (K--) {
		int x = rand() % n + 1;
		if (x == stone) continue;
		if (ask({x}, {stone}) == 1) stone = x;
	}
	
	vector <int> ord;
	rep(i, 1, n)
		if (i != stone)
			ord.pb(i);
			
	vector <int> L = {stone}, R;
	for (int p = 1, i = 0; i < n;) {
		R.clear();
		rep(j, i, i + p - 1)
			if (j < ss(ord))
				R.pb(ord[j]);
		i += p;
		assert(ss(L) >= ss(R));
		if (ask(L, R) == 1) break;
		for (auto it : R) L.pb(it);
		p *= 2;
	}
	
	int l = 0, r = ss(R) - 1;
	while (l < r) {
		int m = (l + r) / 2;
		vector <int> Z;
		rep(j, 0, m) Z.pb(R[j]);
		if (ask(L, Z) == 3) l = m + 1;
		else r = m;
	}
			
	printf ("! %d\n", R[l]);
	fflush(stdout);
}

int main() {
	srand(2137);
	int T;
	scanf ("%d", &T);
	while (T--) solve();
			
	return 0;
}