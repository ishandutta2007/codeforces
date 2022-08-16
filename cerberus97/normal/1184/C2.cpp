#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[300005];
 
const int MX = 7000005 * 4;
int seg[MX], lazy[MX];
 
int query(int u, int a, int b, int i, int j){
	if(j<a || i>b) return -1e9;
	if(lazy[u]){
		seg[u] += lazy[u];
		if(a!=b) {
			lazy[u*2] += lazy[u]; lazy[u*2+1] += lazy[u];
		}
		lazy[u] = 0;
	}
	if(i<=a && b<=j)
		return seg[u];
	return max(query(u*2,a,(a+b)/2,i,j), query(u*2+1,(a+b)/2+1,b,i,j));
}
void update(int u, int a, int b, int i, int j, int val){
	if(lazy[u]){
		seg[u] += lazy[u];
		if(a!=b) {
			lazy[u*2] += lazy[u]; lazy[u*2+1] += lazy[u];
		}
		lazy[u] = 0;
	}
	if(j<a || i>b) return;
	if(i<=a && b<=j){
		seg[u] += val;
		if(a!=b) {
			lazy[u*2] += val; lazy[u*2+1] += val;
		}
		return;
	}
	update(u*2,a,(a+b)/2,i,j,val);
	update(u*2+1,(a+b)/2+1,b,i,j,val);
	seg[u] = max(seg[u*2], seg[u*2+1]);
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
 
	int n,r; cin >> n >> r;
	for(int i=1,x,y;i<=n;++i){
		cin>>x>>y;
		a[i] = {x-y,x+y};
	}
	sort(a+1,a+n+1);
	int min_y = 1e9;
	for(int i=1;i<=n;++i){
		min_y = min(min_y,a[i].second);
	}
	r *= 2;
	for(int i=1;i<=n;++i) a[i].second += abs(min_y) + r + 5;
 
 
	// for(int i=1,j=1;i<=n;++i) cout<<a[i].first<<' '<<a[i].second<<'\n';
 
	int ans = 0;
	for(int i=1,j=1;i<=n;++i){
		while(j<=n && a[j].first-a[i].first <= r){
			update(1,0,MX/4,a[j].second-r,a[j].second,1);
			++j;
		}
		// cout<<i<<' '<<j<<' '<<query(1,0,MX/4,0,MX/4)<<'\n';
		ans = max(ans,query(1,0,MX/4,0,MX/4));
		update(1,0,MX/4,a[i].second-r,a[i].second,-1);
	}
	cout<<ans;
}