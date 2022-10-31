#include <cstdio>
#include <iostream>
using namespace std;
int n,m,ans,full,a[1<<22],v[1<<22],p[1<<22];
void dfs(int x)
{
	if (v[x])return; v[x]=1;
	if (p[x])dfs(full-x);
	for(int i=0;i<n;i++)
		if (x & (1<<i))dfs(x^(1<<i));
}
int main()
{
	cin>>n>>m; full=(1<<n)-1;
	for(int i=1;i<=m;i++){ scanf("%d",&a[i]); p[a[i]]=1; }
	for(int i=1;i<=m;i++)
		if (!v[a[i]])ans++,dfs(full-a[i]);
	cout<<ans<<endl;
}