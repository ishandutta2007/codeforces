#include<bits/stdc++.h>
using namespace std;
char s[100];
int n,m,ans;
int blocks=0;
int a[1010];
int alloc(int x)
{
	for(int i=1;i<=m;i++)
	{
		int j=i;
		int num=0;
		while(a[j]==0 && num !=x && j<=m)
		{
			num++;
			j++;
		}
		if(num!=x)
		{
			i=j;
		}
		else
		{
			blocks++;
			for(int k=i;k<j;k++)
			{
				a[k]=blocks;
			}
			return blocks;
		}

	}
	return 0;
}
int earse(int x)
{
	if(x<=0)
	{
		return -1;
	}
	int flag=0;
	for(int i=1;i<=m;i++)
	{
		while(a[i]==x)
		{
			a[i++]=0;
			flag=1;
		}
		
	}
	if(flag==1)
	{
		return -2;
	}
	return -1; // 
}
int defragment()
{
	for(int i=1;i<=m;i++)
	{
		if(a[i]==0)
		{
			for(int j=i+1;j<=m;j++)
			{
				if(a[j])
				{
					swap(a[i],a[j]);break;
				}
			}
		}
	}
	return -5;
}
int main()
{
	int x;
	cin>>n>>m;
	memset(a,0,sizeof(a));
	while(n--)
	{
		scanf("%s",&s);
		if(s[0]=='a')
		{
			cin>>x;
			ans=alloc(x);
		}
		else if(s[0]=='e')
		{
			cin>>x;
			ans=earse(x);
		}
		else if(s[0]=='d')
		{
			ans=defragment();
		}
		
		if(ans==0){
			printf("NULL\n");
		}
		else if(ans==-1)
		{
			printf("ILLEGAL_ERASE_ARGUMENT\n");
		}
		else if(ans>=1)
		{
			printf("%d\n",ans);
		}
	}
	return 0;
}