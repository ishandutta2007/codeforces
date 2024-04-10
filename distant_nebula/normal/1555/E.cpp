#include <cstdio>
#include <algorithm>
const int N=1000005;
int n, m, l[N], r[N], w[N], id[N], ans=0x3f3f3f3f;
namespace SGT{
	#define lid (id<<1)
	#define rid (id<<1|1)
	int tag[N<<2], mn[N<<2];
	inline void addp(int id, int v)
	{
		tag[id]+=v, mn[id]+=v;
	}
	inline void upt(int id)
	{
		mn[id]=std::min(mn[lid], mn[rid]);
	}
	inline void pushdown(int id)
	{
		addp(lid, tag[id]);
		addp(rid, tag[id]);
		tag[id]=0;
	}
	void add(int id, int l, int r, int l1, int r1, int v)
	{
		if(l1>r1) return;
		if(l1<=l&&r<=r1) { addp(id, v); return; }
		pushdown(id);
		int mid=(l+r)>>1;
		if(l1<=mid) add(lid, l, mid, l1, r1, v);
		if(r1>mid) add(rid, mid+1, r, l1, r1, v);
		upt(id);
	}
}
using namespace SGT;
bool cmp(int a, int b) { return w[a]<w[b]; }
int main()
{
	scanf("%d%d", &n, &m);
	--m;
	for(int i=1; i<=n; ++i) scanf("%d%d%d", l+i, r+i, w+i), --r[i], id[i]=i;
	std::sort(id+1, id+n+1, cmp);
	for(int x=1, y=0; x<=n; ++x)
	{
		if(x>1) add(1, 1, m, l[id[x-1]], r[id[x-1]], -1);
		while(y<n&&!mn[1]) add(1, 1, m, l[id[y+1]], r[id[y+1]], 1), ++y;
		if(!mn[1]) break;
		ans=std::min(ans, w[id[y]]-w[id[x]]);
	}
	printf("%d\n", ans);
	return 0;
}