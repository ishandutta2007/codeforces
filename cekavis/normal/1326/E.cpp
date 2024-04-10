#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 300005;
int n, cnt, a[N], p[N], q[N], s[N<<2], lazy[N<<2];
set<int> f;
void change(int l, int r, int t, int L, int R, int x){
	if(L<=l && r<=R) return (void)(s[t]+=x, lazy[t]+=x);
	int mid=(l+r)>>1, k=t<<1;
	if(lazy[t]) lazy[k]+=lazy[t], lazy[k|1]+=lazy[t], s[k]+=lazy[t], s[k|1]+=lazy[t], lazy[t]=0;
	if(L<=mid) change(l, mid, k, L, R, x);
	if(R>mid) change(mid+1, r, k|1, L, R, x);
	s[t]=min(s[k], s[k|1]);
}
int query(int l, int r, int t, int x){
	if(l==r) return s[t];
	int mid=(l+r)>>1, k=t<<1;
	if(lazy[t]) lazy[k]+=lazy[t], lazy[k|1]+=lazy[t], s[k]+=lazy[t], s[k|1]+=lazy[t], lazy[t]=0;
	return x<=mid?query(l, mid, k, x):query(mid+1, r, k|1, x);
}
int query2(int l, int r, int t, int L){
	if(s[t]>=0) return n+1;
	if(l==r) return l;
	int mid=(l+r)>>1, k=t<<1;
	if(lazy[t]) lazy[k]+=lazy[t], lazy[k|1]+=lazy[t], s[k]+=lazy[t], s[k|1]+=lazy[t], lazy[t]=0;
	if(L>mid) return query2(mid+1, r, k|1, L);
	int ans=query2(l, mid, k, L);
	if(ans<=n) return ans;
	return query2(mid+1, r, k|1, L);
}
void add1(int x){
	auto it=f.lower_bound(x);
	if(it!=f.end()){
		if(x!=*it) change(1, n, 1, x, *it-1, 1);
		f.erase(it);
	}
	else ++cnt, change(1, n, 1, x, n, 1);
}
void add2(int x){
	if(query(1, n, 1, x)>0){
		--cnt, change(1, n, 1, x, n, -1);
		int y=query2(1, n, 1, x);
		if(y<=n) change(1, n, 1, y, n, 1), ++cnt, f.insert(y);
	}
	else f.insert(x);
}
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", p+i), a[p[i]]=i;
	for(int i=1; i<=n; ++i) scanf("%d", q+i);
	add1(a[n]);
	for(int i=1, ans=n; i<=n; ++i){
		printf("%d%c", ans, " \n"[i==n]);
		add2(q[i]);
		while(ans>1 && !cnt) add1(a[--ans]);
	}
	return 0;
}