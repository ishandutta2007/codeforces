#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int N=100005,M=1000000007;
int n,i,ans,k,mx,pos[100005];
char c[100005],p[100005];
int main(){
	scanf("%s",c);
	n=strlen(c);
	for(i=0;i<n;i++)
		if(c[i]!='a')
		{
			pos[k]=i;
			p[k++]=c[i];
		}
		else
			mx=k;
	if(k==0)
	{
		printf("%s",c);
		return 0;
	}
	if(k%2==1)
	{
		printf(":(");
		return 0;
	}
	for(i=k/2;i<k;i++)
		if(p[i]!=p[i-k/2])
		{
			printf(":(");
			return 0;
		}
	if(mx>k/2)
	{
		printf(":(");
		return 0;
	}
	for(i=0;i<pos[k/2];i++)
		printf("%c",c[i]);
}