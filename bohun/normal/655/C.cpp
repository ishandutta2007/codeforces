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

using namespace std;

void setIO(string name) {
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

const int N = 1e5 + 100;

int n, k;
char s[N];
int p[N];

int sum(int l, int r) {
	l = max(l, 1);
	r = min(r, n);
	if (l > r) return 0;
	return p[r] - p[l - 1];
}
		
bool ok(int x) {
	rep(i, 1, n) {
		if (s[i] == '0' && sum(i - x, i - 1) + sum(i + 1, i + x) >= k) return true;
	}
	return false;
}

int main() {
	scanf ("%d%d", &n, &k);
	scanf ("%s", s + 1);
	rep(i, 1, n) {
		p[i] = p[i - 1] + (s[i] == '0');
	}
	int l = 1;
	int r = n;
	while (l < r) {
		int m = (l + r) / 2;
		if (ok(m)) r = m;
		else l = m + 1;
	}
	printf ("%d\n", l);
	
	
	return 0;
}