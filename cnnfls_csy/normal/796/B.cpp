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
int n,m,k,i,j,x,a[1000005],y,z;
string st;
int main()
{
	x=1;
	cin>>n>>m>>k;
	for (i=1;i<=m;i++)
	{
		scanf("%d",&y);
		a[y]=1;
	}
	if (a[1]) {cout<<1;return 0;}
	for (i=1;i<=k;i++)
	{
		scanf("%d%d",&y,&z);
		if (x==y) x=z;
		else if (x==z) x=y;
		if (a[x]) {while (getline(cin,st));cout<<x;return 0;}
	}
	cout<<x;
	return 0;
}