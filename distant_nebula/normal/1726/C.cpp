#include <cstdio>
#include <numeric>
#include <algorithm>
#define INF 0x3f3f3f3f
const int N=400005;
int T, n, fa[N], stk[N], top;
char s[N];
inline int findfa(int x) { return fa[x]==x?x:fa[x]=findfa(fa[x]); }
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%s", &n, s+1);
		std::iota(fa, fa+2*n+1, 0);
		int cnt=0;
		top=0;
		for(int i=1; i<=2*n; ++i)
		{
			if(s[i]=='(') stk[++top]=i;
			else
			{
				fa[findfa(stk[top])]=findfa(i);
				if(stk[top]>1&&s[stk[top]-1]==')') fa[findfa(stk[top]-1)]=findfa(i);
				--top;
			}
		}
		for(int i=1; i<=2*n; ++i) cnt+=findfa(i)==i;
		printf("%d\n", cnt);
	}
	return 0;
}