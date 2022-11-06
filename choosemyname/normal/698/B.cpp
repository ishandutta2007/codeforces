#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int fa[200010],v[200010],x,k,num[200010],cx[200010];
void dfs(int i)
{
//	cout<<i<<endl;
	if(v[i]==0)
		v[i]=k;
//	cout<<i<<' '<<v[fa[i]]<<' '<<k<<endl;
	if(v[fa[i]]==k||v[i]==-x)
	{
	//	cout<<i<<'s'<<endl;
		if(v[i]==k)
			x++;
		num[x]++;
		if(v[fa[i]]!=-x&&fa[i]!=i)
		{
			v[i]=v[fa[i]]=-x;
			dfs(fa[i]);
		}
		else
			v[i]=-x;
		return;
	}
	if(v[fa[i]]==0)
		dfs(fa[i]);
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>fa[i];
	for(int i=1;i<=n;i++)
		if(v[i]==0)
		{
			k++;
			dfs(i);
		}
	int can=0;
	for(int i=1;i<=x;i++)
	{
	//	cout<<num[i]<<endl;
		if(num[i]==1)
		{
			for(int j=1;j<=n;j++)
				if(v[j]==-i)
				{
					can=j;
					break;
				}
			break;
		}
	}
//	cout<<can<<' '<<x<<endl;
	if(can)
		printf("%d\n",x-1);
	else
		printf("%d\n",x);
	if(can==0)
		for(int i=1;i<=n;i++)
			if(v[i]<0)
			{
				fa[i]=i;
				cx[-v[i]]=1;
				can=i;
				break;
			}
		for(int i=1;i<=n;i++)
			if(v[i]>0||cx[-v[i]])
				printf("%d ",fa[i]);
			else
			{
				printf("%d ",can);
				cx[-v[i]]=1;
			}
}