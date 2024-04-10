#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5+3, MOD = 1e9+7;
int a[MN]; vector<pii> order;
void solve (vector<int> inds) {
	if (inds.empty()) return;
	int mx = 0;
	for (int i : inds) mx = max(mx,a[i]);
	vector<int> go;
	for (int i : inds) {
		if (a[i] != mx) go.push_back(i);
	}
	solve(go);
	for (int j = 0; j < (int)inds.size(); j++) {
		if (a[inds[j]] == mx) {
			for (int k = (int)inds.size() - 1; k > j; k--) if (a[inds[k]] != mx) {
				//printf ("%d %d\n",inds[j],inds[k]);
				order.emplace_back(inds[j],inds[k]);
			}
		}
	}
}
int main () {
	int n;
	scanf ("%d",&n);
	vector<int> og(n+1);
	for (int i = 1; i <= n; i++) scanf ("%d",a+i), og[i] = a[i];
	vector<int> inds(n); iota(all(inds),1);
	solve(inds);
	int inv = 0;
	for (int j = 1; j < n; j++) for (int k = j+1; k <= n; k++) if (og[j] > og[k]) ++inv;
	printf ("%d\n",(int)order.size());
	//assert(is_sorted(a+1,a+1+n));
	assert((int)order.size() == inv);
	for (pii &p : order) swap(og[p.first],og[p.second]);
	assert(is_sorted(1+all(og)));
	//printf ("%d\n",(int)order.size());
	for (pii p : order) printf ("%d %d\n",p.first,p.second);
	return 0;
}
// by induction, we can prove it always works for a permutation
// take the maximum element, recur on both halves, swap inversions from right to left
// w-w-w-what if theyre the same ...
// looks like you can consider them from left to right if they are the same