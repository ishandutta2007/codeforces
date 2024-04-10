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
int n,m,i,j,mem[255][1505],dif[255][1505],t,l,r,mid;
char c;
string st;
int main()
{
	cin>>n>>st>>m;
	memset(mem,0,sizeof(mem));
	for (i=1;i<=m;i++)
	{
		scanf(" %d %c",&t,&c);
		if (mem[c][t]) {cout<<mem[c][t]<<endl;continue;}
		if (!dif[c][1502])
		{
			dif[c][0]=(st[0]!=c);
			for (j=1;j<n;j++)
			{
				dif[c][j]=dif[c][j-1]+(st[j]!=c);
			}
			dif[c][1502]=1;
		}
		for (j=0;j<n;j++)
		{
			l=j+t-1;r=n;
			while (l<r)
			{
				mid=(l+r)/2;
				if (dif[c][mid]-(j?dif[c][j-1]:0)<=t)
				{
					mem[c][t]=min(n,max(mem[c][t],mid-j+1));
					l=mid+1;
				}
				else r=mid;
			}
		}
		cout<<mem[c][t]<<endl;
	}
	return 0;
}