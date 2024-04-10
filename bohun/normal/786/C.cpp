#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; n >= i; ++i)

using namespace std;
using namespace __gnu_pbds;

const int nax = 200005, ile = 5000000, pod = (1 << 17), inf = 1e9;
int n, t[nax];
int root[ile], l[ile], r[ile], sum[ile];
int fre = 1;


void build(int node = 0, int le = 0, int pr = pod - 1) {
	if(le == n + 1 && pr == n + 1)
		sum[node] = inf;
	if(le == pr)
		return;
	l[node] = fre++;
	r[node] = fre++;
	int mid = (le + pr) / 2;
	build(l[node], le, mid);
	build(r[node], mid + 1, pr);
	sum[node] = sum[l[node]] + sum[r[node]];
}

int upd(int x, int y, int id, int val, int le = 0, int pr = pod - 1) {
	int ja = fre++;
	if(pr <= y && x <= le){
		sum[ja] = sum[id] + val;
		return ja;
	}
	int mid = (le + pr) / 2;
	l[ja] = l[id];
	r[ja] = r[id];
	if(x <= mid)
		l[ja] = upd(x, y, l[ja], val, le, mid);
	if(mid < y)
		r[ja] = upd(x, y, r[ja], val, mid + 1, pr);
	sum[ja] = sum[l[ja]] + sum[r[ja]];
	return ja;
}

int daj(int id, int k, int le = 0, int pr = pod - 1) {
	if(le == pr)
		return le;
	int mid = (le + pr) / 2;
	int v1 = sum[l[id]];
	if(v1 >= k)
		return daj(l[id], k, le, mid);
	else
		return daj(r[id], k - v1, mid + 1, pr);
}

int ans[nax];
int last[nax];

	
	
		
		
int fun(int K) {
	int pos = 1, ans = 0;
	while(pos <= n){
		++ans;
		pos = daj(root[pos], K + 1);
	}
	return ans;
}


int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> t[i];
	}
	build();
	
	for(int i = 1; i <= n; ++i)
		last[i] = n + 1;
	root[n + 1] = 0;
	for(int i = n; 1 <= i; --i){
		root[i] = upd(last[t[i]], last[t[i]], root[i + 1], -1);
		root[i] = upd(i, i, root[i], 1);
		last[t[i]] = i;
	}
	for(int i = 1; i <= n; ++i) {
		ans[i] = fun(i);
	}
	
	for(int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
	
	
	
	
	
	
		
	
    return 0;
}