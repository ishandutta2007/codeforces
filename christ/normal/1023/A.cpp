#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5 + 5, MOD = 1e9 + 7;
char s[MN], t[MN];
int main () {
	int n,m;
	scanf ("%d %d",&n,&m);
	scanf ("%s\n%s",s+1,t+1);
	int pre = 0, suf = 0; bool star = 0;
	for (int i = 1; i <= n; i++) if (s[i] == '*') star = 1;
	for (int i = 1; i <= min(n,m); i++) {
		if (s[i] == t[i]) pre = i;
		else break;
	}
	for (int i = 1; i <= min(n,m); i++) {
		if (s[n-i+1] == t[m-i+1]) suf = i;
		else break;
	}
	bool ok = 0;
	if (!star) ok = n == m && pre == n;
	else {
		for (int i = 1; i <= n; i++) if (s[i] == '*') {
			ok = pre >= i-1 && suf >= n-i && pre + suf <= m;
		}
	}
	printf (ok ? "YES\n" : "NO\n");
	return 0;
}