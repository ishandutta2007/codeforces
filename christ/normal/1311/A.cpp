
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+2, MOD = 1e9+7, BASE = 31, INF = 1e9, ED = 1e3+1;
#define all(x) (x).begin(),(x).end()
void solve () {
	int a,b;
	scanf ("%d %d",&a,&b);
	if (a == b) return (void) printf ("0\n");
	if (a > b) {
		printf ("%d\n",1+((a-b)&1));
	} else {
		printf ("%d\n",1+!((b-a)&1));
	}
}
int main() {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
    return 0;
}