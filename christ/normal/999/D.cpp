#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 4e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int freq[MN], a[MN], fin[MN];
int main() {
	int n,m;
	scanf ("%d %d",&n,&m);
	set<int> rem;
	for (int i = 0; i < m; i++) freq[i] = n/m, rem.insert(i);
	ll ret = 0;
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&a[i]);
		auto it = rem.lower_bound(a[i]%m);
		if (it == rem.end()) it = rem.begin();
		int j = *it;
		if (!(--freq[j])) rem.erase(j);
		fin[i] = a[i]+(j-(a[i]%m)+m)%m;
		ret += (j-(a[i]%m)+m)%m;
	}
	printf ("%lld\n",ret);
	for (int i = 1; i <= n; i++) printf ("%d ",fin[i]);
	printf ("\n");
    return 0;
}