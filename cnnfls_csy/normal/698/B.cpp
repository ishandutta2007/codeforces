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
int n,m,i,j,ans,fa[200005],x,y,num[200005],gen;
bool fi=1;
int find(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	fa[find(x)]=find(y);
}
set<int> used;
int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for (i=1;i<=n;i++) fa[i]=i;
	for (i=1;i<=n;i++)
	{
		cin>>num[i];
		if (!gen&&i==num[i])
		{
			gen=i;
		}	
	}
	for (i=1;i<=n;i++)
	{
		if (find(i)!=find(num[i])) merge(i,num[i]);
		else
		{
			if (!gen)
			{
				gen=i;
				used.insert(1e9+7);
			}
			num[i]=gen;
		}
		/*else 
		{
			num[i]=gen;
			merge(i,gen);
		}*/
	}
	for (i=1;i<=n;i++)
	{
		used.insert(find(i));
	}
	cout<<used.size()-1<<endl;
	for (i=1;i<=n;i++) cout<<num[i]<<' ';
	return 0;
}