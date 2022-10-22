#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#pragma GCC diagnostic ignored "-Wunused-result" 
#pragma GCC diagnostic ignored "-Wsign-compare" 
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
#define setio(x)
#else
#define setio(x) freopen((x+".in").c_str(),"r",stdin); freopen((x+".out").c_str(),"w",stdout)
#endif
const int MN = 4e5+3, BASE = 31, LOG = 20, MOD = 1e9+7;
vector<int> xs;
void getx (int &x) {x = lower_bound(all(xs),x)-xs.begin()+1;}
pii a[MN];
pii swaps[MN];
int bit[MN];
map<int,int> rlyat;
void update (int i, int v) {
	for (;i<MN;i+=i&-i)
		bit[i] += v;
}
int query (int i) {
	int ret = 0;
	for (;i;i^=i&-i)
		ret += bit[i];
	return ret;
}
int main() {
	int n;
	scanf ("%d",&n);
	vector<int> arr;
	arr.push_back(0);
	for (int i = 1; i <= n; i++) {
		scanf ("%d %d",&swaps[i].first,&swaps[i].second);
		arr.push_back(swaps[i].first); arr.push_back(swaps[i].second);
	}
	sort(all(arr)); arr.erase(unique(all(arr)),arr.end());
	int ind = 0, sz = arr.size();
	for (int i = 1; i < sz; i++) {
		if ((arr[i]-arr[i-1])>1) a[++ind] = {arr[i]-1,arr[i]-1-arr[i-1]};
		a[++ind] = {arr[i],1};
		rlyat[arr[i]] = ind;
	}
	for (int i = 1; i <= ind; i++) xs.push_back(a[i].first);
	sort(all(xs));
	for (int i = 1; i <= n; i++) {
		swap(a[rlyat[swaps[i].first]],a[rlyat[swaps[i].second]]);
	}
	//for (int i = 1; i <= ind; i++) printf ("%d: %d %d\n",i,a[i].first,a[i].second);
	ll ans = 0;
	for (int i = ind; i >= 1; i--) {
		getx(a[i].first);
		ans += query(a[i].first) * 1LL * a[i].second;
		update(a[i].first,a[i].second);
	}
	printf ("%lld\n",ans);
	return 0;
}