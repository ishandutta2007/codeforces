#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+2, BASE = 31; const ll MOD = 1000000000000037LL;
#define all(x) (x).begin(),(x).end()
char s[MN];
int main() {
	int n;
	scanf ("%d\n%s",&n,s+1); int ret = 0, sz = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'x') {
			++sz;
		} else {
			ret += max(0,sz-2);
			sz = 0;
		}
	}
	ret += max(0,sz-2);
	printf ("%d\n",ret);
    return 0;
}