#include <cstdio>
#include <vector>
#include <set>
#define mp std::make_pair
#define MAXN 100005
using std::set;
using std::pair;
int n, m, col[MAXN], a[4], d[MAXN];
set<pair<int, int> > st;
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1, a, b; i<=m; ++i) scanf("%d%d", &a, &b), st.insert(mp(a, b)), st.insert(mp(b, a)), ++d[a], ++d[b];
	for(int i=1; i<=n; ++i)
	{
		if(!col[i])
		{
			col[i]=1;
			++a[1];
			for(int j=1; j<=n; ++j) if(j!=i&&(st.find(mp(i, j))==st.end())) col[j]=1, ++a[1];
			break;
		}
	}
	for(int i=1; i<=n; ++i)
	{
		if(!col[i])
		{
			col[i]=2;
			++a[2];
			for(int j=1; j<=n; ++j) if(j!=i&&(st.find(mp(i, j))==st.end())) col[j]=2, ++a[2];
			break;
		}
	}
	for(int i=1; i<=n; ++i)
	{
		if(!col[i])
		{
			col[i]=3;
			++a[3];
			for(int j=1; j<=n; ++j) if(j!=i&&(st.find(mp(i, j))==st.end())) col[j]=3, ++a[3];
			break;
		}
	}
	for(auto it=st.begin(); it!=st.end(); ++it) if(col[(*it).first]==col[(*it).second]) return puts("-1"), 0;
	if(a[1]+a[2]+a[3]<n) return puts("-1"), 0;
	for(int i=1; i<=n; ++i) if(d[i]!=(n-a[col[i]])) return puts("-1"), 0;
	if(!a[1]||!a[2]||!a[3]) return puts("-1"), 0;
	for(int i=1; i<=n; ++i) printf("%d ", col[i]);
	return 0;
}