#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
 
using ll = long long;
using namespace std;

int n;
 
int ask(int l, int r) {
	if (l == r) return -1;
	printf("? %d %d\n", l, r);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}
 
int main() {
	scanf("%d", &n);
	int s = ask(1, n);
	if (ask(1, s) == s) {
		int l = 1, r = s - 1;
		while (l < r) {
			int m = (l + r + 1) / 2;
			if (ask(m, s) == s) l = m;
			else r = m - 1;
		}
		return !printf("! %d\n", l);
	}
	int l = s + 1, r = n;
		while (l < r) {
			int m = (l + r) / 2;
			if (ask(s, m) == s) r = m;
			else l = m + 1;
		}
	return !printf("! %d\n", l);
	
	return 0;
}