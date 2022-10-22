#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5 + 5, MOD = 1e9 + 7;
char s[MN];
int main () {
	int n;
	scanf ("%d",&n);
	scanf ("%s",s+1);
	vector<int> pre(n+1);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i-1] + (s[i] == '(' ? 1 : -1);
		if (pre[i] < -1) return !printf ("No\n");
	}
	if (pre[n]) return !printf ("No\n");
	printf ("Yes\n");
	return 0;
}