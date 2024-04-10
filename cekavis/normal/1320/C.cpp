#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005, M = 1000005;
int n, m, p, f[M], s[M*4], lazy[M*4];
pair<int,int> a[N];
struct item{
	int x, y, z;
	bool operator<(const item &r)const{ return x<r.x;}
} c[N];
void build(int l, int r, int t){
	if(l==r) return (void)(s[t]=-f[l]);
	int mid=(l+r)>>1, k=t<<1;
	build(l, mid, k), build(mid+1, r, k|1);
	s[t]=max(s[k], s[k|1]);
}
void change(int l, int r, int t, int L, int x){
	if(L<=l) return (void)(s[t]+=x, lazy[t]+=x);
	int mid=(l+r)>>1, k=t<<1;
	if(L<=mid) change(l, mid, k, L, x);
	change(mid+1, r, k|1, L, x);
	s[t]=max(s[k], s[k|1])+lazy[t];
}
int main() {
	scanf("%d%d%d", &n, &m, &p);
	for(int i=1; i<=n; ++i) scanf("%d%d", &a[i].first, &a[i].second);
	sort(a+1, a+n+1);
	fill(f+1, f+1000001, 2e9);
	for(int i=1, x, y; i<=m; ++i) scanf("%d%d", &x, &y), f[x]=min(f[x], y);
	for(int i=999999; i; --i) f[i]=min(f[i], f[i+1]);
	for(int i=1; i<=p; ++i) scanf("%d%d%d", &c[i].x, &c[i].y, &c[i].z);
	sort(c+1, c+p+1);
	build(1, 1000000, 1);
	int ans=-2e9;
	for(int i=1, j=1; i<=n; ++i){
		while(j<=p && c[j].x<a[i].first){
			if(c[j].y<1000000) change(1, 1000000, 1, c[j].y+1, c[j].z);
			++j;
		}
		ans=max(ans, s[1]-a[i].second);
	}
	printf("%d\n", ans);
	return 0;
}