#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long 
#define inf 1000000007
using namespace std;
int v[500];	
int p,x,y;
int judge(int s)
{
	int i=s;
	for(int j=1;j<=25;j++)
	{
		i=(i*96+42)%475;
		if (i+26==p)return 1;
	}
	return 0;
}
int main()
{
	cin>>p>>x>>y;
	int prex=x;
	for(int i=0;i<=474;i++)v[i]=judge(i);
	int flag=0;
	while (x>=y)
	{
		if (v[(x/50)%475]){flag=1; break;}
		x-=50;
	}
	while (x<y)x+=50;
	int ans=0;
	x=prex;
	if (!flag)
	while (1==1)
	{
		ans++;
		if (v[((x+50)/50)%475]){flag=1; break;}
		if (v[((x+100)/50)%475]){flag=1; break;}
		x+=100;
	}
	cout<<ans<<endl;
	return 0;
}