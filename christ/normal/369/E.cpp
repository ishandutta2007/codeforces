#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#pragma GCC diagnostic ignored "-Wunused-result" 
#pragma GCC diagnostic ignored "-Wsign-compare" 
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
#define setio(x)
#else
#define setio(x) freopen((x+".in").c_str(),"r",stdin); freopen((x+".out").c_str(),"w",stdout)
#endif
#define lc ind<<1
#define rc ind<<1|1
const int MN = 3e5+3, MM = 1e6+3, BASE = 31, LOG = 20, MOD = 1e9+7;
struct Q {
	int l,r,ind;
};
int ans[MN];
int bit[MM];
void inc (int i) {
	for(;i<MM;i+=i&-i)
		++bit[i];
}
int query (int i) {
	int ret = 0;
	for(;i;i^=i&-i)
		ret += bit[i];
	return ret;
}
pii segs[MN];
int main() {
	int n,m;
	scanf ("%d %d",&n,&m);
	for (int i = 1; i <= n; i++) scanf ("%d %d",&segs[i].first,&segs[i].second);
	vector<Q> s1,s2;
	for (int i = 1; i <= m; i++) {
		int c,a; scanf ("%d",&c); int last = -1, first = -1;
		while (c--) {
			scanf ("%d",&a); 
			if (first == -1) first = a;
			if (last != -1&&a-last>1) s2.push_back({last+1,a-1,i});
			last = a;
		}
		s1.push_back({first,last,i});
	}
	sort(segs+1,segs+1+n);
	sort(all(s1),[&](Q &a, Q &b) {return a.r < b.r;});
	int sind = 1;
	for (Q &q : s1) {
		while (sind <= n && segs[sind].first <= q.r) {
			inc(segs[sind].second);
			++sind;
		}
		ans[q.ind] = query(MM-1)-query(q.l-1);
	}
	sort(all(s2),[&](Q &a, Q &b){return a.l > b.l;});
	sind = n;
	memset(bit,0,sizeof bit);
	for (Q &q : s2) {
		while (sind && segs[sind].first >= q.l) {
			inc(segs[sind].second);
			--sind;
		}
		ans[q.ind] -= query(q.r);
	}
	for (int i = 1; i <= m; i++) printf ("%d\n",ans[i]);
	return 0;
}