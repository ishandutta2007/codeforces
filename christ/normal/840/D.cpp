#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int MN = 3e5+5;
vector<int> pos[MN]; set<pii> yeet[MN];
int a[MN], freq[MN], ans[MN];
struct Q {
	int l,r,need,ind;
};
inline static int cnt (int v, int l, int r) {
	return upper_bound(all(pos[v]),r)-lower_bound(all(pos[v]),l);
}
void solve (int l, int r, vector<Q> &queries) {
	if (queries.empty()) return;
	int mid = (l+r)/2;
	yeet[mid-1].clear();
	for (int i = mid; i <= r; i++) {
		yeet[i] = yeet[i-1];
		++freq[a[i]];
		if (!yeet[i].count({freq[a[i]]-1,a[i]})) {
			if (yeet[i].size() < 5) yeet[i].insert({freq[a[i]],a[i]});
			else if (yeet[i].begin()->first < freq[a[i]]) {
				yeet[i].erase(yeet[i].begin());
				yeet[i].insert({freq[a[i]],a[i]});
			}
		} else {
			yeet[i].erase({freq[a[i]]-1,a[i]});
			yeet[i].insert({freq[a[i]],a[i]});
		}
	}
	for (int i = mid; i <= r; i++) --freq[a[i]];
	for (int i = mid-1; i >= l; i--) {
		if (i != mid-1) yeet[i] = yeet[i+1];
		++freq[a[i]];
		if (!yeet[i].count({freq[a[i]]-1,a[i]})) {
			if (yeet[i].size() < 5) yeet[i].insert({freq[a[i]],a[i]});
			else if (yeet[i].begin()->first < freq[a[i]]) {
				yeet[i].erase(yeet[i].begin());
				yeet[i].insert({freq[a[i]],a[i]});
			}
		} else {
			yeet[i].erase({freq[a[i]]-1,a[i]});
			yeet[i].insert({freq[a[i]],a[i]});
		}
	}
	for (int i = l; i < mid; i++) --freq[a[i]];
	vector<Q> lq,rq;
	for (Q &q : queries) {
		if (q.l > mid) rq.push_back(q);
		else if (q.r < mid-1) lq.push_back(q);
		else if (q.l == mid) {for (pii i : yeet[q.r]) if (cnt(i.second,q.l,q.r)>q.need) ans[q.ind]=min(ans[q.ind],i.second);}
		else if (q.r == mid-1) {for (pii i : yeet[q.l]) if (cnt(i.second,q.l,q.r)>q.need) ans[q.ind] = min(ans[q.ind],i.second);}
		else {
			for (pii i : yeet[q.r]) if (cnt(i.second,q.l,q.r)>q.need) ans[q.ind] = min(ans[q.ind],i.second);
			for (pii i : yeet[q.l]) if (cnt(i.second,q.l,q.r)>q.need) ans[q.ind] = min(ans[q.ind],i.second);
		}
	}
	solve(l,mid-2,lq);
	solve(mid+1,r,rq);
}
int main () {
	int n,qq;
	scanf ("%d %d",&n,&qq);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]), pos[a[i]].push_back(i);
	vector<Q> queries(qq);
	for (int i = 0; i < qq; i++) scanf ("%d %d %d",&queries[i].l,&queries[i].r,&queries[i].need),queries[i].need=(queries[i].r-queries[i].l+1)/queries[i].need, queries[i].ind = i;
	memset(ans,0x3f,sizeof ans);
	solve(1,n,queries);
	for (int i = 0; i < qq; i++) printf ("%d\n",ans[i]<1e9?ans[i]:-1);
	return 0;
}