#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,t,pos[205],ans;
int main()
{
	cin>>t;
	while (t--)
	{
		cin>>n>>m;
		for (i=1;i<=m;i++)
		{
			scanf("%d",&pos[i]);
		}
		ans=0;
		j=1;
		pos[0]=-1<<25;
		pos[m+1]=1<<25;
		for (i=1;i<=n;i++)
		{
			while (i>pos[j]) j++;
			ans=max(ans,min(abs(i-pos[j-1]),abs(i-pos[j])));
		}
		cout<<ans+1<<endl;
	}
	return 0;
}