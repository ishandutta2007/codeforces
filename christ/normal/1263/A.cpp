#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 5e4+2, MOD = 1e9+7, LOG = 15;
#define all(x) (x).begin(),(x).end()
void solve () {
	vector<int> a(3);
	for (auto &au : a) scanf ("%d",&au);
	sort(all(a));
	int ret = a[0];
	int go = a[0];
	int ree = min(go,a[2]-a[1]);
	a[2] -= ree;
	go -= ree;
	a[1] -= go/2;
	a[2] -= (go+1)/2;
	ret += min(a[1],a[2]);
	printf ("%d\n",ret);
}
int main() {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
    return 0;
}