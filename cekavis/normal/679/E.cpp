#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define push(t,x) (mn[t]-=x, (s[t]?s[t]:lazy[t])+=x)
#define pushdown if(s[t]) s[k]=s[k|1]=s[t], mn[k]=mn[k|1]=mn[t], lazy[k]=lazy[k|1]=0; if(lazy[t]) push(k, lazy[t]), push(k|1, lazy[t]), lazy[t]=0
#define update mn[t]=min(mn[k], mn[k|1]), s[t]=s[k]==s[k|1]?s[k]:0

const int N = 100005;
int n, q, cnt, a[N];
ll y, yy, z[20], s[N<<2], mn[N<<2], lazy[N<<2];
ll calc(ll x){ return x==y?yy:yy=*upper_bound(z, z+cnt, x)-x;}
void build(int l, int r, int t){
	if(l==r) return (void)(mn[t]=calc(s[t]=a[l]));
	int mid=(l+r)>>1, k=t<<1;
	build(l, mid, k), build(mid+1, r, k|1);
	update;
}
ll query(int l, int r, int t, int x){
	if(s[t]) return s[t];
	int mid=(l+r)>>1, k=t<<1;
	pushdown;
	return x<=mid?query(l, mid, k, x):query(mid+1, r, k|1, x);
}
void change(int l, int r, int t, int L, int R, ll x){
	if(L<=l && r<=R) return (void)(mn[t]=calc(s[t]=x), lazy[t]=0);
	int mid=(l+r)>>1, k=t<<1;
	pushdown;
	if(L<=mid) change(l, mid, k, L, R, x);
	if(R>mid) change(mid+1, r, k|1, L, R, x);
	update;
}
bool inc(int l, int r, int t, int L, int R, int x){
	if(L<=l && r<=R){
		if(s[t]) return mn[t]=calc(s[t]+=x), lazy[t]=0, s[t]*41==mn[t];
		if(x<mn[t]) return push(t, x), 0;
	}
	int mid=(l+r)>>1, k=t<<1;
	pushdown;
	bool o=0;
	if(L<=mid) o|=inc(l, mid, k, L, R, x);
	if(R>mid) o|=inc(mid+1, r, k|1, L, R, x);
	update;
	return o;
}
int main() {
	for(z[0]=cnt=1; z[cnt-1]<1e17; ++cnt) z[cnt]=z[cnt-1]*42;
	scanf("%d%d", &n, &q);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	build(1, n, 1);
	while(q--){
		int opt, l, r, x;
		scanf("%d%d", &opt, &l);
		if(opt==1) printf("%lld\n", query(1, n, 1, l));
		else{
			scanf("%d%d", &r, &x);
			if(opt==2) change(1, n, 1, l, r, x);
			else while(inc(1, n, 1, l, r, x));
		}
	}
	return 0;
}