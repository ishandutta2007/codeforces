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

const int nax = 5e5 + 111;

int n, a, b, t;
char s[nax];

int cost;
LL pref[nax];

LL sum(int l, int r) {
	return pref[r] - pref[l - 1];
}

int main() {	
	scanf ("%d%d%d%d", &n, &a, &b, &t);
	scanf ("%s", s + 1);
	rep(i, 1, n) {
		cost = (s[i] == 'h' ? 1 : b + 1);
		pref[i] = cost + pref[i - 1];
	}
	
	int res = 0;
	rep(i, 1, n) {
		int l = i + 1;
		int r = n + 1;
		
		if (sum(1, i) + (LL) (i - 1) * a > t) continue;
		
		while (l < r) {
			int m = (l + r) / 2;
			LL c = sum(1, i) + sum(m, n);
			if (i - 1 < n - m + 1)
				c += (LL) (2 * (i - 1) + n - m + 1) * a;
			else
				c += (LL) (i - 1 + 2 * (n - m + 1)) * a;
				
			if (c <= t) r = m;
			else l = m + 1;
		}
		
		res = max(res, i + n - l + 1);
	}
	printf ("%d\n", res);
		
	
	return 0;
}