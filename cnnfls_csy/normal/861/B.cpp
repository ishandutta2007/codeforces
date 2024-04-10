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
int n,m,i,j,num[205],x,y;
set<int> ans;
int main()
{
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>x>>y;
		num[x]=y;
	}
	for (i=1;i<=100;i++)
	{
		bool ok=1;
		for (j=1;j<=100;j++)
		{
			if (!num[j]) continue;
			if ((j+i-1)/i!=num[j])
			{
				ok=0;
				break;
			}
		}
		if (ok) ans.insert((n+i-1)/i);
	}
	if (ans.size()==1)
	{
		cout<<*ans.begin();
	}
	else cout<<-1;
	return 0;
}