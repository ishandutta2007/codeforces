#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int N=100005,M=1000000007;
int n,i,a,b,n1,n2;
struct str{
	int a,b,t;
}s1[300005],s2[300005];
bool cmp1(str a,str b)
{
	return a.a>b.a;
}
bool cmp2(str a,str b)
{
	return a.a<b.a;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&a,&b);
		if(a<b)
			s1[++n1]=(str){a,b,i};
		else
			s2[++n2]=(str){a,b,i};
	}
	if(n1>n2)
	{
		sort(s1+1,s1+1+n1,cmp1);
		printf("%d\n",n1);
		for(i=1;i<=n1;i++)
			printf("%d ",s1[i].t);
	}
	else
	{
		sort(s2+1,s2+1+n2,cmp2);
		printf("%d\n",n2);
		for(i=1;i<=n2;i++)
			printf("%d ",s2[i].t);
	}
}