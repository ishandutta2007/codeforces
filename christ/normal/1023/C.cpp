#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5 + 5, MOD = 1e9 + 7;
char s[MN];
int main () {
	int n,k;
	scanf ("%d %d",&n,&k);
	scanf ("%s",s+1);
	int pre = 0, len = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '(') {
			if (len + pre + 2 <= k) printf ("("), ++len, ++pre;
		} else if (s[i] == ')') {
			if (pre != 0) printf(")"), --pre, ++len;
		}
	}
	printf ("\n");
	return 0;
}