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
const int MN = 1e5 + 2, LOG = 17, INF = 1e8;
int a[MN];
void solve () {
	vector<int> cnt(31);
	int n;
	scanf ("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&a[i]);
		for (int j = 30; j >= 0; j--) if (a[i]>>j&1) ++cnt[j];
	}
	for (int j = 30; j >= 0; j--) if (cnt[j]&1) { //whoever gets this bit wins
		int zeros = n - cnt[j], ones = cnt[j];
		if ((zeros&1) || (ones % 4 == 1)) printf ("WIN\n");
		else printf ("LOSE\n");
		return;
	}
	printf ("DRAW\n");
}
int main () { 
	int _t = 1;
	scanf ("%d",&_t);
	while (_t--) solve();
    return 0;
}