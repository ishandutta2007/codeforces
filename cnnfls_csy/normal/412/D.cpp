// "   ios::sync_with_stdio(0);   " !!!!!!
#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<set>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,x,y,ans[100005];
set<int> bi[100005];
int main()
{
	 ios::sync_with_stdio(0);
	 cin>>n>>m;
	 for (i=1;i<=m;i++)
	 {
	 	cin>>x>>y;
	 	bi[x].insert(y);
	 }
	 for (i=1;i<=n;i++) ans[i]=i;
	 for (i=1;i<=n;i++)
	 {
	 	j=i;
	 	while (j-1&&bi[ans[j-1]].count(ans[j]))
	 	{
	 		swap(ans[j],ans[j-1]);
	 		j--;
	 	}
	 }
	 for (i=1;i<=n;i++) cout<<ans[i]<<' ';
	 return 0;
}