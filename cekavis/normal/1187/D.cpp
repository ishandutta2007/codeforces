#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 300005;
int T, n, a[N], b[N], s[N<<2];
vector<int> f[N];
void build(int l, int r, int t){
	if(l==r) return (void)(s[t]=a[l]);
	int mid=(l+r)>>1, k=t<<1;
	build(l, mid, k), build(mid+1, r, k|1);
	s[t]=min(s[k], s[k|1]);
}
int query(int l, int r, int t, int x){
	if(r<=x) return s[t];
	int mid=(l+r)>>1, k=t<<1;
	if(x<=mid) return query(l, mid, k, x);
	return min(query(l, mid, k, x), query(mid+1, r, k|1, x));
}
void modify(int l, int r, int t, int x){
	if(l==r) return (void)(s[t]=n);
	int mid=(l+r)>>1, k=t<<1;
	if(x<=mid) modify(l, mid, k, x); else modify(mid+1, r, k|1, x);
	s[t]=min(s[k], s[k|1]);
}
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) f[i].clear();
		for(int i=1; i<=n; ++i) scanf("%d", a+i), f[a[i]].push_back(i);
		for(int i=1; i<=n; ++i) scanf("%d", b+i);
		build(1, n, 1);
		for(int i=1; i<=n; ++i) reverse(f[i].begin(), f[i].end());
		for(int i=1; i<=n; ++i){
			if(f[b[i]].empty()){ puts("NO"); goto nxt;}
			int x=f[b[i]].back();
			f[b[i]].pop_back();
			if(query(1, n, 1, x)<b[i]){ puts("NO"); goto nxt;}
			modify(1, n, 1, x);
		}
		puts("YES");
		nxt:;
	}
	return 0;
}