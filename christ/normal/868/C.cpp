#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
using ui = unsigned int;
using ull = unsigned long long;
using ui128 = __uint128_t;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e6 + 2, LOG = 17, INF = 1e8;
void solve () {
	int n,k; set<int> exists;
	scanf ("%d %d",&n,&k);
	for (int i = 1; i <= n; i++) {
		int a = 0;
		for (int j = 0; j < k; j++) {
			int b; scanf ("%d",&b);a |= b << j;
		}
		exists.insert(a);
		for (int k = 0; k < (1 << 4); k++) if (((a&k) == 0) && exists.count(k)) return (void) printf ("YES\n");
	}
	printf ("NO\n");
	
}
int main () { 
	int _t = 1;
	//scanf ("%d",&_t);
	for (int cs = 1; cs <= _t; cs++) solve();
    return 0;
}