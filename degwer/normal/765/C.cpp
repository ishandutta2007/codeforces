#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int k,a,b;
	scanf("%d%d%d",&k,&a,&b);
	int x=a/k,y=b/k;
	if(a-x*k<=y*(k-1)&&b-y*k<=x*(k-1))printf("%d\n",x+y);
	else printf("-1\n");
}