#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int ans[7][3]=
{
	{0,1,2},
	{1,0,2},
	{1,2,0},
	{2,1,0},
	{2,0,1},
	{0,2,1}	
};
int n,x;
int main()
{
	scanf("%d%d",&n,&x);
	n%=6;
	printf("%d\n",ans[n][x]);
}