#include <cstdio>
#include <numeric>
#include <vector>
#include <set>
#include <algorithm>
#define INF 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define ll long long
#define x first
#define y second
using std::vector;
using std::pair;
using std::set;
const int N=400005;
int n, t, g[N], c[N];
int d[N];
ll s;
set<pair<pair<int, int>, ll> > st;
ll ask(int l, int r)
{
	// printf("ask %d %d\n", l, r);
	ll ans=INF;
	while(1)
	{
		auto it=st.lower_bound({{l, 0}, 0});
		pair<pair<int, int>, ll> t;
		if(it!=st.begin()&&prev(it)->x.y>l)
		{
			--it;
			ans=it->y;
			t=*it;
			st.erase(it);
			st.insert({{t.x.x, l}, t.y});
		}
		else
		{
			if(it==st.end()||it->x.x>=r) break;
			t=*it;
			st.erase(it);
		}
		ll v=t.y+t.x.x-std::min(r, t.x.y);
		ans=std::min(ans, v+1);
		if(t.x.y>r)
		{
			st.insert({{r, t.x.y}, v});
			break;
		}
	}
	// printf("ans %lld\n", ans);
	return ans;
}
int main()
{
	scanf("%d%d", &n, &t);
	for(int i=1; i<=n; ++i) scanf("%d%d", g+i, c+i), c[i]=(g[i]+t-c[i])%t, g[i]=t-g[i];
	for(int i=1; i<n; ++i) scanf("%d", d+i);
	st.insert({{0, t}, 0});
	for(int i=1; i<=n; ++i)
	{
		// printf("c %d %d\n", c[i], g[i]);
		++g[i];
		ll rc=((c[i]-s)%t+t)%t;
		// printf("rc %d %d\n", rc, g[i]);
		c[i]=rc;
		ll ret=INF;
		if(c[i]+g[i]<=t) ret=ask(c[i], c[i]+g[i])+c[i]+g[i];
		else ret=std::min(ask(c[i], t)+c[i]+g[i], ask(0, c[i]+g[i]-t)+c[i]+g[i]-t);
		int ct=(rc+g[i]-1)%t;
		if(ret<INF) st.insert({{ct, ct+1}, ret-1-ct});
		s+=d[i];
		// printf("in %d %lld\n", i, s);
		// for(auto t:st) printf("%d %d %lld\n", t.x.x, t.x.y, t.y+t.x.x);
		// puts("");
	}
	ll ans=INF;
	for(auto t:st) ans=std::min(ans, t.y+t.x.x);
	printf("%lld\n", ans+s);
	return 0;
}