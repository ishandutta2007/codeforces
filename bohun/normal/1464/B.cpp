#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;

const int N = 1e5 + 50;

int n, x, y;
char s[N];
ll res = 1LL << 60;

void solve(int c, int x, ll cx, ll xc) {
	ll curr = 0, C = 0, X = 0;
	int tab[N][2]{};
	for (int i = 1; i <= n; ++i) {
		if (s[i] - '0' == c || s[i] == '?') {
			curr += xc * X;
			C++;
		}
		else {
			curr += cx * C;
			X++;
		}
	}
	res = min(res, curr);
	for (int i = 1; i <= n; ++i) {
		tab[i][0] = tab[i - 1][0];
		tab[i][1] = tab[i - 1][1];
		
		if (s[i] == '?') {
			int p = tab[i - 1][!c];
			int s = X - p;
			curr -= xc * p;
			curr -= cx * s;
			C--;
			
			p = tab[i - 1][c];
			s = C - p;
			curr += cx * p;
			curr += xc * s;
			X++;
			
			tab[i][x]++;
		}
		else {
			tab[i][s[i] - '0']++;
		}
		
		res = min(res, curr);
	}
}
		

int main() {
	scanf("%s%d%d", s + 1, &x, &y);
	n = strlen(s + 1);
	solve(0, 1, x, y);
	solve(1, 0, y, x);
	printf("%lld\n", res);
	return 0;
}