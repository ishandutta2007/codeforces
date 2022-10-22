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

const int nax = 1e5 + 11;

int t;
char s[nax];
int n;

map <pair<pair<int,int>, pair<int,int>>, int> m;

pair<pair<int,int>, pair<int,int>> f(int a, int b, int c, int d) {
	auto m1 = mp(a, b);
	auto m2 = mp(c, d);
	if (m1 > m2) swap(m1, m2);
	return {m1, m2};
}

int main() {		
	scanf ("%d", &t);
	while (t--) {
		scanf ("%s",s);
		n = strlen(s);
		int x = 0, y = 0;
		int px = 0, py = 0;
		m.clear();
		int res = 0;
		rep(i, 0, n - 1) {
			if (s[i] == 'N') y++;
			if (s[i] == 'E') x++;
			if (s[i] == 'S') y--;
			if (s[i] == 'W') x--;
			if (m.find(f(px, py, x, y)) != m.end()) res++;
			else res += 5;
			m[f(px, py, x, y)] = 1;
			px = x;
			py = y;
		}
		printf ("%d\n", res);
	}
	
	return 0;
}