#include <cstdio>
#include <algorithm>
#define N 100005
#define M 3000005
int n, a[N], l[M], r[M], f[M], dep[M], top=1;
inline void insert(int x)
{
	int idx=1;
	for(int i=29; ~i; --i)
	{
		if(x&(1<<i)) { if(!r[idx]) r[idx]=++top, dep[top]=i; idx=r[idx]; }
		else { if(!l[idx]) l[idx]=++top, dep[top]=i; idx=l[idx]; }
	}
}
void dfs(int u)
{
	if(!l[u]&&!r[u]) return;
	if(!l[u]) dfs(r[u]), f[u]=f[r[u]];
	else if(!r[u]) dfs(l[u]), f[u]=f[l[u]];
	else dfs(l[u]), dfs(r[u]), f[u]=(1<<(dep[u]-1))+std::min(f[l[u]], f[r[u]]);
}
int main()
{
	dep[1]=30;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), insert(a[i]);
	dfs(1);
	printf("%d\n", f[1]);
	return 0;
}