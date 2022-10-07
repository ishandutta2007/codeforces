#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
int n,k,i,s1[1000005],s0[1000005],l0[1000005],r0[1000005],l1[1000005],r1[1000005];
char c[1000005];
int main()
{
	scanf("%d %d",&n,&k);
	scanf("%s",c+1);
	for(i=1;i<=n;i++)
	{
		s0[i]=s0[i-1];
		s1[i]=s1[i-1];
		if(c[i]=='0')
		{
			s0[i]++;
			l0[i]=i;
			l1[i]=l1[i-1];
		}
		else
		{
			s1[i]++;
			l1[i]=i;
			l0[i]=l0[i-1];
		}
	}
	for(i=n;i>=1;i--)
		if(c[i]=='0')
		{
			r1[i]=r1[i+1];
			r0[i]=i;
		}
		else
		{
			r0[i]=r0[i+1];
			r1[i]=i;
		}
	for(i=k;i<=n;i++)
	{
		if(s0[i]-s0[i-k]==s0[n])
		{
			printf("tokitsukaze");
			return 0;
		}
		if(s1[i]-s1[i-k]==s1[n])
		{
			printf("tokitsukaze");
			return 0;
		}
	}
	for(i=k;i<=n;i++)
	{
		if((r1[i+1]!=0&&l1[i-k]!=0)||(r0[i+1]!=0&&l0[i-k]!=0))
			break;
		if(r0[i+1]==0&&l0[i-k]-r0[1]+1>k)
			break;
		if(l0[i-k]==0&&l0[n]-r0[i+1]+1>k)
			break;
		if(r1[i+1]==0&&l1[i-k]-r1[1]+1>k)
			break;
		if(l1[i-k]==0&&l1[n]-r1[i+1]+1>k)
			break;
	}
	if(i>n)
		printf("quailty");
	else
		printf("once again");
}