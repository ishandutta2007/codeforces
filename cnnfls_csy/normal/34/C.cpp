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
int n,page[100005],i,j,x;
char ch;
bool fi=1;
int main()
{
	for (;scanf("%d%c",&x,&ch)==2&&ch==',';) page[x]=1;
	page[x]=1;
	for (i=1;i<=100000;i++)
	{
		if (page[i])
		{
			if (fi) fi=0; else cout<<',';
			cout<<i;
			if (page[i+1])
			{
				for (j=i+1;j<=100000;j++)
				{
					if (!page[j]) break;
				}
				cout<<'-'<<j-1;
				i=j;
			}
		}
	}
	return 0;
}