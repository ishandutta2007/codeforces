#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ll long long

const int N = 100005;
int n, m, cnt, a[N];
ll ans[N];
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> s;
struct query{
	ll x;
	int t, id;
	inline bool operator<(const query &r)const{ return x<r.x;}
} q[N], f[N];
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1; i<=m; ++i){
		++cnt;
		scanf("%lld%d", &q[cnt].x, &q[cnt].t);
		if(q[cnt].x<a[1]) ans[i]=q[cnt].x, --cnt; else q[cnt].id=i;
	}
	sort(q+1, q+cnt+1);
	for(int i=0; i<n; ++i) s.insert(i);
	ll now=1e18, tim=0;
	int i=n, j=cnt;
	while(j){
		ll x=(now-a[i]-1)/i+1;
		while(j && q[j].x>=now-i*x)
			f[j].x=tim+(now-q[j].x-1)/i+1-q[j].t,
			f[j].t=*s.find_by_order(i-(now-q[j].x+i-1)%i-1),
			f[j].id=q[j].id, --j;
		tim+=x, now-=i*x;
		while(i && a[i]>=now) s.erase(s.find_by_order(a[i--]-now));
	}
	sort(f+1, f+cnt+1);
	s.clear();
	for(int i=0; i<n; ++i) s.insert(i);
	now=1e18, tim=0, i=n, j=1;
	while(j<=cnt){
		ll x=(now-a[i]-1)/i+1;
		while(j<=cnt && tim+x>=f[j].x)
			ans[f[j].id]=now+s.order_of_key(f[j].t)-(f[j].x-tim)*i, ++j;
		tim+=x, now-=i*x;
		while(i && a[i]>=now) s.erase(s.find_by_order(a[i--]-now));
	}
	for(int i=1; i<=m; ++i) printf("%lld\n", ans[i]);
	return 0;
}