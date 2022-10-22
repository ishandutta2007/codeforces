#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using pii = pair<int,int>;
const int MN = 4e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
ll a[MN];
ll psa[MN];
ll suf[MN];
int main() {
	int n,m,k;
	scanf ("%d %d %d",&n,&m,&k);
	for (int i = 1; i <= n; i++) scanf ("%lld",a+i), psa[i] = psa[i-1] + a[i];
	for (int i = n; i >= 1; i--) {
		auto it = upper_bound(psa+1,psa+1+n,k+psa[i-1]);
		--it;
		int ed = it-psa;
		suf[i] = suf[ed+1] + 1;
	}
	for (int st = 1; st <= n; st++) {
		auto it = upper_bound(psa+1,psa+1+n,k+psa[st-1]);
		--it;
		int ed = it-psa;
		if (suf[ed+1] + 1 <= m) return !printf ("%d\n",n-st+1);
	}
	assert(0);
    return 0;
}
//psa[j] - psa[i-1] <= k
//psa[j] <= k + psa[i-1]