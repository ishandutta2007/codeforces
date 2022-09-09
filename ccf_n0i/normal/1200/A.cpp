#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,m,i,j,v[10];
char c;
int main()
{
	scanf("%d\n",&n);
	rep(i,n)
	{
		scanf("%c",&c);
		if(c=='L')
		{
			for(j=0;;j++)
			{
				if(!v[j])
				{
					v[j]=1;
					break;
				}
			}
		}
		else if(c=='R')
		{
			for(j=9;;j--)
			{
				if(!v[j])
				{
					v[j]=1;
					break;
				}
			}
		}
		else
		{
			v[c-'0']=0;
		}
	}
	for(i=0;i<=9;i++)
	{
		printf("%d",v[i]);
	}
	return 0;
}