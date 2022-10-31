#include <cstdio>
#include <map>
#include <algorithm>
#define MAXN 200005
using std::map;
map<int, int> count;
int n, k, id[MAXN], t[MAXN], top;
int main()
{
	scanf("%d%d", &n, &k);
	for(int i=1, a; i<=n; ++i) scanf("%d", &a), id[i]=a;
	for(int i=1; i<=n; ++i) if(!count[id[i]]) t[++top]=id[i], count[id[i]]=1, top>k?count[t[top-k]]=0:0;
	printf("%d\n", std::min(top, k));
	for(int i=top; i>top-k&&i; --i) printf("%d ", t[i]);
	return 0;
}