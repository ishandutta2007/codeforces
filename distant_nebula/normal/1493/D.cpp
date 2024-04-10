#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#define B 505
#define N 200005
using std::map;
using std::multiset;
const int MOD=1000000007;
int n, q, a[N], ans=1;
multiset<int> st[N];
map<int, int> mp[N];
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }
inline void cp(int i, int x, int t)
{
	if(st[x].size()==n) ans=1ll*ans*qpow(x, 1ll*(MOD-2)*(*(st[x].begin()))%(MOD-1))%MOD;
	if(mp[i].count(x)) st[x].erase(st[x].find(mp[i][x]));
	(mp[i][x]+=t)%=MOD-1;
//	printf("fa %d %d %d %d\n", i, x, (*(st[x].begin())), st[x].size());
	st[x].insert(mp[i][x]);
	if(st[x].size()==n) ans=1ll*ans*qpow(x, *(st[x].begin()))%MOD;
//	printf("fa %d %d %d %d\n", i, x, (*(st[x].begin())), st[x].size());
//	puts("");
}
inline void change(int id, int x)
{
	for(int i=2; i*i<=x; ++i) if(x%i==0)
	{
		int t=0;
		while(x%i==0) x/=i, ++t;
		cp(id, i, t);
	}
	if(x) cp(id, x, 1);
}
int main()
{
	scanf("%d%d", &n, &q);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), change(i, a[i]);
	for(int i=1, x, y; i<=q; ++i) scanf("%d%d", &x, &y), change(x,  y), printf("%d\n", ans);
	return 0;
}