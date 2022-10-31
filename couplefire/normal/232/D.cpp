#include <bits/stdc++.h>
#define F first
#define S second
#define pii pair<int, int>
#define pb push_back
#define rank RANK
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const ll N = 2e5 + 10, LOG = 20, INF = 1e12;
 
ll a[N], s[N], rank[LOG][N];
int lg[N], suf[N], rmq[LOG][N], rg[N], f[N];
pair<pair<ll, ll>, int> tmp[N];
int seg[LOG][4 * N];
 
int lcp(int i, int j){
	int len = 0;
	for(int k=LOG-1; k>=0; k--){
		if(rank[k][i] == rank[k][j]){
			i += (1 << k);
			j += (1 << k);
			len += (1 << k);
		}
	}
	return len;
}
 
void suffix_array(int n){
	for(int i=0; i<n; i++)
		rank[0][i] = s[i] + INF;
 
	for(int j=1; j<LOG; j++){
		for(int i=0; i<n; i++){
			if(i + (1 << (j - 1)) < n)
				tmp[i] = {{rank[j - 1][i], rank[j - 1][i + (1 << (j - 1))]}, i};
			else tmp[i] = {{rank[j - 1][i], -1}, i};
		}
		sort(tmp, tmp + n);
		for(int i=0; i<n; i++){
			int id = tmp[i].S;
			if(i == 0)
				rank[j][id] = 1;
			else if(tmp[i].F == tmp[i - 1].F)
				rank[j][id] = rank[j][tmp[i - 1].S];
			else rank[j][id] = rank[j][tmp[i - 1].S] + 1;
		}
	}
 
	for(int i=0; i<n; i++){
		suf[i] = tmp[i].S;
		f[tmp[i].S] = i;
	}
 
	for(int i=0; i<n-1; i++)
		rmq[0][i] = lcp(suf[i], suf[i + 1]);
 
	for(int j=1; j<LOG; j++)
		for(int i=0; i<n-1; i++)
			if(i + (1 << j) <= n-1)
				rmq[j][i] = min(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
		
	return ;
}
 
int get(int l, int r){
	int len = r - l;
	return min(rmq[lg[len]][l], rmq[lg[len]][r - (1 << lg[len])]);
}
 
int solve(int tb, int L, int R, int xl, int xr, int s, int e){
	if(xl > xr)return 0;
	if(L<=s && e<=R){
		int up = upper_bound(seg[tb] + s, seg[tb] + e, xr) - (seg[tb] + s);
		int down = lower_bound(seg[tb] + s, seg[tb] + e, xl) - (seg[tb] + s);
		return up - down;
	}
	if(L>=e || s>=R)return 0;
	int mid = (s + e)/2;
	return solve(tb + 1, L, R, xl, xr, s, mid) + solve(tb + 1, L, R, xl, xr, mid, e);
}
 
void build(int tb, int s, int e){
	if(e - s < 2){
		seg[tb][s] = suf[s];
		return ;
	}
	int mid = (s + e)/2;
	build(tb + 1, s, mid);
	build(tb + 1, mid, e);
	merge(seg[tb + 1] + s, seg[tb + 1] + mid, seg[tb + 1] + mid, seg[tb + 1] + e, seg[tb] + s);
}
 
int find(int l, int r, int n){
	int lo, hi;
	lo = -1, hi = f[l];
	while(hi - lo > 1){
		int mid = (lo + hi)/2;
		if(get(mid, f[l]) >= r-l)
			hi = mid;
		else lo = mid;
	}
	int left = hi;
 
	lo = f[l], hi = n;
	while(hi - lo > 1){
		int mid = (lo + hi)/2;
		if(get(f[l], mid) >= r-l)
			lo = mid;
		else hi = mid;
	}
	int right = hi;
 
	int nn = (n + 1)/2;
	l -= nn; r -= nn;
 
	return solve(0, left, right, 0, l-(r-l)-1, 0, n) + solve(0, left, right, r+1, nn-2, 0, n);
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i=0; i<n; i++)
		cin >> a[i];
 
	for(int i=0; i<n-1; i++)
		s[i] = a[i + 1] - a[i];
	s[n - 1] = INF;
	for(int i=n; i<2*n-1; i++)
		s[i] = a[i - n] - a[i - n + 1];
 
	for(int i=2; i<N; i++)
		lg[i] = lg[i/2] + 1;
 
	suffix_array(2 * n - 1);
/*
	for(int i=0; i<2*n-1; i++)
		cout << s[i] << ' '; cout << endl;
 
	for(int i=0; i<2*n-1; i++)
		cout << suf[i] << ' '; cout << endl;
 
	for(int i=0; i<2*n-1; i++)
		cout << rank[LOG - 1][suf[i]] << ' '; cout << endl << endl;
*/
 
	for(int i=n-1; i>=0; i--){
		if(i == n - 1)rg[i] = n;
		else if(a[i] == a[i + 1])rg[i] = rg[i + 1];
		else rg[i] = i + 1;
	}
 
	build(0, 0, 2*n-1);
 
	int q; cin >> q;
	while(q--){
		int l, r; cin >> l >> r; --l;
		if(r - l == 1){
			cout << n - 1 << '\n';
		}else{
			r--;
			int res = find(l+n, r+n, 2*n - 1);
			cout << res << '\n';
		}
	}
	
}