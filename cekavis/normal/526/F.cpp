#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 300005;
ll ans;
int n, sf, sg, f[N], g[N], a[N], lazy[N<<2];
pair<int,int> s[N<<2];
void change(int l, int r, int t, int L, int R, int x){
	if(L<=l && r<=R) return (void)(lazy[t]+=x, s[t].first+=x);
	int mid=(l+r)>>1, k=t<<1;
	if(L<=mid) change(l, mid, k, L, R, x);
	if(R>mid) change(mid+1, r, k|1, L, R, x);
	s[t]=(s[k].first==s[k|1].first?make_pair(s[k].first, s[k].second+s[k|1].second):min(s[k], s[k|1]));
	s[t].first+=lazy[t];
}
int main() {
	scanf("%d", &n), fill(s, s+N*4, make_pair(0, 1));
	for(int i=1, x, y; i<=n; ++i)
		scanf("%d%d", &x, &y), a[x]=y, change(1, n, 1, i, i, i);
	for(int i=1; i<=n; ++i){
		while(sf && a[f[sf]]<a[i])
			change(1, n, 1, f[sf-1]+1, f[sf], a[i]-a[f[sf]]), --sf;
		while(sg && a[g[sg]]>a[i])
			change(1, n, 1, g[sg-1]+1, g[sg], a[g[sg]]-a[i]), --sg;
		f[++sf]=g[++sg]=i, ans+=s[1].second;
	}
	printf("%lld\n", ans);
	return 0;
}