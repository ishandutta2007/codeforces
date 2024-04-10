#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
using namespace std;
int able(int n,int k)
{
	if (n*n<k)return 0;
	if (n>k)return 1;
	k--;
	int tmp=(n*(n-1))/2;
	int t=k/2;
	int rest=max(0,t-tmp)*2+(k%2);
	if(rest>n-1)return 0;
	else return 1; 
}
int main()
{
	int n,k;
	int a[200][200];
	memset(a,0,sizeof(a));
	cin>>n>>k;
	int flag=1;
	int i=1;
	while (k>0)
	{
		if (able(n-i+1,k))
		{
			a[i][i]=1;
			k--;
		}	
		if (k>=2)
		for(int j=1;j<=n-i;j++)
			if (k>=2){ a[i][i+j]=a[i+j][i]=1; k-=2; }
		i++;
		if (i>n&&k!=0){ flag=0; break; }
	}
	if (k!=0)flag=0;
	if (!flag)printf("-1\n");
	else
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<n;j++)printf("%d ",a[i][j]);
		printf("%d\n",a[i][n]);
	}
	return 0;
}