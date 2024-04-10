#include <cstdio>
#include <map>
#include <algorithm>
#define x first
#define y second
#define mp std::make_pair
#define N 200005
using std::pair;
using std::map;
int n, m, cnt, cc;
char op[10], c[4];
map<pair<int, int>, int> e;
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1, x, y, z; i<=m; ++i)
	{
		scanf("%s%d", op, &x);
		if(op[0]=='+')
		{
			scanf("%d%s", &y, c);
			z=c[0]-'a'+1;
			e[mp(x, y)]=z;
			if(e[mp(y, x)]==z) ++cnt;
			if(e[mp(y, x)]) ++cc;
		}
		if(op[0]=='-')
		{
			scanf("%d", &y);
			z=e[mp(x, y)];
			e[mp(x, y)]=0;
			if(e[mp(y, x)]==z) --cnt;
			if(e[mp(y, x)]) --cc;
		}
		if(op[0]=='?')
		{
			if(x&1) puts(cc?"YES":"NO");
			else puts(cnt?"YES":"NO");
		}
	}
	return 0;
}